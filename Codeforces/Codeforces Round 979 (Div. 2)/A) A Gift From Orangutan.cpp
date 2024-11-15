//Link: https://codeforces.com/problemset/problem/2030/A
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll n, i, res=0, mi=LLONG_MAX, ma=0;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    mi=v[0];
    ma=v[0];
    for(i=n-1; i>0; i--)
    {
        mi=min(mi,v[i]);
        ma=max(ma,v[i]);
        res+=ma-mi;
    }
    cout << res << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
