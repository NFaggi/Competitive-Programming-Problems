//Link: https://codeforces.com/problemset/problem/1042/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1<<3;
ll dp[MAXN];
int main()
{
    ll n, c, pos, i, j;
    string s;
    cin >> n;
    for(i=1; i<MAXN; i++)
        dp[i]=LLONG_MAX;
    for(i=0; i<n; i++)
    {
        pos=0;
        cin >> c >> s;
        for(auto k: s)
        {
            if(k=='A')
                pos|=1;
            else if(k=='B')
                pos|=1<<1;
            else
                pos|=1<<2;
        }
        dp[pos]=min(dp[pos],c);
    }
    for(i=1; i<MAXN; i++)
    {
        for(j=1; j<i; j++)
        {
            pos=i|j;
            if(dp[i]==LLONG_MAX||dp[j]==LLONG_MAX)
                continue;
            dp[pos]=min(dp[pos],dp[i]+dp[j]);
        }
    }
    pos=(1<<3)-1;
    if(dp[pos]==LLONG_MAX)
        cout << -1;
    else
        cout << dp[pos];
    return 0;
}
