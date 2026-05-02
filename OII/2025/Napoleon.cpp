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

ll cruz(ll x1, ll y1, ll x2, ll y2)
{
    return x1 * y2 - y1 * x2;
}

bool bor1(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    return cruz(b.fr - a.fr, b.se - a.se, c.fr - a.fr, c.se - a.se) >= 0;
}
bool bor2(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    return cruz(b.fr - a.fr, b.se - a.se, c.fr - a.fr, c.se - a.se) <= 0;
}

void calc(vector<pair<ll, ll>> &q, ll t, pair<ll, ll> &x)
{
    while (sz(q) > 1)
    {
        if (t == 1)
        {
            if (bor1(q[sz(q) - 2], q.back(), x))
                q.pop_back();
            else
                break;
        }
        else
        {
            if (bor2(q[sz(q) - 2], q.back(), x))
                q.pop_back();
            else
                break;
        }
    }
}

void YES()
{
    cout << "YES\n";
}

void NO()
{
    cout << "NO\n";
}

void solve()
{
    ll n, s, i, x, y;
    cin >> n;
    vector<ll> FE(n), DE(n);
    vector<pair<ll, ll>> pts;
    for (i = 0; i < n; i++)
        cin >> FE[i];
    for (i = 0; i < n; i++)
    {
        cin >> DE[i];
        pts.pb({FE[i], DE[i]});
    }
    sort(all(pts));

    cin >> s;
    vector<vector<ll>> okie(s, vector<ll>(4));
    for (i = 0; i < s; i++)
        cin >> okie[i][0] >> okie[i][1] >> okie[i][2] >> okie[i][3];

    vector<pair<ll, ll>> top, bot;
    top.pb(pts[0]);
    bot.pb(pts[0]);

    for (i = 1; i < n; i++)
    {
        calc(top, 1, pts[i]);
        calc(bot, 2, pts[i]);
        top.pb(pts[i]);
        bot.pb(pts[i]);
    }

    vector<pair<ll, ll>> chu = top;
    reverse(all(bot));
    if (sz(bot) && sz(top) && bot[0] == top.back())
        chu.pop_back();
    if (sz(bot))
        bot.pop_back();
    for (auto k : bot)
        chu.pb(k);

    ll l, r, piv, pos, k, ret, x2, y2, x3, y3;
    bool band;
    for (i = 0; i < s; i++)
    {
        if (okie[i][0] > n)
            NO();
        else
        {
            k = okie[i][1];
            x = okie[i][2];
            y = okie[i][3];
            if (sz(chu) == 1)
            {
                if (x == chu[0].fr * k && y == chu[1].se * k)
                    YES();
                else
                    NO();
                continue;
            }
            else if (sz(chu) == 2)
            {
                ret = cruz(chu[1].fr * k - chu[0].fr * k, chu[1].se * k - chu[0].se * k, x - chu[0].fr * k, y - chu[0].se * k);
                if (ret == 0)
                {
                    if (x >= min(chu[0].fr * k, chu[1].fr * k) && x <= max(chu[0].fr * k, chu[1].fr * k) && y >= min(chu[0].se * k, chu[1].se * k) && y <= max(chu[0].se * k, chu[1].se * k))
                        YES();
                    else
                        NO();
                    continue;
                }
                else
                    NO();
                continue;
            }
            l = 1;
            r = sz(chu) - 1;

            ret = cruz(chu[1].fr * k - chu[0].fr * k, chu[1].se * k - chu[0].se * k, x - chu[0].fr * k, y - chu[0].se * k);

            if (ret > 0)
            {
                NO();
                continue;
            }
            if (ret == 0)
            {
                if (x >= min(chu[0].fr * k, chu[1].fr * k) && x <= max(chu[0].fr * k, chu[1].fr * k) && y >= min(chu[0].se * k, chu[1].se * k) && y <= max(chu[0].se * k, chu[1].se * k))
                    YES();
                else
                    NO();
                continue;
            }
            ret = cruz(chu.back().fr * k - chu[0].fr * k, chu.back().se * k - chu[0].se * k, x - chu[0].fr * k, y - chu[0].se * k);
            if (ret < 0)
            {
                NO();
                continue;
            }
            if (ret == 0)
            {
                if (x >= min(chu[0].fr * k, chu.back().fr * k) && x <= max(chu[0].fr * k, chu.back().fr * k) && y >= min(chu[0].se * k, chu.back().se * k) && y <= max(chu[0].se * k, chu.back().se * k))
                    YES();
                else
                    NO();
                continue;
            }
            pos = r;
            band = 0;
            while (l <= r)
            {
                piv = (l + r) / 2;
                ret = cruz(chu[piv].fr * k - chu[0].fr * k, chu[piv].se * k - chu[0].se * k, x - chu[0].fr * k, y - chu[0].se * k);
                if (ret == 0)
                {
                    band = 1;
                    if (x >= min(chu[0].fr * k, chu[piv].fr * k) && x <= max(chu[0].fr * k, chu[piv].fr * k) && y >= min(chu[0].se * k, chu[piv].se * k) && y <= max(chu[0].se * k, chu[piv].se * k))
                        YES();
                    else
                        NO();
                    break;
                }
                else if (ret > 0)
                {
                    pos = piv;
                    r = piv - 1;
                }
                else
                    l = piv + 1;
            }
            if (band)
                continue;
            ret = cruz(chu[pos].fr * k - chu[pos - 1].fr * k, chu[pos].se * k - chu[pos - 1].se * k, x - chu[pos - 1].fr * k, y - chu[pos - 1].se * k);
            if (ret > 0)
                NO();
            else
                YES();
        }
    }
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
