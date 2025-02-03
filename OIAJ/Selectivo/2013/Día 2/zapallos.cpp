//Link: https://juez.oia.unsam.edu.ar/task/138
//Score: 100/100
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("zapallos.in");
    ofstream cout("zapallos.out");
    long long n, m, i, a,b,k, pv, val,j,xA=-1,xK=-1;
    cin >> n >> m;
    vector<vector<long long>>v(n);
    vector<pair<long long, long long>>ord;
    for(i=0; i<n; i++)
    {
        cin >> a;
        for(j=0; j<a; j++)
        {
            cin >> b;
            v[i].push_back(10-b);
        }
        ord.push_back({-int(v[i].size()),i});
    }
    sort(ord.begin(),ord.end());
    vector<vector<long long>>dp(n+1,vector<long long>(m+1,-LLONG_MAX));
    vector<vector<pair<long long,long long>>>cam(n+1,vector<pair<long long, long long>>(m+1,{-1,-1}));
    for(i=0; i<=n; i++) {
        dp[i][0]=0;
    }
    long long mag=0,aj=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            pv=ord[i-1].second;
            val=0;
            if(dp[i-1][j]!=-LLONG_MAX)
            {
                dp[i][j]=dp[i-1][j];
                cam[i][j]={i-1,j};
            }
                
            for(k=1; k<=j; k++)
            {
                if(k-1>=int(v[pv].size()))
                    break;
                val+=v[pv][k-1];
                if(dp[i-1][j-k]!=-LLONG_MAX&&dp[i-1][j-k]+val>dp[i][j])
                {
                    dp[i][j]=dp[i-1][j-k]+val;
                    cam[i][j]={i-1,j-k};
                }
            }
            if(mag<dp[i][j]||(mag==dp[i][j]&&j<aj)){
            mag=dp[i][j];
            aj=j;
            xA=i;
            xK=j;
            }
        }
    }
    vector<long long> rec(n + 1, 0);
    vector<long long> most(n, 0);
    pair<long long, long long> aDP;

    while (xA > 0 && xK > 0) {
        aDP = cam[xA][xK];
        if (aDP.second >= 0)
            rec[xA] = xK - aDP.second;
        xA = aDP.first;
        xK = aDP.second;
    }
    for (i = 1; i <= n; ++i) {
        most[ord[i - 1].second] = rec[i];
    }
    cout << mag << ' ' << aj << endl;
    for (auto k : most) {
        cout << k << ' ';
    }
    cout << '\n';

    return 0;
}
