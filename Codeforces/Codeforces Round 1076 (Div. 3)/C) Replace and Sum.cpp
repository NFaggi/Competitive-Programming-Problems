//Link: https://codeforces.com/contest/2193/problem/C
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
    ll n, i, ma=0, q, x, y, sum;
    cin >> n >> q;
    vector<ll>a(n),b(n), pref(n);
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<n; i++)
        cin >> b[i];
    for(i=n-1; i>=0; i--)
    {
        ma=max(ma,max(a[i],b[i]));
        a[i]=ma;
    }
    pref[0]=a[0];
    for(i=1; i<n; i++)
        pref[i]=pref[i-1]+a[i];
    while(q--)
    {
        cin >> x >> y;
        x--;
        y--;
        sum=pref[y];
        if(x>0)
            sum-=pref[x-1];
        cout << sum << ' ';
    }
    cout << '\n';
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
