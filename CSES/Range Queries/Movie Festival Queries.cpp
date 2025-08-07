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
const int MAXL = 1e6 + 1;
const int LOG = 21;
ll dp[MAXL + 1], up[MAXL + 1][LOG];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, a, b, j, cant, pos;
    cin >> n >> q;
    vector<pair<ll, ll>> v;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.pb({a, b});
    }
    sort(all(v));
    dp[MAXL] = MAXL;
    for (i = MAXL - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        while (sz(v) && v.back().fr >= i)
        {
            dp[i] = min(dp[i], v.back().se);
            v.pop_back();
        }
    }

    for (i = 0; i < LOG; i++)
        up[MAXL][i] = MAXL;
    
    for (j = MAXL - 1; j >= 0; j--)
    {
        up[j][0]=dp[j];
    }
    for (i = 1; i < LOG; i++)
    {
        for (j = MAXL - 1; j >= 0; j--)
        {
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }

    while(q--)
    {
        cin >> a >> b;
        cant=0;
        pos=a;
        for(i=LOG-1; i>=0; i--)
        {
            if(up[pos][i]<=b)
            {
                pos=up[pos][i];
                cant=cant|(1<<i);
            }
        }
        cout << cant << '\n';
    }

    return 0;
}
