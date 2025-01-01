//Score: 100/100
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

struct prob
{
    ll p, f, t;
};

bool comp(prob & a, prob & b)
{
    return a.t*b.f<b.t*a.f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t, i, j, ans=0, punt;
    cin >> n >> t;
    vector<prob>v(n);
    vector<ll>dp(t+1,0);
    for(i=0; i<n; i++)
        cin >> v[i].p >> v[i].f >> v[i].t;
    sort(all(v),comp);
    for(i=0; i<n; i++)
    {
        for(j=t; j>=v[i].t; j--)
        {
            punt=max(v[i].p-v[i].f*j,0ll);
            dp[j]=max(dp[j],dp[j-v[i].t]+punt);
        }
    }

    for(i=0; i<=t; i++)
    {
        ans=max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}
