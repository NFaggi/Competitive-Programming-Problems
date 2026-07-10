//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define fr first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

ll sum, k;

vector<ll> ans;
map<ll, ll> memo;

ll cons(ll x)
{
    if (x == 0)
        return 0;
    if (memo[x])
        return memo[x] - 1 + sum;
    ll ret;
    cout << "? " << x << endl;
    cin >> ret;
    memo[x] = ret + 1;
    return ret + sum;
}

ll gauss(ll x)
{
    return (x * (x + 1ll)) / 2ll;
}
ll n;
void calc(ll l, ll r, ll cant)
{
    if (sz(ans) == k - 1)
    {
        l = cons(n);
        l = gauss(n) - l;
        ans.pb(l);
        return;
    }
    if (sz(ans) == k)
        return;
    if (cant == 0)
        return;
    ll ret, falt;
    ret = cons(r);
    falt = gauss(r) - ret;
    if (cant == 1 || (falt / l) == 1)
    {
        ans.pb(falt);
        sum += falt;
        return;
    }
    ll tam = (r - l + 1);
    ll prom = (falt) / cant, i, ant = l - 1;
    for (i = prom; i <= r; i)
    {
        if (sz(ans) == k - 1)
        {
            ant = cons(n);
            ant = gauss(n) - ant;
            ans.pb(ant);
            return;
        }
        if (sz(ans) == k)
            return;
        ret = cons(i);
        falt = gauss(i) - ret;

        if (falt != 0)
            calc(ant + 1, i, min(falt / (ant + 1ll), cant));

        if (i == r)
            break;
        ant = i;
        i = min(i + prom, r);
    }
}

void solve()
{
    sum = 0;
    ans.resize(0);
    memo.clear();
    ll i, ret, ant = 0, cant = 0, falt;
    cin >> n >> k;
    if (k == 1)
    {
        ret = cons(n);
        falt = gauss(n) - ret;
        ans.pb(falt);
    }
    else
    {
        vector<pair<ll,ll>>v={{1,2}};
        while(v.back().se<n)
        {
            v.pb({v.back().se+1,min((v.back().se+1)*2,n)});
        }
        for (ll j=0; j<sz(v); j++)
        {
            i=v[j].se;
            ant=v[j].fr-1;
            if (sz(ans) == k - 1)
            {
                i = cons(n);
                i = gauss(n) - i;
                ans.pb(i);
                break;
            }
            ret = cons(i);
            if (ret != gauss(i))
            {
                falt = gauss(i) - ret;
                cant = falt / (ant + 1ll);
                calc(ant + 1, i, min(cant, k));
            }
            if (sz(ans) == k)
                break;
            ant = i;
            if (i < n)
                i = min(i << 2ll, n);
            else
                break;
        }
    }
    cout << "! ";
    for (auto k : ans)
        cout << k << ' ';
    cout << endl;

    cin >> n;
    if (n == -1)
        exit(0);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
