//Link: https://usaco.org/index.php?page=viewproblem2&cpid=1543
#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define fr first
#define se second
#define pb push_back
using namespace std;

const int MAXN = 2e5 + 10;
const ll INF = 1e10;
ll L[MAXN], R[MAXN], vis[MAXN], act, val[MAXN], par[MAXN];
vector<pair<ll, ll>> grafo[MAXN];
void init()
{
    act = 0;
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(vis, 0, sizeof(vis));
    for (ll i = 0; i < MAXN; i++)
        grafo[i].resize(0);
}

vector<ll> nods;
vector<pair<ll, ll>> times;
ll tot, bucle, nBuc, pars[MAXN], imp, sPar[MAXN], sImp[MAXN], in, inX, prof[MAXN];
void dfs(ll nod, ll pari)
{
    pars[nod] = pari;
    vis[nod] = act;
    nods.pb(nod);
    if (!pari)
    {
        times.pb({tot + L[nod], 0});
        times.pb({tot + R[nod], 1});
    }
    else
    {
        times.pb({tot - R[nod], 0});
        times.pb({tot - L[nod], 1});
    }
    for (auto k : grafo[nod])
    {
        if (k.fr == nod)
        {
            bucle = k.se;
            nBuc = nod;
        }
        if (vis[k.fr]==act)
        {
            if (pars[k.fr] == pars[nod] && prof[k.fr] <= prof[nod])
            {
                imp = 1;
                if(k.fr==nod)
                {
                    inX=k.se/2;
                    in=nod;
                    continue;
                }
                if (pari == 0)
                    sPar[nod] += k.se;
                else
                    sImp[nod] += k.se;
                in = k.fr;
                ll b = sImp[nod] - sImp[k.fr], a = sPar[nod] - sPar[k.fr];
                if (pars[k.fr] == 0)
                    inX = (a - b) / 2;
                else
                    inX = (b - a) / 2;
                if (pari == 0)
                    sPar[nod] -= k.se;
                else
                    sImp[nod] -= k.se;
            }
            continue;
        }
        par[k.fr] = k.se;
        if (!pari)
            tot += k.se;
        else
            tot -= k.se;
        sPar[k.fr] = sPar[nod];
        sImp[k.fr] = sImp[nod];
        if (pari == 0)
            sPar[k.fr] += k.se;
        else
            sImp[k.fr] += k.se;
        prof[k.fr] = prof[nod] + 1;
        dfs(k.fr, !pari);
        if (!pari)
            tot -= k.se;
        else
            tot += k.se;
        if (pari == 0)
            sPar[k.fr] -= k.se;
        else
            sImp[k.fr] -= k.se;
    }
}
ll cant = 0;
bool can(ll nod, ll x)
{
    val[nod] = x;
    vis[nod] = act;
    if (x >= L[nod] && x <= R[nod])
        cant++;
    for (auto k : grafo[nod])
    {
        if (vis[k.fr] == act)
        {
            if (val[nod] + val[k.fr] != k.se)
                return 0;
        }
        else if (!can(k.fr, k.se - x))
            return 0;
    }
    return 1;
}

void solve()
{
    init();
    ll n, m, i, x, y, z, ans = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> L[i];
    for (i = 1; i <= n; i++)
        cin >> R[i];
    bool band = 0;
    map<pair<ll, ll>, ll> ap;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        grafo[x].pb({y, z});
        grafo[y].pb({x, z});
        if (ap.find({x, y}) == ap.end())
        {
            ap[{x, y}] = z;
            ap[{y, x}] = z;
        }
        else if (ap[{x, y}] != z)
            band = 1;
    }
    if (band)
    {
        cout << -1 << '\n';
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (sz(grafo[i]) == 0)
            {
                ans++;
                continue;
            }
            times.resize(0);
            act++;
            nods.resize(0);
            tot = 0;
            bucle = -INF;
            imp = 0;
            prof[i] = 0;
            sPar[i] = sImp[i] = 0;
            dfs(i, 0);
            if (!imp)
            {
                act++;
                if(!can(i,0))
                {
                    cout << -1 << '\n';
                    return;
                }
                sort(all(times));
                ll act = 0, ma = 0;
                for (auto k : times)
                {
                    if (k.se == 0)
                        act++;
                    else
                        act--;
                    ma = max(ma, act);
                }
                ans += ma;
            }
            else
            {
                act++;
                cant = 0;
                if (can(in, inX))
                {
                    ans += cant;
                }
                else
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
