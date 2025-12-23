//Link: https://oj.uz/problem/view/APIO20_swap
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

const int MAXN = 1e5 + 1;
const int LOG = 20;
const ll INF = LLONG_MAX;
vector<pair<ll, ll>> grafo[MAXN], grafo2[MAXN], grafo3[MAXN];
ll up[MAXN][LOG], miA[MAXN][LOG], disUp[MAXN][LOG], mi2D[MAXN], mi2DU[MAXN], prof[MAXN], up2[MAXN][LOG], disUp2[MAXN][LOG], con[MAXN], dp[MAXN], dpU[MAXN];
void dfs(ll nod, ll pad)
{
    up[nod][0] = pad;
    ll cant = 0;
    for (auto k : grafo[nod])
    {
        cant++;
        if (cant == 3)
        {
            miA[nod][0] = k.fr;
            break;
        }
    }
    for (ll i = 1; i < LOG; i++)
    {
        up[nod][i] = up[up[nod][i - 1]][i - 1];
        miA[nod][i] = min(miA[nod][i - 1], miA[up[nod][i - 1]][i - 1]);
        disUp[nod][i] = max(disUp[nod][i - 1], disUp[up[nod][i - 1]][i - 1]);
    }

    ll act = 0;
    cant = 0;
    for (auto k : grafo[nod])
    {
        if (k.se == pad)
            continue;
        prof[k.se] = prof[nod] + 1;
        cant++;
        act = max(act, k.fr);
        if (cant == 2)
            mi2D[nod] = min(mi2D[nod], act);
        disUp[k.se][0] = k.fr;
        dfs(k.se, nod);
        dp[nod] = min(dp[nod], max(k.fr, dp[k.se]));
        mi2D[nod] = min(mi2D[nod], max(mi2D[k.se], k.fr));
    }
}

void dfs2(ll nod, ll pad, ll pMiD2)
{
    mi2DU[nod] = pMiD2;
    for (auto k : grafo[nod])
    {
        if (k.se == pad)
            continue;
        ll cant = 0, act = 0, m2D = INF;
        for (auto l : grafo[nod])
        {
            if (l.se == k.se)
                continue;
            cant++;
            act = max(act, l.fr);
            if (cant == 2)
            {
                m2D = act;
                break;
            }
        }
        for (auto l : grafo2[nod])
        {
            if (l.se == k.se || l.se == pad)
                continue;
            m2D = min(m2D, l.fr);
            break;
        }
        dpU[k.se] = min(dpU[k.se], max(min(dp[nod], dpU[nod]), k.fr));
        dfs2(k.se, nod, max(k.fr, min(m2D, mi2DU[nod])));
    }
}
ll aCon = 1;
void dfs3(ll nod, ll pad)
{
    con[nod] = aCon;
    up2[nod][0] = pad;
    for (ll i = 1; i < LOG; i++)
    {
        up2[nod][i] = up2[up2[nod][i - 1]][i - 1];
        disUp[nod][i] = max(disUp[nod][i - 1], disUp[up[nod][i - 1]][i - 1]);
    }
    for (auto k : grafo3[nod])
    {
        if (k.se == pad)
            continue;
        disUp[k.se][0] = k.fr;
        dfs3(k.se, nod);
    }
}

ll id[MAXN];
vector<ll> comp[MAXN];

bool unionfind(ll a, ll b)
{
    ll x = id[a], y = id[b];
    if (x == y)
        return 1;
    if (sz(comp[x]) < sz(comp[y]))
        swap(x, y);
    for (auto k : comp[y])
    {
        comp[x].pb(k);
        id[k] = x;
    }
    return 0;
}

ll n, m, xZ, yZ;
void init(int N, int M,
          std::vector<int> U, std::vector<int> V, std::vector<int> W)
{
    vector<vector<ll>> v, v2;
    ll i, j;
    for (i = 0; i < M; i++)
        v.pb({W[i], U[i], V[i]});
    sort(all(v));
    for (i = 0; i < N; i++)
    {
        dp[i] = dpU[i] = INF;
        id[i] = i;
        comp[i] = {i};
    }
    U.resize(0);
    V.resize(0);
    W.resize(0);
    for (i = 0; i < sz(v); i++)
    {
        grafo3[v[i][1]].pb({v[i][0], v[i][2]});
        grafo3[v[i][2]].pb({v[i][0], v[i][1]});
        if (unionfind(v[i][1], v[i][2]))
        {
            dpU[v[i][1]] = dp[v[i][1]] = min(dp[v[i][1]], 1ll * v[i][0]);
            dpU[v[i][2]] = dp[v[i][2]] = min(dp[v[i][2]], 1ll * v[i][0]);
            continue;
        }
        W.pb(v[i][0]);
        U.pb(v[i][1]);
        V.pb(v[i][2]);
    }
    n = N;
    M = m = sz(V);
    for (i = 0; i < MAXN; i++)
    {
        mi2D[i] = INF;
        mi2DU[i] = INF;
        for (j = 0; j < LOG; j++)
        {
            miA[i][j] = INF;
        }
    }

    for (i = 0; i < M; i++)
    {
        grafo[U[i]].pb({W[i], V[i]});
        grafo[V[i]].pb({W[i], U[i]});
    }
    for (i = 0; i < N; i++)
        sort(all(grafo[i]));
    dfs(0, 0);
    for (i = 0; i < M; i++)
    {
        grafo2[U[i]].pb({max(1ll * W[i], mi2D[V[i]]), V[i]});
        grafo2[V[i]].pb({max(1ll * W[i], mi2D[U[i]]), U[i]});
    }
    for (i = 0; i < N; i++)
        sort(all(grafo2[i]));
    dfs2(0, 0, INF);
}

