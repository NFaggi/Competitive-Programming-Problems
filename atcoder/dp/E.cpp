#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, k;
    long long w, ma=0,tam=0;
    cin >> n >> w;
    vector<pair<long long,long long>>v(n);
    vector<pair<long long, long long>>b;

    for(i=0; i<n; i++)
    {
        cin >> v[i].second >> v[i].first;
        tam+=v[i].first;
    }
    vector<long long>dp(tam+1,LLONG_MAX);
    
    sort(v.begin(),v.end());
    dp[0]=0;
    for(i=0; i<int(v.size()); i++)
    {
        for(j=int(dp.size())-1; j>=v[i].first; j--)
        {
            if(dp[j-v[i].first]!=LLONG_MAX)
            dp[j]=min(dp[j],dp[j-v[i].first]+v[i].second);
        }
    }
    for(int i=0; i<int(dp.size()); i++)
    {
        if(dp[i]<=w)
        ma=i;
    }
    cout << ma;
    return 0;
}