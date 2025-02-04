//Link: https://juez.oia.unsam.edu.ar/task/162
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

long long saltarines(int K, vector<int> &elegancias, vector<int> &ubicaciones)
{
    long long n=int(elegancias.size())+1,c=int(ubicaciones.size()), i, j, k, d;
    long long ma=0, costo;
    vector<vector<long long>>dp(c+1,vector<long long>(K+1,0));
    vector<long long>pref(n,0);
    sort(ubicaciones.begin(),ubicaciones.end());
    for(i=1; i<n; i++)
    {
        pref[i]=pref[i-1]+elegancias[i-1];
    }
    for(i=0; i<n; i++)
    {
        for(j=c-1; j>=0; j--)
        {
            d=i-ubicaciones[j];
            costo=pref[i]-pref[ubicaciones[j]];
            if(d<0)
                continue;
            for(k=0; k<=K-d; k++)
            {
                dp[j+1][k+d]=max(dp[j+1][k+d],dp[j][k]+costo);
            }
        }
    }
    for(i=0; i<=K; i++)
        ma=max(ma,dp[c][i]);
    return ma;
}
