//Link: https://codeforces.com/gym/105668/problem/C
//Score: 100/100
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
    ll n, i, x, y, cost=0;
    cin >> n;
    vector<ll>v(n);
    forn(i,n)
    {
        cin >> x >> y;
        v[i]=x+y;
    }
    sort(v.begin(),v.end());
    forn(i,n-1)
        cost+=v[i+1]-v[i];
    cost+=v[n-1]-v[0];
    cout << cost << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
