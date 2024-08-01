#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main()
{
    int n, m, i,j;
    cin >> n >> m;
    vector<string>v(n);
    vector<vector<int>>sum(n,vector<int>(m,0));
    for(i=0; i<n; i++)
    {
        cin >>v[i];
    }
    sum[0][0]=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(v[i][j]=='#')
                continue;
            if(i>0)
            {
                sum[i][j]=(sum[i][j]+sum[i-1][j])%MOD;
            }
            if(j>0)
            {
                sum[i][j]=(sum[i][j]+sum[i][j-1])%MOD;
            }
        }
    }

    cout << sum[n-1][m-1];
    return 0;
}
