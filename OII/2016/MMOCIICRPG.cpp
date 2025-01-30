//Score: 100/100
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

const int MAXM = 2e5 + 1;
const int MAXP = 2097153;

ll val[MAXM], pos[MAXM], seg[MAXP], seg2[MAXP], I[MAXP], D[MAXP], act[MAXM], ans[MAXM], maps[MAXM], pot = 1, mi, ma, piv, posi, m;
vector<ll>grafo[MAXM];
vector<pair<ll, ll>>qs[MAXM];
vector<pair<ll, ll>>ms;

void update(ll nod, ll x)
{
    while (nod > 0)
    {
        seg[nod] += x;
        nod /= 2;
    }
}

void update2(ll nod, ll x)
{
    while (nod > 0)
    {
        seg2[nod] += x;
        nod /= 2;
    }
}

ll calc(ll a, ll b, ll nod)
{
    if (I[nod] > b || D[nod] < a)
        return 0;
    if (I[nod] >= a && D[nod] <= b)
        return seg[nod];
    return calc(a, b, nod * 2) + calc(a, b, nod * 2 + 1);
}

ll cantCalc(ll a, ll b, ll nod)
{
    if (I[nod] > b || D[nod] < a)
        return 0;
    if (I[nod] >= a && D[nod] <= b)
        return seg2[nod];
    return cantCalc(a, b, nod * 2) + cantCalc(a, b, nod * 2 + 1);
}
void dfs(ll nod, ll pad)
{
    ll i;
    if (nod!=1&&act[maps[nod]] == 0)
    {
        update(pos[maps[nod]] + pot, val[maps[nod]]);
        update2(pos[maps[nod]] + pot, 1);
    }
    if(nod != 1)
        act[maps[nod]]++;
    for (i = 0; i < sz(qs[nod]); i++)
    {
        mi = 0; ma = m - 1;
        posi = -1;
        while (mi <= ma)
        {
            piv = (mi + ma) / 2;
            if (ms[piv].first < qs[nod][i].first)
                mi = piv + 1;
            else
            {
                ma = piv - 1;
                if (posi != -1)
                    posi = min(posi, piv);
                else
                    posi = piv;
            }
        }
        if (posi != -1)
            ans[qs[nod][i].second] = calc(pot + posi, pot * 2 - 1, 1) - qs[nod][i].first * cantCalc(pot + posi, pot * 2 - 1, 1);
        else
            ans[qs[nod][i].second] = 0;
    }
    for (auto k : grafo[nod])
        if (k != pad)
            dfs(k, nod);
    if (nod != 1)
    {
        act[maps[nod]]--;
        if (act[maps[nod]] == 0)
        {
            update(pos[maps[nod]] + pot, -val[maps[nod]]);
            update2(pos[maps[nod]] + pot, -1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, x, p, mi, t, k;
    cin >> n >> m >> q;
    ms.resize(m);
    for (i = 0; i < m; i++)
    {
        cin >> x;
        ms[i] = { x,i };
        val[i] = x;
    }
    sort(all(ms));
    for (i = 0; i < m; i++)
        pos[ms[i].second] = i;

    while (pot < m)
        pot *= 2;
    for (i = pot; i < pot * 2; i++)
    {
        I[i] = i;
        D[i] = i;
    }
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
    }

    for (i = 2; i <= n; i++)
    {
        cin >> p >> mi;
        grafo[i].pb(p);
        grafo[p].pb(i);
        maps[i] = mi-1;
    }

    for (i = 0; i < q; i++)
    {
        cin >> t >> k;
        qs[t].pb({ k,i });
    }
    dfs(1, 0);

    for (i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}

