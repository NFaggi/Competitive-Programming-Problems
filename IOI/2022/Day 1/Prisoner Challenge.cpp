//Link: https://oj.uz/problem/view/IOI22_prison
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

vector<vector<int>> v;
ll n;

void calc(ll l, ll r, ll tip, ll sig, ll act, ll la, ll ra)
{
    if (l > r)
        return;
    v[act][0] = tip;
    ll i;
    for (i = r; i <= ra; i++)
        v[act][i] = -((!tip) + 1);
    for (i = l; i >= la; i--)
        v[act][i] = -(tip + 1);
    l++;
    r--;
    if (act <= 12)
    {
        ll mid = ((r - l + 1) + 2) / 3;
        for (i = l; i <= l + mid - 1; i++)
            v[act][i] = sig + 1;
        for (i = l + mid; i <= l + mid * 2 - 1; i++)
            v[act][i] = sig + 2;
        for (i = l + mid * 2; i <= r; i++)
            v[act][i] = sig + 3;
        calc(l, l + mid - 1, !tip, sig + 3, sig + 1, l - 1, r + 1);
        calc(l + mid, l + mid * 2 - 1, !tip, sig + 3, sig + 2, l - 1, r + 1);
        calc(l + mid * 2, r, !tip, sig + 3, sig + 3, l - 1, r + 1);
    }
    else
    {
        if (l > r)
            return;

        if (r - l + 1 <= 2)
        {
            for (i = l; i <= r; i++)
                v[act][i] = sig + 1;
            calc(l, r, !tip, sig + 2, sig + 1, l - 1, r + 1);
        }
        else
        {
            ll mid = ((r - l + 1) + 1) / 2;
            for (i = l; i <= l + mid - 1; i++)
                v[act][i] = sig + 1;
            for (i = l + mid; i <= r; i++)
                v[act][i] = sig + 2;
            calc(l, l + mid - 1, !tip, sig + 2, sig + 1, l - 1, r + 1);
            calc(l + mid, r, !tip, sig + 2, sig + 2, l - 1, r + 1);
        }
    }
}

std::vector<std::vector<int>> devise_strategy(int N)
{
    v.resize(21, vector<int>(N + 1, 0));
    n = N;

    calc(1, N, 0, 0, 0, 1, N);

    return {v};
}
