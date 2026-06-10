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

const int MAXN=2e5+1;

vector<ll>grafo[MAXN], dir[MAXN];

ll vis[MAXN], cicl;
vector<ll>act;

void dfs(ll nod)
{
    act.pb(nod);
    vis[nod]=1;
    for(auto k:grafo[nod])
    {
        if(vis[k])
            continue;
        dfs(k);
    }
}

void dfsDir(ll nod)
{
    vis[nod]=2;
    for(auto k:dir[nod])
    {
        if(vis[k]==2)
        {
            cicl=1;
            continue;
        }
        if(vis[k]==1)
            dfsDir(k);
    }
    vis[nod]=3;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, ans, a, b;
    cin >> n >> m;
    ans=n;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
        dir[a].pb(b);
    }

    for(i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            cicl=0;
            act.resize(0);
            dfs(i);
            for(auto k:act)
            {
                if(vis[k]==1)
                    dfsDir(k);
            }
            if(!cicl)
                ans--;
        }
    }
    cout << ans;
    return 0;
}
