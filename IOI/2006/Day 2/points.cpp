//Link: https://juez.oia.unsam.edu.ar/tasks/ioi.2006.day2.points
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
#define fore(i, a, b) for (i = (a); i <= (b); i++)
using namespace std;

const ll INF = 1e18;

ll cruz(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.fr * b.se - a.se * b.fr;
}

ll cru(vector<ll> &a, vector<ll> &b, vector<ll> &c)
{
    pair<ll, ll> A, B;
    A = {a[0] - c[0], a[1] - c[1]};
    B = {b[0] - c[0], b[1] - c[1]};
    return cruz(A, B) > 0;
}

vector<vector<ll>> ans;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<ll>> gs, rs;

void calc(vector<ll> a, vector<ll> b, vector<ll> c, vector<vector<ll>> g, vector<vector<ll>> r)
{
    if (sz(g) == 0 && sz(r) == 0)
        return;
    ll cant = a[3] + b[3] + c[3], i;
    vector<ll> d;

    auto tri = [&](vector<ll> &A, vector<ll> &B, vector<ll> &C)
    {
        gs.resize(0);
        rs.resize(0);
        for (auto &k : g)
            if (cru(A, k, C) != cru(B, k, C) && cru(A, C, B) == cru(A, k, B) && cru(A, B, C) == cru(A, k, C) && cru(B, C, A) == cru(B, k, A))
                gs.pb(k);

        for (auto &k : r)
            if (cru(A, k, C) != cru(B, k, C) && cru(A, C, B) == cru(A, k, B) && cru(A, B, C) == cru(A, k, C) && cru(B, C, A) == cru(B, k, A))
                rs.pb(k);
    };

    if (cant == 1)
    {
        if (sz(r) == 0)
        {
            if (b[3] == 1)
                swap(a, b);
            for (auto k : g)
                ans.pb({b[2], k[2], 0});
            return;
        }

        i = rng() % sz(r);

        d = r[i];
        d.pb(1);
        r.erase(r.begin() + i);

        if (a[3])
            ans.pb({a[2], d[2], 1});
        if (b[3])
            ans.pb({b[2], d[2], 1});
        if (c[3])
            ans.pb({c[2], d[2], 1});
    }
    else
    {
        if (sz(g) == 0)
        {
            if (b[3] == 0)
                swap(a, b);
            for (auto k : r)
                ans.pb({b[2], k[2], 1});
            return;
        }

        i = rng() % sz(g);

        d = g[i];
        d.pb(0);
        g.erase(g.begin() + i);

        if (!a[3])
            ans.pb({a[2], d[2], 0});
        if (!b[3])
            ans.pb({b[2], d[2], 0});
        if (!c[3])
            ans.pb({c[2], d[2], 0});
    }

    // abi

    tri(a, b, d);

    calc(a, b, d, gs, rs);

    // bci

    tri(b, c, d);

    calc(b, c, d, gs, rs);

    // aci

    tri(a, c, d);

    calc(a, c, d, gs, rs);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, i, m, maX = 0, maY = 0, miX = INF, miY = INF;
    cin >> n;
    vector<vector<ll>> g(n, vector<ll>(3));
    fore(i, 0, n - 1)
    {
        cin >> g[i][0] >> g[i][1];
        g[i][2] = i;
    }

    cin >> m;
    vector<vector<ll>> r(m, vector<ll>(3));

    fore(i, 0, m - 1)
    {
        cin >> r[i][0] >> r[i][1];
        r[i][2] = i;
    }

    vector<ll> a, b, c, d;

    for (auto k : g)
    {
        maX = max(maX, k[0]);
        maY = max(maY, k[1]);
    }

    for (auto k : r)
    {
        miX = min(miX, k[0]);
        miY = min(miY, k[1]);
    }

    vector<vector<ll>> gf, rf;

    for (auto k : g)
    {
        if (k[0] == maX || k[1] == maY)
        {
            if (k[0] == maX && k[1] == maY)
                b = k;
            else
                a = k;
            a.pb(0);
            b.pb(0);
        }
        else
            gf.pb(k);
    }

    for (auto k : r)
    {
        if (k[0] == miX || k[1] == miY)
        {
            if (k[0] == miX && k[1] == miY)
                d = k;
            else
                c = k;
            d.pb(1);
            c.pb(1);
        }
        else
            rf.pb(k);
    }

    vector<vector<ll>> gi, ri, gd, rd;
    pair<ll, ll> A, B;
    for (auto k : gf)
    {
        A = {b[0] - d[0], b[1] - d[1]};
        B = {k[0] - d[0], k[1] - d[1]};
        if (cruz(A, B) > 0)
            gi.pb(k);
        else
            gd.pb(k);
    }

    for (auto k : rf)
    {
        A = {b[0] - d[0], b[1] - d[1]};
        B = {k[0] - d[0], k[1] - d[1]};
        if (cruz(A, B) > 0)
            ri.pb(k);
        else
            rd.pb(k);
    }

    ans.pb({a[2], b[2], 0});
    ans.pb({c[2], d[2], 1});

    calc(a, b, d, gi, ri);
    calc(b, d, c, gd, rd);
    for (auto k : ans)
    {
        cout << k[0] + 1 << ' ' << k[1] + 1 << ' ';
        if (k[2] == 0)
            cout << "g\n";
        else
            cout << "r\n";
    }
    return 0;
}
