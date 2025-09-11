#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define fr first
#define se second
#define pb push_back
using namespace std;
mt19937 rng;
struct nodo
{
    ll val, pri, hijos=1, cant=1;
    nodo *l=nullptr, *r=nullptr;
};
#define Treap nodo*
Treap raiz=nullptr;
void update(Treap T)
{
    if (!T) return;
    T->hijos = T->cant;
    if (T->l) T->hijos += T->l->hijos;
    if (T->r) T->hijos += T->r->hijos;
}
void split(Treap T, ll k, Treap &l, Treap &r)
{
    if(T==nullptr) l=r=nullptr;
    else if(k<T->val)
    {
        split(T->l, k, l, T -> l);
        r=T;
    }
    else
    {
        split(T->r, k, T->r, r);
        l=T;
    }
    update(T);
}

void insert(Treap &T, Treap x)
{
    if(!T) T=x;
    else if(x->pri>T->pri)
    {
        split(T,x->val,x->l,x->r);
        T=x;
    }
    else
    {
        if(x->val < T->val)
            insert(T->l,x);
        else
            insert(T->r,x);
    }
    update(T);
}
bool find(Treap &T, ll k)
{
    if(!T) return 0;
    if(T->val>k)
        return find(T->l,k);
    else if(T->val<k)
        return find(T->r,k);
    return 1;
}

void aum(Treap &T, ll k)
{
    if(!T) return;
    if(T->val>k)
        aum(T->l,k);
    else if(T->val<k)
        aum(T->r,k);
    else
    {
        T->cant++;
        T->hijos++;
    }
    update(T);
}

void insert_value(ll x)
{
    if(find(raiz,x))
    {
        aum(raiz,x);
        return;
    }
    Treap nod=new nodo();
    nod->val=x;
    nod->pri=int(rng());
    insert(raiz,nod);
}
void merge(Treap &T, Treap l, Treap r)
{
    if(!l) T=r;
    else if(!r) T=l;
    else if(l->pri>r->pri)
    {
        merge(l->r, l->r, r);
        T=l;
    }
    else
    {
        merge(r->l,l,r->l);
        T=r;
    }
    update(T);
}

void erase (Treap &T, ll k)
{
    if(!T) return;
    else if(T->val==k)
    {
        if((T->cant)==1)
            merge(T, T->l, T->r);
        else
            T->cant--;
    }
    else
    {
        if(k<T->val) erase(T->l, k);
        else erase(T->r,k);
    }
    update(T);
}

ll calc(Treap &T, ll k)
{
    if(!T)
        return 0;
    if(T->val<k)
    {
        ll act=T->hijos;
        if(T->r)
            act=act-(T->r)->hijos;
        return act+calc(T->r, k);
    }
    else if(T->val>k)
    {
        return calc(T->l, k);
    }
    ll act=0;
    if(T->l)
        act=(T->l)->hijos;
    return act+calc(T->r, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, i, x, q, k, ans;
    char c;
    cin >> n >> q;
    vector<ll>v(n);
    for(i=0; i<n; i++)
    {
        cin >> x;
        v[i]=x;
        insert_value(x);
    }
    while(q--)
    {
        cin >> c;
        if(c=='!')
        {
            cin >> k >> x;
            k--;
            erase(raiz,v[k]);
            insert_value(x);
            v[k]=x;
        }
        else
        {
            cin >> k >> x;
            ans=calc(raiz,x+1)-calc(raiz,k);
            cout << ans << '\n';
        }
    }
}
