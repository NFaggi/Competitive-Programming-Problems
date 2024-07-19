#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, q, i, j, a, b, c, d;
    char ch;
    cin >> n >> q;
    vector<vector<int>>mat(n+1,vector<int>(n+1,0));
    vector<vector<int>>sum(n+1,vector<int>(n+1,0));
 
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin >> ch;
            if(ch=='*')
                mat[i][j]=1;
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            sum[i][j]=mat[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    while(q--)
    {
        cin >> a >> b >> c >> d;
        cout << sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1] << '\n';
    }
    return 0;
}
