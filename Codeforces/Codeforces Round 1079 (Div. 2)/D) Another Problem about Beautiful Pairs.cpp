//Link: https://codeforces.com/contest/2197/problem/D
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
    ll n, i, sq=450, j, eq=0, tot=0, num, k;
    cin >> n;
    vector<ll>a(n);
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<n; i++)
    {
        for(j=1; j<min(sq,a[i]); j++)
        {
            num=j*a[i];
            k=i-num;
            if(k>=0&&a[k]==j)
                tot++;
            k=i+num;
            if(k<n&&a[k]==j)
                tot++;
        }
        if(a[i]<=sq)
        {
            num=a[i]*a[i];
            k=i-num;
            if(k>=0&&a[k]==a[i])
                eq++;
            k=i+num;
            if(k<n&&a[k]==a[i])
                eq++;
        }
    }
    eq=eq/2ll;
    tot=tot+eq;
    cout << tot << '\n';
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
