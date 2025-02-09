//Link: https://codeforces.com/gym/103809/problem/A
//Score: 100/100
#include <bits/stdc++.h>
#include <cmath>
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
    ll a, b, c, d, ma=0, x, cant=0, i;
    priority_queue<pair<ll,ll>>pq;
    cin >> a;
    for(i=0; i<a; i++)
    {
        cin >> x;
        ma=max(x,ma);
    }
    cin >> d;
    for(i=0; i<d; i++)
    {
        cin >> x;
        pq.push({x,0});
    }
    cin >> c;
    for(i=0; i<c; i++)
    {
        cin >> x;
        pq.push({x,-1});
    }

    cin >> b;
    for(i=0; i<b; i++)
    {
        cin >> x;
        pq.push({x,-2});
    }

    vector<ll>ans(3,0);

    while(cant<10)
    {
        x=pq.top().first;
        ans[-pq.top().second]++;
        pq.pop();
        ma+=x;
        cant++;
    }
    cout << ma << ' ' << ans[0] << '-' << ans[1] << '-' << ans[2] << '\n';

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
