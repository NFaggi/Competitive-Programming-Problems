//Link: https://codeforces.com/problemset/problem/2051/E
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
    ll n, i, x, k, cant=0, ma=0, neg=0;
    cin >> n >> k;
    vector<pair<ll,ll>>v;
    vector<ll>in(n);
    for(i=0; i<n; i++)
    {
        cin >> x;
        in[i]=x;
        v.push_back({x,0});
    }
    for(i=0; i<n; i++)
    {
        cin >> x;
        v.push_back({x,in[i]});
    }
    sort(all(v));
    reverse(all(v));
    priority_queue<ll>pq;
    i=0;
    while(i<n*2)
    {
        if(v[i].second)
        {
            neg++;
            cant++;
        }
        else
        {
            neg--;
        }
        if(i+1<n*2&&v[i+1].first==v[i].first)
        {
            i++;
            continue;
        }
        if(neg<=k)
            ma=max(ma,v[i].first*cant);
        i++;
    }
    cout << ma << '\n';
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
