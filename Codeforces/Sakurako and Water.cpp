//Link: https://codeforces.com/problemset/problem/2033/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t, n, i, j,tot;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<vector<ll>>mat(n,vector<ll>(n));
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cin >> mat[i][j];
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(j>0&&i>0)
                {
                    mat[i][j]=min(mat[i][j],mat[i-1][j-1]);
                }
            }
        }
        tot=0;
        for(i=0; i<n; i++)
        {
            if(mat[i][n-1]<0)
            {
                tot-=mat[i][n-1];
            }
            if(mat[n-1][i]<0&&n-1!=i)
            {
                tot-=mat[n-1][i];
            }
        }
        cout << tot << '\n';
    }

    return 0;
}
