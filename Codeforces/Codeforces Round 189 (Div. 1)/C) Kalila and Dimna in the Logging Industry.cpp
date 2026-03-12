//Link: https://codeforces.com/problemset/problem/319/C
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

ll a[MAXN], b[MAXN], dp[MAXN];

vector<ll> q;
__int128 L, R;
ll cons(ll x, ll i)
{
    ll ant, act = q[i];
    if (i > 0)
    {
        ant = q[i - 1];
        L = 1;
        L = L * (dp[act] - dp[ant]);
        R = 1;
        R = R * x * (b[ant] - b[act]);
    }
    if (i > 0 && L > R)
        return -1;
    ll sig;
    if (i + 1 < sz(q))
    {
        sig = q[i + 1];
        L = 1;
        L = L * (dp[sig] - dp[act]);
        R = 1;
        R = R * x * (b[act] - b[sig]);
    }
    if (i + 1 < sz(q) && L < R)
        return 1;
    return 0;
}

ll query(ll x)
{
    ll l = 0, r = sz(q) - 1, piv, ret;
    while (l <= r)
    {
        piv = (l + r) / 2;
        ret = cons(x, piv);
        if (ret == 0)
            return q[piv];
        else if (ret == -1)
            r = piv - 1;
        else
            l = piv + 1;
    }
    return 0;
}
bool del(ll i, ll j, ll k)
{
    L = 1;
    L = L * (dp[k] - dp[i]) * (b[i] - b[j]);
    R = 1;
    R = R * (dp[j] - dp[i]) * (b[i] - b[k]);
    if (L < R)
        return 1;
    return 0;
}

void inser(ll x)
{
    while (sz(q) > 1 && del(q[sz(q) - 2], q.back(), x))
        q.pop_back();
    q.pb(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];

    dp[0] = 0;
    inser(0);

    for (i = 1; i < n; i++)
    {
        j = query(a[i]);
        dp[i] = b[j] * a[i] + dp[j];
        inser(i);
    }
    cout << dp[n - 1];
    return 0;
}
