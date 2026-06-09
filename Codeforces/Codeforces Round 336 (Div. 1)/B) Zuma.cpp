//Link: https://codeforces.com/problemset/problem/607/B
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <numeric>
#define ll long long
#define sz(x) int(x.size())
using namespace std;

const int MAXN=501;
ll dp[MAXN][MAXN], v[MAXN], INF=LLONG_MAX;
ll calc(ll l, ll r)
{
    if(l==r)
        return 1;
    if(r-l==1)
    {
        if(v[l]==v[r])
            return 1;
        return 2;    
    }    
    if(dp[l][r])
        return dp[l][r];
    ll j, mi=INF;    
    if(v[l]==v[r])
        mi=calc(l+1,r-1);
    
    for(j=l; j<r; j++)
        mi=min(mi,calc(l,j)+calc(j+1,r));
    dp[l][r]=mi;
    return mi;    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> v[i];
    cout << calc(0,n-1);    
    return 0;
}
