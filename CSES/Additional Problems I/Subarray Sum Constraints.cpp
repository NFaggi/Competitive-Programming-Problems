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

const int MAXN=5001;

ll vis[MAXN], p[MAXN];
vector<pair<ll,ll>>grafo[MAXN];

bool dfs(ll nod)
{
    vis[nod]=1;
    for(auto k:grafo[nod])
    {
        if(!vis[k.fr])
        {
            p[k.fr]=p[nod]+k.se;
            if(!dfs(k.fr))
                return 0;
        }
        else if(p[k.fr]!=p[nod]+k.se)
            return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, m, l, r, s;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> l >> r >> s;
        l--;
        grafo[l].pb({r,s});
        grafo[r].pb({l,-s});
    }
    for(i=0; i<=n; i++)
        if(vis[i]==0&&!dfs(i))
        {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";
    for(i=1; i<=n; i++)
        cout << p[i]-p[i-1] << ' ';
    cout << '\n';
    return 0;
}
