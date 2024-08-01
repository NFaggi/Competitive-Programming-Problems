#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j;
    long long W;
    cin >> n >> W;
    vector<pair<long long,long long>>obj(n);
    vector<vector<long long>>mat(n+1,vector<long long>(W+1,LLONG_MAX));
    for(i=0; i<n; i++)
    {
        cin >> obj[i].first >> obj[i].second;
    }
    sort(obj.begin(),obj.end());
    for(i=0; i<W+1; i++)
    {
        mat[0][i]=0;
    }
    for(i=0; i<n+1; i++)
    {
        mat[i][0]=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=1; j<min(obj[i].first,W+1); j++)
        {
            mat[i+1][j]=mat[i][j];
        }
        for(j=obj[i].first; j<W+1; j++)
        {
            mat[i+1][j]=max(mat[i][j],mat[i][j-obj[i].first]+obj[i].second);
        }
    }
    long long ma=0;
    for(i=0; i<=n; i++)
    {
        ma=max(mat[i][W],ma);
    }
    cout << ma;
    return 0;
}