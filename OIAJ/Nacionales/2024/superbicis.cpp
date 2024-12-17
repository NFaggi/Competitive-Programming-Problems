//Link: https://juez.oia.unsam.edu.ar/task/171
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dist(pair<ll,ll>a,pair<ll,ll>b)
{
    ll res=abs(a.first-b.first)+abs(a.second-b.second);
    return res;
}
long long superbicis(vector<long long> &x, vector<long long> &y, vector<int> &c)
{
    vector<pair<ll,ll>>sob,falt;
    int i, n=int(x.size()), j,b=0,k,mask;
    for(int l:c)
        b+=l;
    b/=n;
    for(i=0; i<n; i++)
        if(c[i]>b)
            for(j=0; j<c[i]-b; j++)
                sob.push_back({x[i],y[i]});
        else if(c[i]<b)
            for(j=0; j<b-c[i]; j++)
                falt.push_back({x[i],y[i]});
    k=int(sob.size());
    vector<ll>dp(1<<k,LLONG_MAX);
    dp[0]=0;
    for(mask=1; mask<int(dp.size()); mask++)
    {
        i=__builtin_popcount(mask)-1;
        for(j=0; j<k; j++)
        {
            if((1<<j)&mask)
            {
                dp[mask]=min(dp[mask],dp[mask^(1<<j)]+dist(sob[i],falt[j]));
            }
        }
    }
    return dp[int(dp.size())-1];
}
