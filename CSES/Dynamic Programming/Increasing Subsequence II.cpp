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


const int MOD=1e9+7;
struct st
{
    ll sum=0;
    st *l=nullptr, *r=nullptr;
};

st *raiz=new st();
ll pot=1;
ll calc(st *&nod, ll a, ll b, ll l=1, ll r=pot)
{
    if(nod==nullptr)
        return 0;
    if(r<a||l>b)
        return 0;
    if(a<=l&&r<=b)
        return nod->sum;
    ll mid=(l+r)/2;
    return (calc(nod->l,a,b,l,mid)+calc(nod->r,a,b,mid+1,r))%MOD;
}

void add(st *&nod)
{
    nod->sum=0;
    if(nod->l!=nullptr)
        nod->sum=(nod->sum+(nod->l)->sum)%MOD;
    if(nod->r!=nullptr)
        nod->sum=(nod->sum+(nod->r)->sum)%MOD;
}

void update(st *&nod, ll a, ll x, ll l=1, ll r=pot)
{
    if(l==r)
    {
        nod->sum=(nod->sum+x)%MOD;
        return;
    }
    ll mid=(l+r)/2;
    if(a<=mid)
    {
        if(nod->l==nullptr)
            nod->l=new st();
        update(nod->l,a,x,l,mid);
        add(nod);
    }
    else
    {
        if(nod->r==nullptr)
            nod->r=new st();
        update(nod->r,a,x,mid+1,r);
        add(nod);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, act;
    while(pot<int(1e9+1))
        pot*=2;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    
    for(i=0; i<n; i++)
    {
        act=calc(raiz,1,v[i]-1)+1;
        update(raiz,v[i],act);
    }
    cout << raiz->sum;
    return 0;
}
