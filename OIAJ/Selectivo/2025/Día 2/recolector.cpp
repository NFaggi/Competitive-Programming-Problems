//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second

using namespace std;

int recolector(vector<vector<int>> &E)
{
    ll n=sz(E), m=sz(E[0]), i, j, cost=0, mi;
    mi=min(n,m);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(E[i][j]>0)
            {
                cost++;
                cost+=E[i][j];
                if(i>0&&E[i-1][j]>0)
                    cost++;
                if(j>0&&E[i][j-1]>0)
                    cost++;
            }
        }
    }
    bool ag;
    for(i=m-mi; i<m-1; i++)
    {
        ag=1;
        for(j=0; j<m-i; j++)
        {
            if(E[j][i+j]<=0)
                ag=0;
        }
        if(ag)
            cost++;
    }
    return cost;
}
