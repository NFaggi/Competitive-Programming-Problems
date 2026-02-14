//Link: https://codeforces.com/contest/2193/problem/E
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
    ll n, i, x, j;
    cin >> n;
    vector<ll>mi(n+1,n+1);
    for(i=0; i<n; i++)
    {
        cin >> x;
        mi[x]=1;
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=sqrt(i); j++)
        {
            if(i%j==0)
                mi[i]=min(mi[i],mi[j]+mi[i/j]);
        }
        if(mi[i]==n+1)
            cout << -1 << ' ';
        else
            cout << mi[i] << ' ';
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
