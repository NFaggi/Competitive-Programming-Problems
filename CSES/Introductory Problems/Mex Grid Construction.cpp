#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, j, k;
    cin >> n;
    vector<vector<ll>>v(n,vector<ll>(n,0));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            vector<ll>vis(n*n+1,0);
            for(k=i-1; k>=0; k--)
                vis[v[k][j]]=1;
            for(k=j-1; k>=0; k--)
                vis[v[i][k]]=1;
            for(k=0; k<sz(vis); k++)
                if(vis[k]==0)
                {
                    v[i][j]=k;
                    break;
                }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
