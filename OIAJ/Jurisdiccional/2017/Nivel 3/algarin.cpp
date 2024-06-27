#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, i, j, x=0, y=0,INF=-LLONG_MAX;
    char a;
    cin >> m >> n;
    vector<vector<char>>mat(m,vector<char>(n));
    vector<vector<long long>>dp(m,vector<long long>(n,INF));
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]=='A')
            {
                mat[i][j]=0;
                x=i;
                y=j;
                dp[i][j]=0;
            }
        }
    }
    for(j=0; j<n-1; j++)
    {
        for(i=0; i<m; i++)
        {
            if(dp[i][j]<0)
                continue;
            if(mat[i][j+1]=='.')
            {
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
            }
            else if(mat[i][j+1]=='J')
            {
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]+1);
            }
            else if(mat[i][j+1]=='M')
            {
                if(dp[i][j]>0)
                    dp[i][j+1]=0;
            }
            if(i>0)
            {
                if(mat[i-1][j+1]=='.')
                {
                    dp[i-1][j+1]=max(dp[i-1][j+1],dp[i][j]);
                }
                else if(mat[i-1][j+1]=='J')
                {
                    dp[i-1][j+1]=max(dp[i-1][j+1],dp[i][j]+1);
                }
                else if(mat[i-1][j+1]=='M')
                {
                    if(dp[i][j]>0)
                        dp[i-1][j+1]=0;
                }
            }
            if(i<m-1)
            {
                if(mat[i+1][j+1]=='.')
                {
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
                }
                else if(mat[i+1][j+1]=='J')
                {
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
                }
                else if(mat[i+1][j+1]=='M')
                {
                    if(dp[i][j]>0)
                        dp[i+1][j+1]=0;
                }
            }
        }

    }
    long long ma=-1;
    for(i=0;i<m; i++)
    {
        ma=max(dp[i][n-1],ma);
    }
    if(ma==-1)
    {
        cout << "SIN SALIDA";
    }
    else
    cout << ma;
    return 0;
}