#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct nodo
{
    ll val, sz=1, pr, lazy=0, sum=0;
    nodo *l=nullptr, *r=nullptr;
};

nodo *Treap;

const int MAXN=2e5+1;

ll v[MAXN];

void crear(nodo *&x, ll k)
{
    x=new nodo();
    x->val=k;
    x->pr=rng();
    x->sum=v[k];
}

ll getsz(nodo *&x)
{
    if(x==nullptr)
        return 0ll;
    return x->sz;
}

ll getsum(nodo *&x)
{
    if(x==nullptr)
        return 0;
    return x->sum;
}

void upd(nodo *&x)
{
    x->sz=getsz(x->l)+getsz(x->r)+1;
    x->sum=getsum(x->l)+getsum(x->r)+v[x->val];
}

void act(nodo *&x, ll k)
{
    if(x==nullptr)
        return;
    swap(x->l,x->r);
    x->lazy=(x->lazy+k)%2;
}
void prop(nodo *&x)
{
    if(x==nullptr||x->lazy==0)
        return;
    act(x->l,x->lazy);
    act(x->r,x->lazy);
    x->lazy=0;
}

void split(nodo *T, ll k, nodo *&L, nodo *&R)
{
    prop(T);
    if(T==nullptr)
    {
        L=R=nullptr;
        return;
    }
    else if(getsz(T->l)+1<k)
    {
        split(T->r,k-getsz(T->l)-1,T->r,R);
        L=T;
        upd(L);
    }
    else
    {
        split(T->l,k,L,T->l);
        R=T;
        upd(R);
    }
}

void merge(nodo *&T, nodo *&L, nodo *&R)
{
    if(L==nullptr||R==nullptr)
    {
        T=((L==nullptr)?R:L);
        return;
    }
    else if(L->pr > R->pr)
    {
        prop(L);
        merge(L->r,L->r,R);
        T=L;
    }
    else
    {
        prop(R);
        merge(R->l,L,R->l);
        T=R;
    }
    upd(T);
}

void inser(nodo *&T, nodo *&x)
{
    if(T==nullptr)
        T=x;
    else if(T->pr > x->pr)
    {
        inser(T->r,x);
        upd(T);
    }
    else
        merge(T,T,x);
}

void ins(ll k)
{
    nodo *x;
    crear(x,k);
    inser(Treap,x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, a, b, t;
    cin >> n >> q;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        ins(i);
    }
    while(q--)
    {
        cin >> t >> a >> b;
        nodo *l=nullptr, *mid=nullptr, *r=nullptr;
        split(Treap,a,l,mid),
        split(mid,b-a+2,mid,r);
        if(t==1)
        {
            swap(mid->l,mid->r);
            mid->lazy=(mid->lazy+1)%2;
        }
        else
            cout << mid->sum << '\n';        

        merge(Treap,l,mid);
        merge(Treap,Treap,r);
    }
    return 0;
}
