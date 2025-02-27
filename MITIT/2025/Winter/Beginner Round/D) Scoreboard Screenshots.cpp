//Link: https://codeforces.com/gym/105668/problem/D
//Score: 100/100
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

    ll n, k, i, j;
    cin >> n >> k;

    vector<vector<ll>>v(k,vector<ll>(n));


    vector<vector<ll>>ord;

    forn(i,n)
        forn(j,k)
            cin >> v[j][i];

    ord=v;

    forn(i,k)
        sort(ord[i].begin(),ord[i].end());

    vector<bool>vis(n,0);
    vector<ll>ans(n,-1);
    vector<vector<ll>>caps(n,vector<ll>(k)),capsOrd(n,vector<ll>(k));
    forn(i,k)
        forn(j,n)
        {
            caps[j][i]=v[i][j];
            capsOrd[j][i]=ord[i][j];
        }

    forn(i,n)
    {
        forn(j,n)
        {
            if(vis[j])
                continue;
            if(capsOrd[i]==caps[j])
            {
                vis[j]=1;
                ans[i]=j;
                break;
            }
        }
        if(ans[i]==-1)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    forn(i,n)
        cout << ans[i]+1 << ' ';
    return 0;
}
