#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, i,j,nmsk;
    long long x, nv, nvi;
    cin >> n >> x;
    vector<long long>v(n);
    vector<pair<long long, int>>dp((1<<n),{LLONG_MAX,INT_MAX});
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    dp[0]={0,1};
    for(i=0; i<int(dp.size()); i++)
    {
        for(j=0; j<int(v.size()); j++)
        {
            if((i&(1<<j))>0)
            {
                continue;
            }
            nmsk=(i+(1<<j));
            nvi=dp[i].second;
            nv=dp[i].first+v[j];
            if(nv>x)
            {
                nv=v[j];
                nvi++;
            }
            if(nvi<dp[nmsk].second)
            {
                dp[nmsk]={nv,nvi};
            }
            else if(nvi==dp[nmsk].second&&dp[nmsk].first>nv)
            {
                dp[nmsk]={nv,nvi};
            }
        }
    }
    cout << dp[(1<<n)-1].second;
    return 0;
}
