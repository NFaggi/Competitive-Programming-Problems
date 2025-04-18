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

vector<ll> v;
vector<vector<ll>>dp;

ll calc(ll l, ll r)
{
    if(l>=r)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    ll ans=LLONG_MAX, aum;
    for(ll i=l; i<r; i++)
    {
        aum=v[r];
        if(l>0)
            aum-=v[l-1];
        ans=min(ans,calc(l,i)+calc(i+1,r)+aum);
    }
    dp[l][r]=ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i;
    cin >> n;
    v.resize(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=1; i<n; i++)
        v[i]+=v[i-1];
    dp.resize(n,vector<ll>(n,-1));
    cout << calc(0,n-1);
    return 0;
}
