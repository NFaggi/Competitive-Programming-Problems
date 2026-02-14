//Link: https://codeforces.com/contest/2193/problem/D
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
    ll n, i, x, sum=0, ant=0, cant, ma=0;
    cin >> n;
    vector<ll>a(n);
    for(i=0; i<n; i++)
        cin >> a[i];
    set<ll>s;
    map<ll,ll>m;
    for(i=0; i<n; i++)
    {
        cin >> x;
        sum+=x;
        s.insert(sum);
        m[sum]=i;
    }
    sort(all(a));
    for(i=0; i<n; i++)
    {
        if(a[i]==ant)
            continue;
        ant=a[i];
        cant=n-i;
        auto it=s.upper_bound(cant);
        if(it==s.begin())
            break;
        it=prev(it);
        ma=max(ma,(m[*it]+1)*ant);
    }

    cout << ma << '\n';
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
