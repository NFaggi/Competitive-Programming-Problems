//Link: https://qoj.ac/contest/216/problem/952
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

struct sg
{
    ll cant[2] = {0, 0};
    ll lazy = 0;
};

const int MAXN = 2e5 + 1;
vector<ll> grafo[MAXN], I, D;

vector<sg> seg;

ll ans, cLea[MAXN], up[MAXN], pos = 1, top[MAXN], id[MAXN], act, pot = 1, lvs, ind[MAXN];

ll dfs(ll nod, ll pad)
{
    if (pad != 0)
        ans++;
    if (sz(grafo[nod]) == 1)
    {
        lvs++;
        return 1;
    }
    for (auto k : grafo[nod])
    {
        if (k == pad)
            continue;
        cLea[nod] += dfs(k, nod);
    }
    if (pad != 0 && cLea[nod] % 2 == 0)
        ans++;
    return cLea[nod];
}

bool comp(ll &a, ll &b)
{
    return cLea[a] > cLea[b];
}

void dfs2(ll nod, ll pad)
{
    id[nod] = act++;

    if (sz(grafo[nod]) == 1)
        return;

    if(pad!=0)
    seg[id[nod] + pot].cant[cLea[nod] % 2]++;

    sort(all(grafo[nod]), comp);

    bool band = 1;
    for (auto k : grafo[nod])
    {
        if (k == pad)
            continue;
        if (band)
        {
            top[k] = top[nod];
            dfs2(k, nod);
            band = 0;
        }
        else
        {
            up[k] = nod;
            top[k] = k;
            dfs2(k, nod);
        }
    }
}

ll cal(ll a, ll b, ll nod)
{
    if (I[nod] > b || D[nod] < a)
        return 0;
    if (I[nod] >= a && D[nod] <= b)
        return seg[nod].cant[0] * 2 + seg[nod].cant[1];
    return cal(a, b, nod * 2) + cal(a, b, nod * 2 + 1);
}
ll raiz;
ll calc(ll nod)
{
    ll ret = cal(id[top[nod]] + pot, id[nod] + pot, 1);
    if (top[nod] == raiz)
        return ret;
    return ret + calc(up[top[nod]]);
}

void prop(ll nod)
{
    if (seg[nod].lazy)
    {
        for (ll j = 0; j < 2; j++)
        {
            swap(seg[nod * 2 + j].cant[0], seg[nod * 2 + j].cant[1]);
            seg[nod * 2 + j].lazy = !seg[nod * 2 + j].lazy;
        }
        seg[nod].lazy = 0;
    }
}

void actu(ll nod)
{
    for (ll j = 0; j < 2; j++)
        seg[nod].cant[j] = seg[nod * 2].cant[j] + seg[nod * 2 + 1].cant[j];
}

void upd(ll a, ll b, ll nod)
{
    if (I[nod] > b || D[nod] < a)
        return;
    if (I[nod] >= a && D[nod] <= b)
    {
        ans -= seg[nod].cant[0] * 2 + seg[nod].cant[1];
        swap(seg[nod].cant[0], seg[nod].cant[1]);
        ans += seg[nod].cant[0] * 2 + seg[nod].cant[1];
        seg[nod].lazy = !seg[nod].lazy;
        return;
    }
    prop(nod);
    upd(a, b, nod * 2);
    upd(a, b, nod * 2 + 1);
    actu(nod);
}

void update(ll nod)
{
    upd(id[top[nod]] + pot, id[nod] + pot, 1);
    if (top[nod] != raiz)
        update(up[top[nod]]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, i, q, a, b;
    cin >> n >> q;

    while (pot < n)
        pot *= 2;
    seg.resize(pot * 2);
    I.resize(pot * 2);
    D.resize(pot * 2);

    for (i = pot; i < pot * 2; i++)
        I[i] = D[i] = i;

    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    for (i = 1; i <= n; i++)
        if (sz(grafo[i]) > 1)
        {
            raiz = i;
            break;
        }

    dfs(raiz, 0);

    top[raiz] = raiz;
    dfs2(raiz, 0);

    ll j;
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
        for (j = 0; j < 2; j++)
            seg[i].cant[j] = seg[i * 2].cant[j] + seg[i * 2 + 1].cant[j];
    }
    vector<ll> lea;

    ll d, x;
    while (q--)
    {
        cin >> d;
        for (i = 1; i <= d; i++)
        {
            cin >> x;
            if (sz(grafo[x]) == 1)
                ind[x]++;
            else
            {
                if (ind[x])
                {
                    if (ind[x] % 2 == 0)
                        ans--;
                    ind[x]++;
                    if (ind[x] % 2 == 0)
                        ans++;
                }
                lvs++;
                update(x);
            }
            grafo[x].pb(n + i);
            lea.pb(x);
        }

        if (lvs % 2 == 0)
            cout << ans + d << '\n';
        else
            cout << -1 << '\n';

        while (sz(lea))
        {
            x = lea.back();
            lea.pop_back();
            grafo[x].pop_back();
            if (sz(grafo[x]) == 1)
                ind[x]--;
            else
            {
                if (ind[x])
                {
                    if (ind[x] % 2 == 0)
                        ans--;
                    ind[x]--;
                    if (ind[x] % 2 == 0)
                        ans++;
                }
                update(x);
                lvs--;
            }
        }
    }
    return 0;
}
