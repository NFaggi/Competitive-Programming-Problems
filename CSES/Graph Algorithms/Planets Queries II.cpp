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
 
const int MAXN = 2e5 + 1;
const int LOG = 20;
 
ll up[MAXN][LOG], comp[MAXN], act=1, fin, cic[MAXN], pos, sArb[MAXN], prof[MAXN], tamC[MAXN];
bool vis[MAXN];
vector<ll> grafo[MAXN], cicl;
pair<ll, ll> disC[MAXN];
void dfs(ll nod)
{
    if (vis[nod])
    {
        pos = 1;
        fin=nod;
        return;
    }
    vis[nod] = 1;
    dfs(up[nod][0]);
    if (fin != -1)
    {
        cic[nod] = pos++;
        cicl.pb(nod);
    }
    if (fin == nod)
        fin = -1;
}
 
void subArb(ll sA, ll nod)
{
    sArb[nod] = sA;
    vis[nod]=1;
    for (auto k : grafo[nod])
    {
        prof[k] = prof[nod] + 1;
        disC[k] = disC[nod];
        disC[k].fr++;
        comp[k]=comp[nod];
        subArb(sA, k);
    }
}
 
void calc(ll nod)
{
    ll sub = 0;
    comp[nod] = act;
    fin = -1;
    cicl.resize(0);
    dfs(nod);
    tamC[act] = sz(cicl);
    for (auto k : cicl)
    {
        comp[k]=act;
        for (auto l : grafo[k])
        {
            if (cic[l])
                continue;
            comp[l]=act;
            sub++;
            prof[l] = 1;
            disC[l] = {1, k};
            subArb(sub,l);
        }
    }
    act++;
}
 
ll cPad(ll nod, ll k)
{
    ll i;
    for (i = LOG - 1; i >= 0; i--)
        if ((1 << i) & k)
            nod = up[nod][i];
    return nod;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, j, a, b, c;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        cin >> up[i][0];
        grafo[up[i][0]].pb(i);
    }
 
    for (i = 1; i < LOG; i++)
        for (j = 1; j <= n; j++)
            up[j][i] = up[up[j][i - 1]][i - 1];
 
    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
            calc(i);
    }
 
    while (q--)
    {
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << '\n';
            continue;
        }
        if (comp[a] != comp[b])
        {
            cout << -1 << '\n';
            continue;
        }
        if (cic[b])
        {
            ll aum = 0;
 
            if (!cic[a])
            {
                aum = disC[a].fr;
                a = disC[a].se;
            }
            if (cic[a] < cic[b])
            {
                cout << cic[a] + tamC[comp[a]] - cic[b] + aum << '\n';
                continue;
            }
            else
            {
                cout << cic[a] - cic[b] + aum << '\n';
                continue;
            }
        }
        else if (cic[a])
        {
            cout << -1 << '\n';
            continue;
        }
        else
        {
            if (sArb[a] != sArb[b])
            {
                cout << -1 << '\n';
                continue;
            }
            if (prof[a] <= prof[b])
            {
                cout << -1 << '\n';
                continue;
            }
            c = cPad(a, prof[a] - prof[b]);
            if (c != b)
            {
                cout << -1 << '\n';
                continue;
            }
            cout << prof[a] - prof[b] << '\n';
            continue;
        }
    }
    return 0;
}
