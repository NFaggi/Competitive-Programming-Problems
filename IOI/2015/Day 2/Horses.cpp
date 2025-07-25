//Link: https://ioi.contest.codeforces.com/group/32KGsXgiKA/contest/103770/problem/D
//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define fr first
#define se second
#define pb push_back
using namespace std;

vector<ll> x, y, seg, I, D, seg2;
ll n, pot = 1;
const int MOD = 1e9 + 7;

void update(ll nod, ll x)
{
    seg[nod] = x;
    nod /= 2;
    while (nod > 0)
    {
        seg[nod] = max(seg[nod * 2], seg[nod * 2 + 1]);
        nod /= 2;
    }
}

ll cSeg(ll a, ll b, ll nod)
{
    if (I[nod] > b || D[nod] < a)
        return 0;
    if (I[nod] >= a && D[nod] <= b)
        return seg[nod];
    return max(cSeg(a, b, nod * 2), cSeg(a, b, nod * 2 + 1));
}

void update2(ll nod, ll x)
{
    seg2[nod] = x;
    nod /= 2;
    while (nod > 0)
    {
        seg2[nod] = (1ll * seg2[nod * 2] * seg2[nod * 2 + 1]) % MOD;
        nod /= 2;
    }
}

ll cSeg2(ll l, ll r, ll nod)
{
    ll L = 1, R = 1;
    while (l <= r)
    {
        if (l == r)
        {
            L = (1ll*L*seg2[l])%MOD;
            break;
        }
        if (l % 2 != 0)
        {
            L = (1ll*L*seg2[l])%MOD;
            l++;
        }
        if (r % 2 == 0)
        {
            R = (1ll*R*seg2[r])%MOD;
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return (1ll*L*R)%MOD;
}
set<ll> s;
ll tim = 0;
vector<pair<ll, ll>> dp;
ll calc()
{
    tim++;
    ll i, band, cant = 1, ans = 0, j, num, ma = 0, cont = 0, sup = 0, ret = 1, kkk;
    if (sz(s) == 0)
        return cSeg(pot, pot * 2 - 1, 1);
    auto it = s.end();
    it--;
    while (it != s.begin() && ret < 31)
    {
        it--;
        ret++;
    }

    while (it != s.end())
    {
        cant = cSeg2(pot, pot + *it, 1);

        band = 0;
        auto it2 = it;
        it2++;
        if (dp[*it].first != tim)
        {
            dp[*it].second = cSeg(*it + pot, pot * 2 - 1, 1);
            dp[*it].first = tim;
        }
        num = dp[*it].second;

        while (it2 != s.end())
        {
            num = num / x[*it2];
            if (dp[*it2].first != tim)
            {
                dp[*it2].second = cSeg(*it2 + pot, pot * 2 - 1, 1);
                dp[*it2].first = tim;
            }

            kkk = dp[*it2].second;
            if (num < kkk)
            {
                band = 1;
                break;
            }
            it2++;
        }
        if (band)
        {
            it++;
            continue;
        }
        if (dp[*it].first != tim)
        {
            dp[*it].second = cSeg(*it + pot, pot * 2 - 1, 1);
            dp[*it].first = tim;
        }
        ans = (1ll * cant * dp[*it].second) % MOD;
        it++;
        return ans;
    }
    return cSeg(pot, pot * 2 - 1, 1);
}

int init(int N, int X[], int Y[])
{
    ll i;
    n = N;
    x.resize(N);
    y.resize(N);
    s.insert(0);
    dp.resize(N, {0, 0});
    for (i = 0; i < n; i++)
    {
        x[i] = X[i];
        y[i] = Y[i];
        if (x[i] != 1)
            s.insert(i);
    }
    while (pot < n)
        pot *= 2;
    seg.resize(pot * 2, 0);
    seg2.resize(pot * 2, 1);
    I.resize(pot * 2);
    D.resize(pot * 2);
    for (i = 0; i < n; i++)
    {
        seg[i + pot] = y[i];
        seg2[i + pot] = x[i];
    }
    for (i = pot; i < pot * 2; i++)
        I[i] = D[i] = i;
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
        seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
        seg2[i] = (1ll * seg2[i * 2] * seg2[i * 2 + 1]) % MOD;
    }
    return calc();
}
int updateX(int pos, int val)
{
    ll i;
    x[pos] = val;
    update2(pos + pot, val);
    if (val == 1 && pos > 0)
    {
        auto it = s.find(pos);
        if (it != s.end())
            s.erase(it);
    }
    else
        s.insert(pos);
    return calc();
}
int updateY(int pos, int val)
{
    ll i;
    y[pos] = val;
    update(pos + pot, val);
    return calc();
}
