//Link: https://www.spoj.com/problems/SAMER08I/
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

const int MAXN = 501;

vector<ll> col[MAXN];
vector<vector<ll>> grafo[MAXN];
bool par, vis[MAXN];
ll c, id[MAXN], cant, prob;

void dfs(ll nod)
{
    vis[nod] = 1;
    cant += sz(grafo[nod]);
    for (auto k : grafo[nod])
    {
        if (k[1] == prob)
            cant--;
        if (k[1] == prob || vis[k[0]])
            continue;
        dfs(k[0]);
    }
}

bool euler(ll nod)
{
    ll i, ma1 = 0;
    for (i = 0; i < c; i++)
        vis[i] = 0;
    for (i = 0; i < c; i++)
    {
        if (vis[i])
            continue;
        cant = 0;
        dfs(i);
        if (cant > 0)
            ma1++;
    }
    if (ma1 > 1)
        return 0;
    cant = 0;
    ll ma0 = 0;
    for (i = 0; i < c; i++)
    {
        if (id[i] % 2 != 0)
            cant++;
        if (id[i]>0)
            ma0++;
    }
    if(id[nod]==0&&ma0!=0)
        return 0;
    if (par)
        return 1;
    if (cant != 2 && cant != 0)
        return 0;
    if (cant == 0)
        return 1;
    if (id[nod] % 2 == 1)
        return 1;
    return 0;
}

void solve()
{
    ll n, i, x, a, j;
    par = 1;
    cin >> n >> c;
    if (n == 0 && c == 0)
        exit(0);
    memset(id, 0, sizeof(id));
    for (i = 0; i < n; i++)
        col[i].resize(0);
    for (i = 0; i < c; i++)
        grafo[i].resize(0);

    for (i = 0; i < c; i++)
    {
        cin >> x;
        for (j = 0; j < x; j++)
        {
            cin >> a;
            col[a].pb(i);
        }
    }

    for (i = 0; i < n; i++)
    {
        id[col[i][0]]++;
        id[col[i].back()]++;
        grafo[col[i][0]].pb({col[i].back(), i});
        grafo[col[i].back()].pb({col[i][0], i});
    }

    for (i = 0; i < c; i++)
        if (id[i] % 2 != 0)
            par = 0;

    for (i = 0; i < n; i++)
    {
        id[col[i][0]]--;
        id[col[i].back()]--;
        prob = i;
        if (euler(col[i][0]))
        {
            cout << i << '\n';
            return;
        }

        if (euler(col[i].back()))
        {
            cout << i << '\n';
            return;
        }
        id[col[i][0]]++;
        id[col[i].back()]++;
    }
    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
        solve();
    return 0;
}
