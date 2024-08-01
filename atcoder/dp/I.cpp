#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i,ma,j;
    cin >> n;
    ma=n/2;
    vector<double>v(n);
    vector<vector<double>>dp(n,vector<double>((ma+1),0));
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    dp[0][0]=v[0];
    if(1<=ma)
    dp[0][1]=(double(1)-v[0]);
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<=ma; j++)
        {
            dp[i+1][j]+=dp[i][j]*v[i+1];
            if(j+1<=ma)
            {
                dp[i+1][j+1]+=dp[i][j]*(double(1)-v[i+1]);

            }
        }
    }
    double sum=0;
    for(i=0; i<=ma; i++)
    {
        sum+=dp[n-1][i];
    }
    printf("%.10f",sum);
    return 0;
}