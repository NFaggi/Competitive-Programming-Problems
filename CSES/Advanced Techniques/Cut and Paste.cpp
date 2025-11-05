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
    ll val, sz=1, pr;
    nodo *l=nullptr, *r=nullptr;
};

string s;

nodo *Treap;
void crear(nodo *&nod, ll k)
{
    nod= new nodo();
    nod->val=k;
    nod->pr=rng();
}

ll getsz(nodo *nod)
{
    if(nod==nullptr)
        return 0ll;
    return nod->sz;
}

void upd(nodo *&nod)
{
    if(nod==nullptr)
        return;
    nod->sz=getsz(nod->l)+getsz(nod->r)+1;
}

void split(nodo *T, ll sz, nodo*&L, nodo *&R)
{
    if(T==nullptr)
    {
        L=R=nullptr;
        return;
    }
    else if(getsz(T->l)+1 < sz)
    {
        split(T->r, sz-getsz(T->l)-1, T->r,R);
        L=T;
        upd(L);
    }
    else
    {
        split(T->l, sz, L, T->l);
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
    else if(L->pr>R->pr)
    {
        merge(L->r,L->r,R);
        T=L;
    }
    else
    {
        merge(R->l,L,R->l);
        T=R;
    }
    upd(T);
}

void inser(nodo *&T, nodo *&nod)
{
    if(T==nullptr)
        T=nod;
    else if(T->pr > nod->pr)
    {
        inser(T->r,nod);
        upd(T);
    }
    else
        merge(T,T,nod);
}

void ins(ll k)
{
    nodo *nod;
    crear(nod,k);
    inser(Treap,nod);
}


void inorder(nodo *T)
{
    if(T==nullptr)
        return;
    inorder(T->l);
    cout << s[T->val];
    inorder(T->r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, a, b;
    cin >> n >> q >> s;

    for(i=0; i<n; i++)
        ins(i);

    for(i=0; i<q; i++)
    {
        cin >> a >> b;

        nodo *L=nullptr, *mid=nullptr, *R=nullptr;

        split(Treap,a,L,mid);

        split(mid,b-a+2,mid,R);

        merge(Treap,L,R);

        merge(Treap,Treap,mid);
        
    }
    inorder(Treap);
    return 0;
}
