#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;
long long dp[int(1e6)+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,ant=1,i;
    cin >> n;
    dp[1]=0;
    dp[2]=1;
    for(i=3; i<=n; i++)
    {
        dp[i]=((i-1)*(dp[i-1]+dp[i-2])%MOD)%MOD;
    }
    cout << dp[n];
    return 0;
}