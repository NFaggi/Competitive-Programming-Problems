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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, j, newMask, mask, ma=LLONG_MIN, act;
    cin >> n;
    vector<vector<ll>>mat(n,vector<ll>(n,0));
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin >> mat[i][j];
    vector<ll>dp(1<<n,0);
    for(mask=1; mask<sz(dp); mask++)
    {
        for(i=0; i<n; i++)
        {
            if(!((1<<i)&mask))
                continue;
            for(j=i+1; j<n; j++)
            {
                if(!((1<<j)&mask))
                    continue;
                dp[mask]+=mat[i][j];
            }
        }
    }
    for(mask=0; mask<sz(dp); mask++)
    {
        for(i=mask; i>0; i=(i-1)&mask)
        {
            dp[mask]=max(dp[mask],dp[mask^i]+dp[i]);
        }
        ma=max(ma,dp[mask]);
    }
    cout << dp.back();
    return 0;
}
