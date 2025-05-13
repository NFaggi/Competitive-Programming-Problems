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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, n, cost=0, a, b, i;
    cin >> x >> n;
    priority_queue<ll>pq;
    for(i=0; i<n; i++)
    {
        cin >> a;
        pq.push(-a);
    }
    while(sz(pq)>1)
    {
        a=-pq.top();
        pq.pop();
        b=-pq.top();
        pq.pop();
        cost+=a+b;
        pq.push(-(a+b));
    }
    cout << cost;
    return 0;
}
