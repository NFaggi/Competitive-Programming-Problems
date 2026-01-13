//Link: https://codeforces.com/gym/104491/problem/H
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

const int MAXN = 2e5 + 10;
const int LOG = 20;
const int MOD = 998244353;
vector<ll> grafo[MAXN], gC[MAXN * 2];
set<ll> comps[MAXN], nodsC[MAXN];
ll vis[MAXN*2], low[MAXN], PA[MAXN], act, comp = 1, id[MAXN * 2], up[MAXN * 2][LOG], sum[MAXN * 2][LOG], dis[MAXN * 2][LOG], depth[MAXN * 2], fact[MAXN], invFact[MAXN];
stack<pair<ll, ll>> p;
void DFS(ll nod, ll pad)
{
    ll hijos = 0;
    vis[nod] = ++act;
    low[nod] = vis[nod];
    for (auto k : grafo[nod])
    {
        if (vis[k] == 0)
        {
            p.push({nod, k});
            hijos++;
            DFS(k, nod);
            low[nod] = min(low[nod], low[k]);
            if ((hijos > 1 && pad == 0) || (pad != 0 && low[k] >= vis[nod]))
            {
                PA[nod] = 1;
                while (p.top() != make_pair(nod, k))
                {
                    comps[p.top().first].insert(comp);
                    comps[p.top().second].insert(comp);
                    nodsC[comp].insert(p.top().first);
                    nodsC[comp].insert(p.top().second);
                    p.pop();
                }
                comps[p.top().first].insert(comp);
                comps[p.top().second].insert(comp);
                nodsC[comp].insert(p.top().first);
                nodsC[comp].insert(p.top().second);
                p.pop();
                comp++;
            }
        }
        else if (k != pad)
        {
            if (vis[k] < vis[nod])
                p.push({nod, k});
            low[nod] = min(low[nod], vis[k]);
        }
    }
}
void dfs(ll nod, ll pad)
{
    vis[nod]=1;
    up[nod][0] = pad;
    if (pad > MAXN)
        dis[nod][0] = 1;
    else if (sz(nodsC[pad]) > 2)
        sum[nod][0] = 1;
    for (ll i = 1; i < LOG; i++)
    {
        up[nod][i] = up[up[nod][i - 1]][i - 1];
        dis[nod][i] = dis[nod][i - 1] + dis[up[nod][i - 1]][i - 1];
        sum[nod][i] = sum[nod][i - 1] + sum[up[nod][i - 1]][i - 1];
    }
    for (auto k : gC[nod])
    {
        if (k == pad)
            continue;
        depth[k] = depth[nod] + 1;
        dfs(k, nod);
    }
}

ll k_ans(ll x, ll k)
{
    for (ll i = 0; i < LOG; i++)
    {
        if ((1 << i) & k)
            x = up[x][i];
    }
    return x;
}

ll lca(ll a, ll b)
{
    if (a == b)
        return a;
    if (depth[a] < depth[b])
        swap(a, b);
    a = k_ans(a, depth[a] - depth[b]);
    if (a == b)
        return a;
    for (ll i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

pair<ll, ll> calc(ll a, ll c)
{
    ll k = depth[a] - depth[c], i;
    pair<ll, ll> ret = {0, 0};
    if (a <= MAXN)
        ret.se = 1;
    for (i = 0; i < LOG; i++)
    {
        if ((1 << i) & k)
        {
            ret.fr += dis[a][i];
            ret.se += sum[a][i];
            a = up[a][i];
        }
    }
    return ret;
}

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % MOD;
    ll ans = binpow(a, b / 2);
    ans = (ans * ans) % MOD;
    if (b % 2 != 0)
        ans = (ans * (a) % MOD) % MOD;
    return ans;
}

ll inv(ll x)
{
    return binpow(x, MOD - 2);
}

void facts()
{
    fact[0] = 1;
    invFact[0] = inv(fact[0]);
    for (ll i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i)%MOD;
        invFact[i] = inv(fact[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, a, b;
    cin >> n >> m;
    facts();
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            DFS(i, 0);
            if (!p.empty())
            {
                while (!p.empty())
                {
                    comps[p.top().first].insert(comp);
                    comps[p.top().second].insert(comp);
                    nodsC[comp].insert(p.top().first);
                    nodsC[comp].insert(p.top().second);
                    p.pop();
                }
                comp++;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (auto k : comps[i])
        {
            gC[k].pb(i + MAXN);
            gC[i + MAXN].pb(k);
        }
    }
    memset(vis,0,sizeof(vis));
    for(i=1; i<=n; i++)
    {
        if(!vis[i+MAXN])
            dfs(i+MAXN, 0);
    }
    ll q, c, k, num, den, f1, f2;
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> k;
        if (a == b)
        {
            if (k == 0)
            {
                cout << "1\n";
                continue;
            }
            else
            {
                cout << "0\n";
                continue;
            }
        }
        a = a + MAXN;
        b = b + MAXN;
        c = lca(a, b);
        pair<ll, ll> A = calc(a, c), B = calc(b, c), C;
        C = A;
        C.fr += B.fr;
        C.se += B.se;
        if (c <= MAXN)
        {
            C.fr++;
            if(sz(nodsC[c])>2)
                C.se--;
        }
        if (C.fr > k || C.fr + C.se < k)
            cout << "0\n";
        else
        {
            num = fact[C.se];
            f1 = k - C.fr;
            f2 = invFact[C.se - f1];
            f1 = invFact[f1];
            num = (num * f1) % MOD;
            num = (num * f2) % MOD;
            cout << num << '\n';
        }
    }
    return 0;
}