ll k_ans(ll a, ll d)
{
    ll i;
    for (i = 0; i < LOG; i++)
        if ((1 << i) & d)
            a = up[a][i];
    return a;
}

ll lca(ll a, ll b)
{
    if (prof[b] > prof[a])
        swap(a, b);
    if (a == b)
        return a;
    ll i, d = prof[a] - prof[b];
    xZ = k_ans(a, d - 1);
    yZ = b;
    a = k_ans(a, d);
    if (a == b)
        return a;
    for (i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    xZ = a;
    yZ = b;
    return up[a][0];
}

ll dist(ll a, ll b)
{
    if (a == b)
        return 0;
    ll d = prof[a] - prof[b], i, act = 0;
    for (i = 0; i < LOG; i++)
    {
        if ((1 << i) & d)
        {
            act = max(act, disUp[a][i]);
            a = up[a][i];
        }
    }
    return act;
}

ll getMiA(ll a, ll b)
{
    if (a == b)
        return INF;
    a = up[a][0];
    ll d = prof[a] - prof[b], i, act = INF;
    for (i = 0; i < LOG; i++)
    {
        if ((1 << i) & d)
        {
            act = min(act, miA[a][i]);
            a = up[a][i];
        }
    }
    act = min(act, miA[a][0]);
    return act;
}

ll calDis(ll x, ll y)
{
    swap(up, up2);
    swap(disUp, disUp2);
    ll z = lca(x, y);
    ll ans = max(dist(x, z), dist(y, z));
    swap(up, up2);
    swap(disUp, disUp2);
    return ans;
}

ll dis(ll X, ll Y, ll px, ll py)
{
    priority_queue<pair<ll, ll>> pq;
    vector<ll> dist(n, INF), proc(n, 0);
    dist[X] = 0;
    pq.push({0, X});
    ll a, d;
    while (sz(pq))
    {
        a = pq.top().se;
        pq.pop();
        if (proc[a])
            continue;
        proc[a] = 1;
        for (auto k : grafo3[a])
        {
            if ((a == px && k.se == py) || (a == py && k.se == px))
                continue;
            d = max(k.fr, dist[a]);
            if (d < dist[k.se])
            {
                dist[k.se] = d;
                pq.push({-d, k.se});
            }
        }
    }
    return dist[Y];
}

int getMinimumFuelCapacity(int X, int Y)
{
    if (X == Y)
        return -1;
    ll Z = lca(X, Y), act, ag, iniD = max(dist(X, Z), dist(Y, Z));
    act = iniD;
    ag = min(getMiA(X, Z), getMiA(Y, Z));
    if (ag <= act)
        return act;
    if (X != Z)
        ag = min(ag, mi2D[X]);
    if (Y != Z)
        ag = min(ag, mi2D[Y]);
    if (ag <= act)
        return act;
    if (Y == Z)
        swap(X, Y);
    if (X == Z)
    {
        ll cal = 0, cant = 0;
        for (auto k : grafo[X])
        {
            if (k.se == xZ || k.se == yZ)
                continue;
            cant++;
            cal = max(cal, k.fr);
            if (cant == 2)
                break;
        }
        if (cant == 2)
            ag = min(ag, cal);
        if (ag <= act)
            return act;
        for (auto k : grafo2[X])
        {
            if (k.se == xZ || k.se == yZ || k.se == up[X][0])
                continue;
            ag = min(ag, k.fr);
            break;
        }
        if (ag <= act)
            return act;
        ag = min(ag, mi2DU[X]);
        if (ag <= act)
            return act;
        if (xZ == X)
            swap(xZ, yZ);
    }
    act = max(ag, act);
    ll maAr = -1, px = 0, py = 0, a, b;
    a = X;
    b = Y;
    act = min(act, max(iniD, min(dp[Z], dpU[Z])));
    if (act == INF)
        return -1;
    return act;
}
