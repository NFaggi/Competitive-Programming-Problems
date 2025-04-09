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
vector<ll>st,lazy,I,D;
ll pot=1;

void prop(ll nod)
{
    lazy[nod*2]+=lazy[nod];
    lazy[nod*2+1]+=lazy[nod];
    st[nod]+=lazy[nod];
    lazy[nod]=0;
}

void up(ll l, ll r, ll x, ll nod)
{
    if(I[nod]>r||D[nod]<l)
        return;
    if(I[nod]>=l&&D[nod]<=r)
    {
        lazy[nod]+=x;
        return;
    }    
    prop(nod);
    up(l,r,x,nod*2);
    up(l,r,x,nod*2+1);
    st[nod]=max(st[nod*2]+lazy[nod*2],st[nod*2+1]+lazy[nod*2+1]);
}

void update(ll l, ll r, ll x)
{
    up(l+pot,r+pot,x,1);
}

ll calc(ll l, ll r, ll nod)
{
    if(I[nod]>r||D[nod]<l)
        return -LLONG_MAX;
    if(I[nod]>=l&&D[nod]<=r)
        return st[nod]+lazy[nod];
    prop(nod);
    return max(calc(l,r,nod*2),calc(l,r,nod*2+1));        
}

ll ma(ll l, ll r)
{
    return calc(l+pot,r+pot,1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, l, r, a;
    cin >> n >> m;
    vector<ll>aum(n+2,0);
    vector<vector<pair<ll,ll>>>borr(n+2);
    for(i=0; i<m; i++)
    {
        cin >> l >> r >> a;
        aum[l]+=a;
        borr[r+1].pb({a,l-1});
    }
    while(pot<(n+2))
        pot*=2;
    st.resize(pot*2,0);
    lazy.resize(pot*2,0);
    I.resize(pot*2,0);
    D.resize(pot*2,0);
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }        
    for(i=1; i<=n+1; i++)
    {
        update(0,i-1,aum[i]);
        for(auto k:borr[i])
            update(0,k.se,-k.fr);
        update(i,i,ma(0,i-1));    
    }
    cout << max(ma(0,n),0ll);
    return 0;
}
