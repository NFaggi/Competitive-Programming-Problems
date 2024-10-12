//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/90
#include <bits/stdc++.h>

using namespace std;

int  nivelacion( string palabra )
{
    int n=int(palabra.size()), i, j;
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(i=n-2; i>=0; i--)
    {
        for(j=i+1; j<n; j++)
        {
            if(palabra[i]==palabra[j])
            {
                dp[i][j]=dp[i+1][j-1];
            }
            else
            {
                dp[i][j]=min(dp[i][j-1],dp[i+1][j])+1;
            }
        }
    }
    return dp[0][n-1];
}