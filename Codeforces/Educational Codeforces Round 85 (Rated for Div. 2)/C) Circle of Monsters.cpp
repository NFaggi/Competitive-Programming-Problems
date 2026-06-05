//Link: https://codeforces.com/contest/1334/problem/C
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
    ll n, i, cost=0, mi=LLONG_MAX;
    cin >> n;
    vector<ll>a(n),b(n);
    for(i=0; i<n; i++)
        cin >> a[i] >> b[i];
    for(i=0; i<n; i++)
    {
        b[i]=min(b[i],a[(i+1)%n]);
        mi=min(mi,b[i]);
        cost=cost+a[i]-b[i];
    }
    cost=cost+mi;
    cout << cost << '\n';
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
