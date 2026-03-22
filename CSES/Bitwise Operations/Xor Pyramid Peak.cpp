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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, xo = 0, i, x;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (((n-1)&i)==i)
            xo = xo ^ x;
    }

    cout << xo;
    return 0;
}
