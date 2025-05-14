//Link: https://www.spoj.com/problems/SAMER08A/
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

void solve(ll n, ll m)
{
    vector<vector<ll>> grafo(n + 1, vector<ll>(n + 1, -1)), pad(n+1);
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<bool> proc(n + 1, 0);
    ll s, d, a, b, c, i;
    cin >> s >> d;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        grafo[a][b] = c;
    }
    dist[s] = 0;
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, s});
    while (pq.size())
    {
        ll nod = pq.top().second;
        pq.pop();
        if (proc[nod])
            continue;
        proc[nod] = 1;
        for (i = 0; i <= n; i++)
        {
            if (grafo[nod][i] == -1)
                continue;
            if (dist[i] > dist[nod] + grafo[nod][i])
            {
                dist[i] = dist[nod] + grafo[nod][i];
                pad[i]={nod};
                pq.push({-dist[i], i});
            }
            else if(dist[i] == dist[nod] + grafo[nod][i])
            {
                pad[i].pb(nod);
            }
        }
    }
    queue<ll>q;
    q.push(d);
    while(sz(q))
    {
        ll nod=q.front();
        q.pop();
        if(nod==s)
            continue;
        for(auto k:pad[nod])
        {
            q.push(k);
            grafo[k][nod]=-1;
        }
        pad[nod].clear();
    }
    dist.resize(0);
    proc.resize(0);
    dist.resize(n+1,LLONG_MAX);
    proc.resize(n+1,0);
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size())
    {
        ll nod = pq.top().second;
        pq.pop();
        if (proc[nod])
            continue;
        proc[nod] = 1;
        for (i = 0; i <= n; i++)
        {
            if (grafo[nod][i] == -1)
                continue;
            if (dist[i] > dist[nod] + grafo[nod][i])
            {
                dist[i] = dist[nod] + grafo[nod][i];
                pq.push({-dist[i], i});
            }
        }
    }
    if(dist[d]==LLONG_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dist[d] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    while (n != 0)
    {
        solve(n, m);
        cin >> n >> m;
    }
    return 0;
}
