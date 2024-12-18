//Link: https://codeforces.com/problemset/problem/2002/C
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dis(ll x, ll y)
{
    ll res=x*x+y*y;
    return res;
}
void solve()
{
    ll dist=0,dist2,di;
    ll n, i;
    ll x, y, x1, y1;
    cin >> n;
    vector<pair<ll,ll>>v(n);
    for(i=0; i<n; i++)
    {
        cin >> x >> y;
        v[i]={x,y};
    }
    cin >> x >> y >> x1 >> y1;
    dist2=abs(x-x1)+abs(y-y1);
    dist=dis(abs(x-x1),abs(y-y1));
    for(i=0; i<n; i++)
    {
        x=v[i].first;
        y=v[i].second;
        di=dis(abs(x-x1),abs(y-y1));
        if(di<=dist)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
