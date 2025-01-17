//Link: https://juez.oia.unsam.edu.ar/task/168
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=int(2e4)+1;
ll dp[MAXN];
long long monedas(vector<int> &a)
{
    int i,j,n=int(a.size()),num;
    ll cant=0;
    for(i=0; i<MAXN; i++)
        dp[i]=LLONG_MAX;
    dp[0]=0;
    for(i=1; i<MAXN; i++)
    {
        cant=0;
        for(j=0; j<n; j++)
        {
            if(a[j]>i)
                break;
            dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
        num=i;
        for(j=n-1; j>=0; j--)
        {
            cant+=num/a[j];
            num=num%a[j];
        }
        if(cant!=dp[i])
            return i;
    }
    return -1;
}
