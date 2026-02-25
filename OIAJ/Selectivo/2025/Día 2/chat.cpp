//Link: https://juez.oia.unsam.edu.ar/task/174
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

const int MAXN = 3001;
const int MOD = 1e9 + 7;

vector<ll> grafo[MAXN];
ll id[MAXN], ways[MAXN], tam[MAXN], fact[MAXN], invFact[MAXN], sig[MAXN], sig2[MAXN], dpA[MAXN], n, newDPA[MAXN], B2, dpB[MAXN], depth[MAXN];

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % MOD;
    ll ans = binpow(a, b / 2);
    ans = (ans * ans) % MOD;
    if (b % 2 != 0)
        ans = (ans * (a % MOD)) % MOD;
    return ans % MOD;
}

ll inv(ll a)
{
    return binpow(a, MOD - 2) % MOD;
}

void init()
{
    fact[0] = 1;
    invFact[0] = inv(fact[0]);
    for (ll i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = inv(fact[i]);
    }
}

void prof(ll nod)
{
    for (auto k : grafo[nod])
    {
        depth[k] = depth[nod] + 1;
        prof(k);
    }
}

ll comb, a;
ll dfs(ll nod)
{
    ways[nod] = 1;
    tam[nod] = 1;
    for (auto k : grafo[nod])
    {
        sig[nod] |= dfs(k);
        comb = (fact[tam[nod] - 1 + tam[k]] * invFact[tam[k]]) % MOD;
        comb = (comb * invFact[tam[nod] - 1]) % MOD;

        ways[nod] = (ways[nod] * ways[k]) % MOD;
        ways[nod] = (ways[nod] * comb) % MOD;

        tam[nod] += tam[k];
    }
    if (sig[nod] || nod == a)
        return nod + 1;
    return 0;
}
ll dfs2(ll nod)
{
    if (nod == B2)
        return nod + 1;
    for (auto k : grafo[nod])
    {
        sig2[nod] |= dfs2(k);
    }
    if (sig2[nod])
        return nod + 1;
    return 0;
}
ll i, j, ta, way, bef, aft, x, y, lca;

void taWay(ll nod, ll si = -1)
{
    for (auto k : grafo[nod])
    {
        if (k == sig[nod] - 1 || k == si)
            continue;

        comb = (fact[ta + tam[k]] * invFact[tam[k]]) % MOD;
        comb = (comb * invFact[ta]) % MOD;

        way = (way * ways[k]) % MOD;
        way = (way * comb) % MOD;

        ta += tam[k];
    }
}

void calc(ll nod)
{
    if (nod == a)
    {
        dpA[0] = ways[nod];
        return;
    }
    if (sig[nod] && sig2[nod])
        lca = nod;
    calc(sig[nod] - 1);
    if (sig2[nod])
        return;
    ta = 0;
    way = 1;
    taWay(nod);

    for (i = 0; i < tam[sig[nod] - 1]; i++)
    {
        x = (tam[sig[nod] - 1] - 1) - i;
        for (j = 0; j <= ta; j++)
        {
            bef = (fact[i + j] * invFact[j]) % MOD;
            bef = (bef * invFact[i]) % MOD;

            y = ta - j;
            aft = (fact[x + y] * invFact[y]) % MOD;
            aft = (aft * invFact[x]) % MOD;

            comb = (dpA[i] * way) % MOD;
            comb = (comb * bef) % MOD;
            comb = (comb * aft) % MOD;

            newDPA[i + j + 1] = (newDPA[i + j + 1] + comb) % MOD;
        }
    }
    swap(dpA, newDPA);

    for (i = 0; i < n; i++)
        newDPA[i] = 0;
}
bool vis[MAXN];
bool can(ll nod)
{
    vis[nod] = 1;
    for (auto k : grafo[nod])
    {
        if (vis[k])
            return 0;
        if (!can(k))
            return 0;
    }
    return 1;
}

int chat(int A, int B, vector<int> &C)
{
    a = C[B];
    n = sz(C);
    init();
    B2 = B;
    for (i = 0; i < n; i++)
    {
        if (i == B)
            continue;
        if (C[i] == -1)
        {
            C[i] = n;
            continue;
        }
        grafo[C[i]].pb(i);
        id[i]++;
    }
    for (i = 0; i < n; i++)
    {
        if (i == B || id[i])
            continue;
        grafo[n].pb(i);
    }
    memset(vis, 0, sizeof(vis));
    if (!can(n))
        return 0;
    prof(n);
    if (depth[A] >= depth[C[B]])
        grafo[A].pb(B);
    else
    {
        grafo[C[B]].pb(B);
        a = A;
    }
    id[B]++;
    memset(vis, 0, sizeof(vis));
    can(n);
    for (i = 0; i < n; i++)
        if (!vis[i])
            return 0;
    memset(vis, 0, sizeof(vis));
    can(B);
    dfs(n);
    set<ll> pads;
    pads.insert(n);
    ll nod = A;
    if (a == A)
        nod = C[B];
    while (nod != n)
    {
        pads.insert(nod);
        nod = C[nod];
    }
    auto it = pads.find(C[B]);
    if (a == A)
        it = pads.find(A);
    if (C[B] == -1 || it != pads.end())
        return ways[n];

    if (vis[C[B]] || vis[A])
        return 0;

    dfs2(n);
    calc(n);
    swap(sig, sig2);
    swap(dpA, dpB);

    swap(a, B2);
    calc(n);
    swap(a, B2);
    swap(dpA, dpB);
    swap(sig, sig2);
    ll k, away = 0, ata = tam[sig[lca] - 1] + tam[sig2[lca] - 1], aux = 0;
    for (i = tam[sig[lca] - 1] - 1; i >= 0; i--)
    {
        for (j = 0; j < tam[sig2[lca] - 1]; j++)
        {
            if (!dpB[j])
                continue;
            x = tam[sig2[lca] - 1] - 1 - j;
            k = i + 1;

            bef = (fact[k + j] * invFact[k]) % MOD;
            bef = (bef * invFact[j]) % MOD;

            y = tam[sig[lca] - 1] - k;
            aft = (fact[x + y] * invFact[x]) % MOD;
            aft = (aft * invFact[y]) % MOD;

            comb = (dpB[j]) % MOD;
            comb = (comb * bef) % MOD;
            comb = (comb * aft) % MOD;

            aux = (aux + comb) % MOD;
        }
        way = away = (away + (aux * dpA[i]) % MOD) % MOD;
    }

    while (true)
    {
        ta = 0;
        way = 1;
        taWay(lca, sig2[lca] - 1);

        comb = (fact[ta + ata] * invFact[ta]) % MOD;
        comb = (comb * invFact[ata]) % MOD;

        way = (way * away) % MOD;
        way = (way * comb) % MOD;

        away = way;
        ata = ta + 1 + ata;
        if (lca == n)
            break;
        lca = C[lca];
    }
    return way;
}
