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

vector<ll> alts[MAXN], imp[MAXN];
ll n;
map<ll, ll> dp[MAXN][2], pref[MAXN], preDP[MAXN][2], sufDP[MAXN], pr[MAXN], su[MAXN];

void agr(ll i, ll x)
{
    if (i > n || i < 0)
        return;
    imp[i].pb(x);
}

ll pre(ll i, ll x)
{
    auto it = pref[i].upper_bound(x);
    if (it == pref[i].begin())
        return 0;
    it = prev(it);
    return it->se;
}

void calc(ll x, ll sub, ll alt)
{
    if (x >= n)
        return;
    ll ma = LLONG_MIN, i, act, reg = -pre(x - 1, alt) - pre(x, alt);

    auto it2 = upper_bound(all(imp[x]), alt);
    if (sub && it2 != imp[x].end())
        ma = max(ma, sufDP[x + 1][*it2] + reg);

    auto it = prev(it2);
    ma = max(ma, preDP[x + 1][0][*it]);

    if (alt == 0)
        ma = max(ma, dp[x + 1][1][0]);
    ma = max(ma, dp[x + 2][1][0]);
    if (x + 1 < n)
    {
        reg=- pre(x, alt);

        auto it4=upper_bound(all(imp[x+1]),alt);
        auto it3=prev(it4);
        ma=max(ma,pr[x+1][*it3]);
        if(it4!=imp[x+1].end())
            ma=max(ma,su[x+1][*it4]+reg);
    }
    dp[x][sub][alt] = ma;
}

long long max_weights(int N, int M, std::vector<int> X, std::vector<int> Y,
                      std::vector<int> W)
{
    n = N;
    ll i, j, k, ag, act, add;
    map<pair<ll, ll>, ll> w;
    for (i = 0; i < M; i++)
    {
        Y[i]++;
        alts[X[i]].pb(Y[i]);
        agr(X[i] + 1, Y[i]);
        agr(X[i] - 1, Y[i]);
        w[{X[i], Y[i]}] = W[i];
    }
    for (i = 0; i <= n + 2; i++)
    {
        imp[i].pb(0);
        sort(all(imp[i]));
        imp[i].erase(unique(all(imp[i])), imp[i].end());

        alts[i].pb(0);
        sort(all(alts[i]));
        pref[i][0] = 0;
        for (j = 1; j < sz(alts[i]); j++)
            pref[i][alts[i][j]] = pref[i][alts[i][j - 1]] + w[{i, alts[i][j]}];
    }
    for (i = n+3; i > 0; i--)
    {
        for (j = 0; j < sz(imp[i - 1]); j++)
        {
            act = imp[i - 1][j];
            for (k = 0; k < 2; k++)
            {
                calc(i, k, imp[i - 1][j]);
                ag = 0;
                if (j > 0)
                    ag = preDP[i][k][imp[i - 1][j - 1]];
                preDP[i][k][act] = max(ag, dp[i][k][act] + pre(i, act) - pre(i - 1, act));
            }
        }
        for(j=sz(imp[i])-1; j>=1; j--)
        {
            act = imp[i][j];
            ag=0;
            if(j+1<sz(imp[i]))
                ag=su[i][imp[i][j+1]];
            su[i][act]=max(ag,dp[i+1][1][act]+pre(i+1,act)+pre(i-1,act));
        }
        for(j=1; j<sz(imp[i]); j++)
        {
            act = imp[i][j];
            ag=0;
            if(j>0)
                ag=pr[i][imp[i][j - 1]];
            pr[i][act]=max(ag,dp[i+1][1][act]+pre(i+1,act));
        }
        for (j = sz(imp[i - 1]) - 1; j >= 0; j--)
        {
            ag = 0, act = imp[i - 1][j], add = 0;
            if (j + 1 < sz(imp[i - 1]))
                ag = sufDP[i][imp[i - 1][j + 1]];
            if (i - 2 >= 0)
                add = pre(i - 2, act);
            sufDP[i][act] = max(ag, dp[i][1][act] + pre(i, act)+add);
        }
    }
    calc(0, 1, 0);
    return dp[0][1][0];
}
