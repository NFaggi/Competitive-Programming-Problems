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
    ll n, m, ma=-1, mai=0, maj=0, i, j, sig;
    cin >> n >> m;
    vector<ll>a(n+1),b(m+1), ans;
    for(i=1; i<=n; i++)
        cin >> a[i];
    for(i=1; i<=m; i++)
        cin >> b[i];
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0)), ant(n+1,vector<ll>(m+1,-1));
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            dp[i][j]=dp[i-1][j];
            ant[i][j]=1;
            if(dp[i][j]<dp[i][j-1])
            {
                dp[i][j]=dp[i][j-1];
                ant[i][j]=2;
            }
            if(a[i]==b[j])
            {
                if(dp[i][j]<dp[i-1][j-1]+1)
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ant[i][j]=3;
                }
            }
            if(dp[i][j]>ma)
            {
                ma=dp[i][j];
                mai=i;
                maj=j;
            }
        }
    }
    i=mai;
    j=maj;
    sig=ant[i][j];
    while(sig!=-1)
    {
        if(sig==3)
        {
            ans.pb(a[i]);
            i--;
            j--;
        }
        else if(sig==2)
            j--;
        else if(sig=1)
            i--;
        sig=ant[i][j];
    }
    cout << ma << '\n';
    reverse(all(ans));
    for(auto k:ans)
        cout << k << ' ';
    return 0;
}
