//Link: https://codeforces.com/problemset/problem/2049/D
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

const int MAXN=201;
ll INF = 1e14;
ll dp[MAXN][MAXN][MAXN], v[MAXN][MAXN];

void solve()
{
    ll i, j, n, m, k, mi, l, p;
    cin >> n >> m >> k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin >> v[i][j];
            for(l=0; l<m; l++)
            {
                dp[i][j][l]=INF;
            }
        }
    }
    dp[0][0][0]=v[0][0];
    for(i=1; i<m; i++)
        dp[0][0][i]=v[0][i]+k*i;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            mi=INF;
            for(l=0; l<m; l++)
                mi=min(mi,dp[i][j][l]);
            if(i+1<n)
            {
                for(l=0; l<m; l++)
                {
                    p=(j+l)%m;
                    dp[i+1][j][l]=min(dp[i+1][j][l],mi+v[i+1][p]+k*l);
                }
            }
            if(j+1<m)
            {
                for(l=0; l<m; l++)
                {
                    p=((j+1+l)%m);
                    dp[i][j+1][l]=min(dp[i][j+1][l],dp[i][j][l]+v[i][p]);
                }
            }

        }
    }
    mi=INF;
    for(i=0; i<m; i++)
    {
        mi=min(dp[n-1][m-1][i],mi);
    }
    cout << mi << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
