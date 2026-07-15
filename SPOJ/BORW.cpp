//Link: https://www.spoj.com/problems/BORW/
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

void solve()
{
    ll N, i;
    cin >> N;
    if (N == -1)
        exit(0);
    vector<ll> v(N), ord;
    map<ll, ll> cord;
    fore(i, 0, N - 1)
            cin >>
        v[i];

    ord = v;
    ord.pb(0);
    ord.pb(INF);
    sort(all(ord));
    ord.erase(unique(all(ord)), ord.end());

    fore(i, 0, sz(ord) - 1)
        cord[ord[i]] = i;

    fore(i, 0, N - 1)
        v[i] = cord[v[i]];

    vector<vector<ll>> dp(sz(ord), vector<ll>(sz(ord), 0)); // dec, acend

    ll j, k;
    fore(i, 0, N - 1)
    {
        vector<vector<ll>> ndp(sz(ord), vector<ll>(sz(ord), 0));
        fore(j, 0, sz(ord) - 1)
        {
            fore(k, 0, sz(ord) - 1)
            {
                if (j > v[i])
                    ndp[v[i]][k] = max(ndp[v[i]][k], dp[j][k] + 1);
                if (k < v[i])
                    ndp[j][v[i]] = max(ndp[j][v[i]], dp[j][k] + 1);

                ndp[j][k] = max(ndp[j][k], dp[j][k]);
            }
        }
        dp = ndp;
    }

    ll ma = 0;
    fore(i, 0, sz(ord) - 1)
    {
        fore(j, 0, sz(ord) - 1)
        {
            ma = max(ma, dp[i][j]);
        }
    }

    cout << N - ma << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
        solve();
    return 0;
}
