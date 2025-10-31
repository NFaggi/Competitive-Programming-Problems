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

const int MAXN=1e5+1;
const int MAXM=2e5+1;

vector<pair<ll,ll>>grafo[MAXN];
vector<ll> gf[MAXN], ginv[MAXN];
ll comp[MAXN], act=1;
bool used[MAXM], vis[MAXN];

void dfs(ll nod)
{
    for(auto k:grafo[nod])
    {
        if(used[k.se])
            continue;
        used[k.se]=1;
        gf[nod].pb(k.fr);
        ginv[k.fr].pb(nod);
        dfs(k.fr);
    }
}
vector<ll>topo;

void dfsT(ll nod)
{
    vis[nod]=1;
    for(auto k:gf[nod])
    {
        if(vis[k])
            continue;
        dfsT(k);
    }
    topo.pb(nod);
}

void dfsC(ll nod)
{
    comp[nod]=act;
    for(auto k:ginv[nod])
    {
        if(comp[k])
            continue;
        dfsC(k);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, a, b;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        grafo[a].pb({b,i});
        grafo[b].pb({a,i});
    }
    dfs(1);
    dfsT(1);
    dfsC(topo.back());

    for(i=1; i<=n; i++)
    {
        if(comp[i]!=act)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for(i=1; i<=n; i++)
    {
        for(auto k:gf[i])
        {
            cout << i << ' ' << k << '\n';
        }
    }
    return 0;
}
