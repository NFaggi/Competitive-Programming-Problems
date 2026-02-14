//Link: https://codeforces.com/contest/2197/problem/B
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
    ll n, i;
    cin >> n;
    vector<ll>p(n), a(n), lp(n+1,-1), la(n+1,-1), rp(n+1,-1), ra(n+1,-1);
    vector<pair<ll,ll>> l(n,{-1,-1}), r(n,{-1,-1});
    for(i=0; i<n; i++)
        cin >> p[i];
    for(i=0; i<n; i++)
        cin >> a[i];
    
    for(i=0; i<n; i++)
    {
        if(la[a[i]]==-1)
            la[a[i]]=i;
        ra[a[i]]=i;
    }
    ll ma=-1;
    for(i=0; i<n; i++)
    {
        if(la[p[i]]<=ma&&la[p[i]]!=-1)
        {
            cout << "NO\n";
            return;
        }
        ma=max(ma,ra[p[i]]);
    }
    ll mi=n;
    for(i=n-1; i>=0; i--)
    {
        if(ra[p[i]]>=mi)
        {
            cout << "NO\n";
            return;
        }
        if(la[p[i]]!=-1)
            mi=min(mi,la[p[i]]);
    }

    cout << "YES\n";
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
