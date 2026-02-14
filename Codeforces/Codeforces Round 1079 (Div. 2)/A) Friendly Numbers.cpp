//Link: https://codeforces.com/contest/2197/problem/A
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

ll d(ll x)
{
    ll sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

void solve()
{
    ll x, rang=10000, cant=0;
    cin >> x;
    for(ll i=x; i<=x+rang; i++)
    {
        if(i-d(i)==x)
            cant++;
    }
    cout << cant << '\n';
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
