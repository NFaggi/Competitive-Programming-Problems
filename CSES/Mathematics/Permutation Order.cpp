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

const int MAXF = 21;
const int MAXN = 21;

ll fact[MAXF];
bool vis[MAXN];

void solveT1()
{
    ll n, k, i, pos = 1, c, j, num, ag, act;
    cin >> n >> k;
    memset(vis, 0, sizeof(vis));
    vector<ll> ans;
    for (i = 1; i <= n; i++)
    {
        c = 0;
        ag = 0;
        num = 1;
        for (j = 1; j <= n; j++)
        {
            if (vis[j])
                continue;
            act = c * fact[n - i];
            if (act + pos <= k)
            {
                num = j;
                ag = act;
            }
            c++;
        }
        vis[num] = 1;
        ans.pb(num);
        pos+=ag;
    }
    for (auto k : ans)
        cout << k << ' ';
    cout << '\n';
}

void solveT2()
{
    ll n, i, x, pos = 1, c, j;
    cin >> n;
    memset(vis, 0, sizeof(vis));

    for (i = 1; i <= n; i++)
    {
        cin >> x;
        c = 0;
        vis[x] = 1;
        for (j = 1; j < x; j++)
            c = c + !vis[j];
        pos += c * fact[n - i];
    }
    cout << pos << '\n';
}

void solve()
{
    ll t;
    cin >> t;
    if (t == 1)
        solveT1();
    else
        solveT2();
}

void precalc()
{
    fact[0] = 0;
    fact[1] = 1;
    for (ll i = 2; i < MAXF; i++)
        fact[i] = fact[i - 1] * i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
