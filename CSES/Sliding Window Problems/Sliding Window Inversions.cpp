#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define fr first
#define se second
#define pb push_back
using namespace std;

struct st
{
    ll val=0;
    st *l=nullptr, *r=nullptr;
};

st *raiz=new st();
ll pot=1;
ll calc(st *&nod, ll a, ll b, ll l=1, ll r=pot)
{
    if(nod==nullptr||r<a||b<l)
        return 0;
    if(l>=a&&r<=b)
        return nod->val;
    ll mid=(l+r)/2;
    return calc(nod->l,a,b,l,mid)+calc(nod->r,a,b,mid+1,r);
}

void add(st *&nod)
{
    ll val=0;
    if(nod->l!=nullptr)
        val+=(nod->l)->val;
    if(nod->r!=nullptr)
        val+=(nod->r)->val;
    nod->val=val;
}

void update(st *&nod, ll a, ll x, ll l=1, ll r=pot)
{
    if(l==r)
    {
        nod->val+=x;
        return;
    }
    ll mid=(l+r)/2;
    if(a<=mid)
    {
        if(nod->l==nullptr)
            nod->l=new st();
        update(nod->l,a,x,l,mid);
    }
    else
    {
        if(nod->r==nullptr)
            nod->r=new st();
        update(nod->r,a,x,mid+1,r);
    }
    add(nod);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, i, tot=0, aum;
    cin >> n >> k;
    while(pot<int(1e9+1))
        pot*=2;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=0; i<k; i++)
    {
        aum=calc(raiz,v[i]+1,pot);
        tot+=aum;
        update(raiz,v[i],1);
    }
    cout << tot << ' ';
    for(i=k; i<n; i++)
    {
        aum=calc(raiz,1,v[i-k]-1);
        tot-=aum;
        update(raiz,v[i-k],-1);
        aum=calc(raiz,v[i]+1,pot);
        tot+=aum;
        update(raiz,v[i],1);
        cout << tot << ' ';
    }
    return 0;
}
