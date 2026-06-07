//Link: https://codeforces.com/contest/2175/problem/D
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

void solve()
{
    ll n, k, i, j;
    cin >> n >> k;
    vector<ll>v(n), ans(n,0);
    for(i=0; i<n; i++)
        cin >> v[i];

    vector<pair<ll,ll>>p;
    p.pb({v[0],0});
    for(i=1; i<n; i++)
        if(p.back().fr<v[i])
            p.pb({v[i],i});
    
    vector<vector<ll>>dp(k+1,vector<ll>(k+1,0));
    ll o, ant=1, ma=0, dis;
    for(i=0; i<sz(p); i++)
    {
        dis=n-p[i].se;
        for(ant; ant<=p[i].fr; ant++)
        {
            for(j=0; j<k; j++)
            {
                if(j+ant>k)
                    break;
                for(o=0; o<k; o++)
                {
                    if(o>=ant)
                        break;
                    dp[j+ant][ant]=max(dp[j+ant][ant],dp[j][o]+dis*(ant-o));
                    ma=max(ma,dp[j+ant][ant]);
                }
            }
        }
    }
    cout << ma << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
