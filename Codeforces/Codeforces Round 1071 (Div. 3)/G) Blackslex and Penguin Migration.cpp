#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN = 10001;
ll n;
map<ll, ll> memo[MAXN];

ll cons(ll i, ll j)
{
    if (i > j)
        swap(i, j);
    if (i == j)
        return 0;
    if (memo[i][j])
        return memo[i][j];
    ll ans;
    cout << "? " << i << ' ' << j << '\n';
    cout.flush();
    cin >> ans;
    memo[i][j] = ans;
    return ans;
}

ll maJ(ll nod)
{
    ll ma = 0, i, maI = 0, x;
    for (i = 1; i <= n * n; i++)
    {
        x = cons(nod, i);
        if (x > ma)
        {
            ma = x;
            maI = i;
        }
    }
    return maI;
}
vector<ll> v[MAXN * 2];
ll ans[101][101], ap[MAXN];

void arm(ll tim, ll a, ll b, ll maD)
{
    if (tim >= n * 2-1)
        return;
    if(tim>=n)
        maD-=2;
    vector<pair<ll, ll>> act;
    vector<ll> iz, der;
    ll i, tam = sz(v[tim]);

    auto calc = [&](ll x)
    {
        act.resize(0);
        for (i = 0; i < tam; i++)
            act.pb({cons(v[tim][i], x), v[tim][i]});
    };
    vector<ll> falt;
    auto ins = [&](vector<ll> &ord)
    {
        sort(all(act));
        if (sz(act))
            falt.pb(act[0].se);
        for (i = sz(act) - 1; i > 0; i--)
        {
            if (act[i].fr == act[i - 1].fr)
            {
                falt.pb(act[i].se);
                break;
            }
            ord.pb(act[i].se);
            ap[act[i].se] = 1;
        }
    };
    calc(b);
    ins(iz);

    if (sz(falt)>1&&cons(falt.back(), a) == maD)
        swap(falt[0],falt[1]);
    der.pb(falt[0]);
    ap[falt[0]] = 1;
    if (sz(falt) > 1)
    {
        ap[falt[1]] = 1;
        der.pb(falt[1]);
    }

    for (i = 0; i < tam; i++)
        if (!ap[v[tim][i]])
        {
            iz.pb(v[tim][i]);
            break;
        }
    while (sz(der))
    {
        iz.pb(der.back());
        der.pop_back();
    }
    ll x = 0, y = tim, sa, sb, di;
    if (tim >= n)
    {
        y = n - 1;
        x = tim - y;
    }
    di = abs(x - y) * 2 + 1;
    for (i = 0; i < tam; i++)
    {
        ans[x][y] = iz[i];
        x++;
        y--;
    }
    if (sz(iz))
    {
        sa = iz[0];
        sb = iz.back();
    }
    arm(tim + 1, sa, sb, di);
}

void solve()
{
    memset(ap, 0, sizeof(ap));
    cin >> n;
    for (ll i = 0; i <= n * n; i++)
        memo[i].clear();
    ll in, i, j;
    in = maJ(1);
    for (i = 1; i <= n * 2; i++)
        v[i].resize(0);
    for (i = 1; i <= n * n; i++)
        v[cons(in, i)].pb(i);

    ans[0][0] = in;
    ans[0][1] = v[1][0];
    ans[1][0] = v[1][1];
    arm(2, ans[0][1], ans[1][0],3);
    cout << "!\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    cout.flush();
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
