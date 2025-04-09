#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, j, q, x,y,x1,y1,res;
    cin >> n >> m >> q;
    vector<string>v(n);
    vector<vector<int>>mat(n+1,vector<int>(m+1,0)),matV(n+1,vector<int>(m+1,0)),matH(n+1,vector<int>(m+1,0)),matHV(n+1,vector<int>(m+1,0));
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(v[i][j]=='1')
            {
                mat[i+1][j+1]=1;
                if(j+1<int(v[i].size())&&v[i][j+1]=='1')
                    matH[i+1][j+1]=1;
                if(i+1<int(v.size())&&v[i+1][j]=='1')
                    matV[i+1][j+1]=1;

            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(v[i][j]=='1')
            {
                if(i+2<=n&&j+2<=m&&mat[i+2][j+1]==1&&mat[i+1][j+2]==1&&mat[i+2][j+2]==1)
                    matHV[i+1][j+1]=1;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            matV[i][j] += matV[i-1][j] + matV[i][j-1] - matV[i-1][j-1];
            matH[i][j] += matH[i-1][j] + matH[i][j-1] - matH[i-1][j-1];
            matHV[i][j] += matHV[i-1][j] + matHV[i][j-1] - matHV[i-1][j-1];
        }
    }
    while(q--)
    {
        cin >> x >>  y  >> x1 >> y1;
        res = mat[x1][y1] - mat[x-1][y1] - mat[x1][y-1] + mat[x-1][y-1];
        res -= matV[x1-1][y1] - matV[x-1][y1] - matV[x1-1][y-1] + matV[x-1][y-1];
        res -= matH[x1][y1-1] - matH[x-1][y1-1] - matH[x1][y-1] + matH[x-1][y-1];
        res+= matHV[x1-1][y1-1]-matHV[x-1][y1-1]-matHV[x1-1][y-1]+matHV[x-1][y-1];
        cout << res << '\n';
    }
    return 0;
}
