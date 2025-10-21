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

const int MAXN = 3e5 + 1;

vector<ll> R, res, comp[MAXN], block, bkey[MAXN], key, alc;
ll last[MAXN], id[MAXN], ans, keys[MAXN];
vector<pair<ll, ll>> grafo[MAXN];
bool vis[MAXN], dead[MAXN];

void unionfind(ll x, ll y)
{
    y = id[y];
    for (auto k : comp[x])
    {
        id[k] = y;
        comp[y].pb(k);
    }
}

void cln()
{
    for (auto k : block)
        bkey[k].clear();
    for (auto k : key)
        keys[k] = 0;
    alc.clear();
    key.clear();
    block.clear();
}

void bfs(ll nod, ll it)
{
    last[nod] = it;
    queue<ll> q;
    q.push(nod);

    while (q.size())
    {
        ll x = q.front();
        q.pop();
        if (id[x] != id[nod])
        {
            unionfind(nod, x);
            last[id[x]] = it;
            cln();
            return;
        }

        if (vis[x])
            continue;
        vis[x] = 1;
        alc.pb(x);

        if (keys[R[x]] == 0)
        {
            keys[R[x]] = 1;
            key.pb(R[x]);
            while (bkey[R[x]].size())
            {
                q.push(bkey[R[x]].back());
                bkey[R[x]].pop_back();
            }
        }

        for (auto k : grafo[x])
        {
            if (keys[k.se])
                q.push(k.fr);
            else
            {
                bkey[k.se].pb(k.fr);
                block.pb(k.se);
            }
        }
    }

    dead[nod] = 1;
    if(sz(alc)<ans)
    {
        res.clear();
        ans=sz(alc);
    }
    if(ans==sz(alc))
    {
        for(auto k:alc)
            res.pb(k);
    }
    cln();
}

std::vector<int> find_reachable(std::vector<int> r, std::vector<int> u, std::vector<int> v, std::vector<int> c)
{
    ll n = sz(r), m = sz(c), i, it = 0;
    ans = n + 1;
    R.resize(n);
    for (i = 0; i < n; i++)
    {
        R[i]=r[i];
        id[i] = i;
        comp[i] = {i};
    }

    for (i = 0; i < m; i++)
    {
        grafo[u[i]].pb({v[i], c[i]});
        grafo[v[i]].pb({u[i], c[i]});
    }

    bool band = 1;

    while (band)
    {
        it++;
        memset(vis, 0, sizeof(vis));
        band = 0;
        for (i = 0; i < n; i++)
        {
            if (id[i] == i && !dead[i] && last[i] != it)
            {
                bfs(i, it);
                band = 1;
            }
        }
    }

    vector<int>ret(n,0);

    for(auto k:res)
        ret[k]=1;
    return ret;
}
