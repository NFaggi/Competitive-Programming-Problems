//Link: https://codeforces.com/problemset/problem/455/A
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+1;
ll dp[MAXN];
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    ll n, i, x;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x;
        dp[x]+=x;
    }
    for(i=1; i<MAXN; i++)
    {
        if(i>1)
        {
            dp[i]=dp[i-2]+dp[i];
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout << dp[MAXN-1];
    return 0;
}
