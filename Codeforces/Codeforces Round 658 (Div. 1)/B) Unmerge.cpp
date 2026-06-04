//Link: https://codeforces.com/problemset/problem/1381/B
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
    ll n, i, j, a, b;
    cin >> n;
    vector<ll>v(n*2+1);
    for(i=n*2; i>=1; i--)
        cin >> v[i];
    vector<vector<vector<ll>>>dp(2,vector<vector<ll>>(n+1,vector<ll>(n+1,0))); 
    // dp[i][j][k]: i ultimo vector al que le agregue un numero (0: A, 1: B), 
    // j: tam de A, k: tam de B 
    // y en dp[i][j][k] se guarda cual es el ultimo nodo en el vector que no es i
    dp[0][0][0]=dp[1][0][0]=n*2+1;
    v[0]=n*2+1;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            b=v[i+j];
            if(i>0)
            {
                a=dp[1][i-1][j];

                if(a)
                {
                    if(v[i+j-1]>b)
                        dp[0][i][j]=max(dp[0][i][j],v[i+j-1]);
                }

                a=dp[0][i-1][j];
                if(a>b)
                    dp[0][i][j]=max(dp[0][i][j],a);
            }
            
            if(j>0)
            {
                a=dp[0][i][j-1];
                if(a)
                {
                    if(v[i+j-1]>b)
                        dp[1][i][j]=max(dp[1][i][j],v[i+j-1]);
                }
                a=dp[1][i][j-1];
                if(a>b)
                    dp[1][i][j]=max(dp[1][i][j],a);
            }
        }
    }
    if(!dp[0][n][n]&&!dp[1][n][n])
        cout << "NO\n";
    else
        cout << "YES\n";
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
