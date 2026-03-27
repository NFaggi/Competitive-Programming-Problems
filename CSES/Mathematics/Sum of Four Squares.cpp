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
    ll n, i, sq, j;
    cin >> n;
    
    sq=sqrt(n);

    vector<pair<ll,ll>>dp(n+1,{0,0});

    vector<ll>v;

    ll act;
    for(i=0; i<=sq; i++)
    {
        act=0;
        for(j=0; j<4; j++)
        {
            act+=i*i;
            if(act>n)
                break;
            v.pb(i*i);
        }
    }

    for(i=1; i<sz(v); i++)
    {
        for(j=i+1; j<sz(v); j++)
        {
            act=v[i]+v[j];
            if(act>n)
                break;
            if(dp[n-act].fr+dp[n-act].se==n-act)
            {
                cout << sqrt(dp[n-act].fr) << ' ' << sqrt(dp[n-act].se) << ' ' << sqrt(v[i]) << ' ' << sqrt(v[j]) << '\n';
                return;
            }
        }
        for(j=i-1; j>=0; j--)
        {
            if(v[i]+v[j]>n)
                continue;
            dp[v[i]+v[j]]={v[i],v[j]};
        }
    }
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
