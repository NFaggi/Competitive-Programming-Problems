//Link: https://codeforces.com/contest/2193/problem/A
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
    ll n, s, x, tot=0, i, a;
    cin >> n >> s >> x;
    for(i=0; i<n; i++)
    {
        cin >> a;
        tot+=a;
    }
    if(tot>s)
    {
        cout << "NO\n";
        return;
    }
    if((s-tot)%x==0)
        cout << "YES\n";
    else
        cout << "NO\n";
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
