//Link: https://www.spoj.com/problems/ACQUIRE/
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
 
vector<pair<ll,ll>>objs;
vector<ll>dp;
vector<pair<ll,ll>>q;
 
__int128 L, R;
 
ll cons(ll x, ll i)
{
    if(i>0)
    {
        L=1;
        R=1;
        L=L*(q[i].se-q[i-1].se);
        R=R*x*(q[i-1].fr-q[i].fr);
    }
    if(i>0&&L>R)
        return -1;
    
    if(i+1<sz(q))
    {
        L=1;
        R=1;
        L=L*(q[i+1].se-q[i].se);
        R=R*x*(q[i].fr-q[i+1].fr);
    }
    if(i+1<sz(q)&&L<R)
        return 1;
    return 0;
}
 
ll query(ll x)
{
    ll l=0, r=sz(q)-1, piv, ret;
    while(l<=r)
    {
        piv=(l+r)/2;
        ret=cons(x,piv);
        if(ret==0)
            return piv;
        if(ret==1)
            l=piv+1;
        else
            r=piv-1;
    }
    return 0;
}
bool del(pair<ll,ll>&a, pair<ll,ll>&b, pair<ll,ll>&c)
{
    L=1;
    R=1;
    L=L*(c.se-a.se)*(a.fr-b.fr);
    R=R*(b.se-a.se)*(a.fr-c.fr);
    return L<=R;
}
 
void inser(ll i)
{
    ll aux=0;
    if(i>0)
        aux=dp[i-1];
    pair<ll,ll>act={objs[i].fr,aux};
    while(sz(q)>1&&del(q[sz(q)-2],q.back(),act))
        q.pop_back();
    q.pb(act);
}
 
bool comp(pair<ll,ll>&a, pair<ll,ll>&b)
{
    if(a.fr!=b.fr)
        return a.fr>b.fr;
    return a.se>b.se;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, ma=-1;
    cin >> n;
    vector<pair<ll,ll>>v(n);
    for(i=0; i<n; i++)
        cin >> v[i].fr >> v[i].se;
    
    sort(all(v),comp);
 
    for(auto k:v)
    {
        if(ma<k.se)
        {
            objs.pb(k);
            ma=k.se;
        }
    }
 
    dp.resize(sz(objs));
    dp[0]=objs[0].fr*objs[0].se;
    inser(0);
    ll ret;
    for(i=1; i<sz(objs); i++)
    {
        inser(i);
        ret=query(objs[i].se);
        dp[i]=objs[i].se*q[ret].fr+q[ret].se;
    }
    cout << dp[sz(objs)-1];
    return 0;
}
 
