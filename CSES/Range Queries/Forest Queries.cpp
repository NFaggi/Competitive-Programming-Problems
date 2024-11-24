#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n, q, i, j, a, b, c, d, sum;
    string s;
    cin >> n >> q;
    for(i=1; i<=n; i++)
    {
        cin >> s;
        for(j=1; j<=n; j++)
        {
            if(s[j-1]=='*')
            {
                dp[i][j]=1;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    while(q--)
    {
        cin >> a >> b >> c >> d;
        if(a>c)
            swap(a,c);
        if(b>d)
            swap(b,d);
        sum=dp[c][d]+dp[a-1][b-1]-dp[a-1][d]-dp[c][b-1];
        printf("%d\n",sum);

    }
    return 0;
}
