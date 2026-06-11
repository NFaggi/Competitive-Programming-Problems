//Link: https://www.spoj.com/problems/HALLOW/
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

bool solve()
{

    ll c, n, i, x, pref=0;
    cin >> c >> n;
    if (c == 0)
        return 0;
    vector<ll>rep(c,-1), v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=0; i<n; i++)
    {
        x=v[i];
        x=x%c;
        pref=(pref+x)%c;
        if(rep[pref]!=-1||pref==0)
        {
            for(ll j=rep[pref]+1; j<=i; j++)
                cout << j+1 << ' ';
            cout << '\n';
            break;
        }
        rep[pref]=i;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (solve())
    {
    }
    return 0;
}
