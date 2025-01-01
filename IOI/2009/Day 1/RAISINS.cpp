//Link: https://ioi.contest.codeforces.com/group/32KGsXgiKA/contest/103754/problem/D
//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
using namespace std;

ll choc[50][50],dp[50][50],memo[50][50][50][50];

ll div(ll a, ll b, ll c, ll d)
{
    if(a==c&&b==d)
        return 0;

    if(memo[a][b][c][d]!=0)
        return memo[a][b][c][d];

    ll i, j,tot=dp[c+1][d+1]-dp[a][d+1]-dp[c+1][b]+dp[a][b], cost=INT_MAX;

    for(i=1; i<=abs(a-c); i++)
        cost=min(div(a+i,b,c,d)+div(a,b,(a+i)-1,d),cost);

    for(i=1; i<=abs(b-d); i++)
        cost=min(div(a,b+i,c,d)+div(a,b,c,(b+i)-1),cost);

    memo[a][b][c][d]=cost+tot;

    return cost+tot;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, i, j;
    cin >> n >> m;

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin >> choc[i][j];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            dp[i][j]=choc[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

    cout << div(0,0,n-1,m-1);
    return 0;
}
