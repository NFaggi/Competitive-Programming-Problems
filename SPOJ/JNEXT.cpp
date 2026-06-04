//Link: https://www.spoj.com/problems/JNEXT/
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
    ll n, i, j=-1, in, fin;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=n-2; i>=0; i--)
    {
        if(v[i]<v[i+1])
        {
            j=i;
            break;
        }
    }
    if(j==-1)
    {
        cout << -1 << '\n';
        return;
    }
    in=j;
    vector<ll>v2;
    for(i=in; i<sz(v); i++)
        v2.pb(v[i]);
    sort(all(v2));
    vector<ll>ans;
    for(i=0; i<in; i++)
        ans.pb(v[i]);
    for(j=0; j<sz(v2); j++)
    {
        if(v2[j]>v[in])
            break;
    }
    ans.pb(v2[j]);
    for(i=0; i<sz(v2); i++)
        if(i!=j)
            ans.pb(v2[i]);
    for(auto k:ans)
        cout << k;
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
