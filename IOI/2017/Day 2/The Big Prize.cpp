//Link: https://oj.uz/problem/view/IOI17_prize
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

vector<int> ask(int i);

const int MAXM = 450;

map<ll, vector<int>> memo;
ll ans = 0;
int N, ma;
bool enc = 0;
vector<int> cons(ll x)
{
    if (enc)
        return {N, N};
    auto it = memo.find(x);
    if (it == memo.end())
        memo[x] = ask(x);
    if (memo[x][0] + memo[x][1] == 0)
    {
        enc = 1;
        ans = x;
    }
    return memo[x];
}
int sum(ll x)
{
    vector<int> ret = cons(x);
    return ret[1] + ret[0];
}
bool lolip(ll x)
{
    vector<int> q = cons(x);
    ll cant = q[0] + q[1];
    return cant >= ma;
}

void solve(ll l, ll r, ll il, ll ir)
{
    if (il == ir || enc)
        return;
    if (l == r)
    {
        cons(l);
        return;
    }

    ll mid = (l + r) / 2;
    while (!enc && mid >= l && !lolip(mid))
        mid--;
    if (enc)
        return;
    if (mid >= l)
    {
        solve(l, mid, il, cons(mid)[0]);
        if (enc)
            return;
        solve((l + r) / 2 + 1, r, cons(mid)[0] + abs(((l + r) / 2) - mid), ir);
    }
}

int find_best(int n)
{

    ll a = 0, i, b = n - 1;
    for (i = 0; i < min(MAXM, n); i++)
    {
        ma = max(ma, sum(i));
        ll x = (ma * ma + 1);
        if (x * x + 1LL > n)
            break;
    }
    N = n;
    for (i = 0; i < MAXM; i++)
    {
        if (enc || lolip(i))
        {
            a = i;
            break;
        }
    }
    for (i = n - 1; i >= n - MAXM; i--)
    {
        if (enc || lolip(i))
        {
            b = i;
            break;
        }
    }

    solve(a, b, cons(a)[0], cons(b)[0]);

    return ans;
}
