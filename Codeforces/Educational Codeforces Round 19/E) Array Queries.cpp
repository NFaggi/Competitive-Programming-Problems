//Link: https://codeforces.com/problemset/problem/797/E
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
    ll n, q, i, ans, p, k, sq, j;
    cin >> n;
    sq=sqrt(n);
    vector<ll>v(n+1);
    for(i=1; i<=n; i++)
        cin >> v[i];

    vector<vector<ll>>dp(n+1,vector<ll>(sq));

    for(i=n; i>0; i--)
    {
        for(j=sq-1; j>0; j--)
        {
            if(i+v[i]+j>n)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i+v[i]+j][j]+1;
        }
    }

    cin >> q;
    while(q--)
    {
        cin >> p >> k;
        if(k<sq)
        {
            ans=dp[p][k];
        }
        else
        {
            ans=0;
            while(p<=n)
            {
                ans++;
                p=p+v[p]+k;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
