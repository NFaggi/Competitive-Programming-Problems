#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

void solve()
{
    ll n, i, x, xo=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x;
        if(x%2!=0)
            xo=1;
    }
    if(!xo)
        cout << "second\n";
    else
        cout << "first\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
