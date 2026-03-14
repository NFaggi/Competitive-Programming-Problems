//Link: https://oj.uz/problem/view/IOI16_aliens
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

const int MAXN = 1e5 + 1;
const int LOG = 45;

ll L[MAXN], R[MAXN], p[MAXN][LOG];
vector<vector<ll>> dp;

vector<vector<ll>> q[LOG];

__int128 IL, IR;

ll cons(ll x, ll i, ll k)
{
    IL = 1;
    IR = 1;
    if (i > 0)
    {
        IL = IL * (q[k][i][1] - q[k][i - 1][1]);
        IR = IR * x * (q[k][i - 1][0] - q[k][i][0]);
    }
    if (i > 0 && IL > IR)
        return -1;
    IL = 1;
    IR = 1;
    if (i + 1 < sz(q[k]))
    {
        IL = IL * (q[k][i + 1][1] - q[k][i][1]);
        IR = IR * x * (q[k][i][0] - q[k][i + 1][0]);
    }
    if (i + 1 < sz(q[k]) && IL < IR)
        return 1;
    return 0;
}

ll query(ll x, ll k)
{
    ll l = 0, r = sz(q[k]) - 1, piv, ret, pos=-1;
    while (l <= r)
    {
        piv = (l + r) / 2;
        ret = cons(x, piv, k);
        if (ret == 0)
        {
            pos=piv;
            r=piv-1;
        }
        else if (ret == -1)
            r = piv - 1;
        else
            l = piv + 1;
    }
    return pos;
}

bool del(vector<ll> &a, vector<ll> &b, vector<ll> &c)
{
    IL = 1;
    IR = 1;
    IL = IL * (c[1] - a[1]) * (a[0] - b[0]);
    IR = IR * (b[1] - a[1]) * (a[0] - c[0]);
    return IL <= IR;
}

void inser(vector<ll> a, ll k)
{
    if (sz(q[k]) && q[k].back()[0] == a[0] && q[k].back()[1] == a[1])
    {
        q[k].pb(a);
        return;
    }
    while (sz(q[k]) > 1 && del(q[k][sz(q[k]) - 2], q[k].back(), a))
        q[k].pop_back();
    q[k].pb(a);
}

bool comp(vector<ll> &a, vector<ll> &b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    return a[1] > b[1];
}

long long take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c)
{
    dp.resize(n + 1, vector<ll>(LOG));
    ll i, j, res, ret, ma = -1;
    vector<ll> a;
    vector<vector<ll>> ord, v;
    for (i = 0; i < n; i++)
        ord.pb({min(r[i], c[i]), max(r[i], c[i]), i});
    sort(all(ord), comp);

    for (i = 0; i < n; i++)
    {
        if (ma < ord[i][1])
        {
            ma = ord[i][1];
            v.pb(ord[i]);
        }
    }
    swap(v, ord);
    n = sz(ord);
    for (i = 0; i < n; i++)
    {
        L[i] = ord[i][0];
        R[i] = ord[i][1];
    }
    ll l = 0, de = 1ll * m * m, C, solo, mi = LLONG_MAX, pos = 0;
    j = 0;
    while (l <= de)
    {
        C = (l + de) / 2;
        for (i = 1; i <= n; i++)
        {
            solo = (R[i - 1] - L[0] + 1) * (R[i - 1] - L[0] + 1) + C;

            ret = query(R[i - 1], j);
            if (ret == -1)
            {
                dp[i][j] = (R[i - 1] - L[i - 1]) + 1;
                dp[i][j] = dp[i][j] * dp[i][j] + C;
                p[i][j] = 1;
            }
            else
            {
                a = q[j][ret];
                p[i][j] = a[2] + 1;
                dp[i][j] = R[i - 1] * R[i - 1] + a[0] * R[i - 1] + a[1] + C;
            }
            if (solo <= dp[i][j])
            {
                p[i][j] = 1;
                dp[i][j] = solo;
            }
            if (i < n)
            {
                res = max(0ll, R[i - 1] - L[i] + 1);
                inser({-2 * (L[i] - 1), dp[i][j] + (L[i] - 1) * (L[i] - 1) - (res * res), p[i][j]}, j);
            }
        }
        if (p[n][j] <= k)
        {
            mi = dp[n][j] - C * k;
            de = C - 1;
            pos = C;
        }
        else
            l = C + 1;
        j++;
    }
    return mi;
}
