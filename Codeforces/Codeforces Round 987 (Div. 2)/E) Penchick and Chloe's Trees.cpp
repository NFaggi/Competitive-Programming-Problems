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
vector<vector<ll>>grafo;

ll dfs(ll nod)
{
    priority_queue<ll>pq;
    for(auto k:grafo[nod])
        pq.push(-dfs(k));
    if(sz(pq)==0)
        return 0;
    if(sz(pq)==1)
        return (-pq.top())+1ll;
    ll x, y, z;
    while(sz(pq)>1)
    {
        x=-pq.top();
        pq.pop();
        y=-pq.top();
        pq.pop();
        z=max(x,y)+1;
        pq.push(-z);
    }
    return -pq.top();
}

void solve()
{
    ll n, i, pad;
    cin >> n;
    grafo.resize(0);
    grafo.resize(n+1);

    for(i=2; i<=n; i++)
    {
        cin >> pad;
        grafo[pad].pb(i);
    }

    cout << dfs(1) << '\n';
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
