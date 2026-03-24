#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

void solve()
{
    ll n, i, j;
    cin >> n;
    vector<ll>t(n),p(n), dp(n+1,LLONG_MAX);
    dp[0]=0;
    for(i=0; i<n; i++)
    {
        cin >> t[i] >> p[i];
        for(j=i; j>=0; j--)
        {
            if(dp[j]<=p[i])
                dp[j+1]=min(dp[j+1],dp[j]+t[i]);
        }
    }
    ll ma=0;
    for(i=1; i<=n; i++)
    {
        if(dp[i]!=LLONG_MAX)
            ma=i;
    }
    cout << ma << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
