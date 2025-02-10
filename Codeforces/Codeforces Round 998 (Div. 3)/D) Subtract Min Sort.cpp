//Link: https://codeforces.com/contest/2060/problem/D
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
    ll n, i, x;
    cin >> n;
    vector<ll>a(n);
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(i=0; i<n-1; i++)
    {
        if(a[i]>a[i+1])
        {
            cout << "No\n";
            return;
        }
        else
        {
            x=min(a[i],a[i+1]);
            a[i]-=x;
            a[i+1]-=x;
        }
    }
    cout << "Yes\n";
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
