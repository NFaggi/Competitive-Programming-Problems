//Link: https://codeforces.com/gym/104936/problem/B
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, m, i, pts=0;
    cin >> n >> m;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    for(i=0; i<n; i++)
    {
        if(v[i]>m)
            break;
        pts+=v[i]+1ll;
        m-=v[i];
    }
    pts+=m;
    cout << pts << '\n';
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
