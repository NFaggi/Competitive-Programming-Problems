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
const int SQ = 317;
vector<ll> grafo[MAXN];
ll a[MAXN], p[MAXN], depth[MAXN], id[MAXN], act[MAXN];

vector<vector<ll>> memo[MAXN];

ll cons(ll x, ll y, ll z = -1)
{
    if (x == 0)
        return 0;
    if (x > y)
        swap(x, y);

    if (z != -1)
    {
        if (act[depth[x]] > SQ)
            return 0;
        memo[depth[x]][id[x]][id[y]] = z;
        return 0;
    }
    if (act[depth[x]] > SQ)
        return cons(p[x], p[y]) + a[x] * a[y];
    if(memo[depth[x]][id[x]][id[y]]==0)
        memo[depth[x]][id[x]][id[y]]=cons(p[x],p[y])+a[x]*a[y];
    return memo[depth[x]][id[x]][id[y]];
}

void dfs(ll nod)
{
    id[nod] = act[depth[nod]]++;
    for (auto k : grafo[nod])
    {
        depth[k] = depth[nod] + 1;
        dfs(k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, q, x, y, ans, ret;
    cin >> n >> q;

    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 2; i <= n; i++)
    {
        cin >> p[i];
        grafo[p[i]].pb(i);
    }
    dfs(1);

    for(i=0; i<=n; i++)
    {
        if(act[i]<=SQ)
            memo[i].resize(act[i],vector<ll>(act[i],0));
    }

    while (q--)
    {
        cin >> x >> y;
        ret = cons(x, y);

        cout << ret << '\n';
    }
    return 0;
}
