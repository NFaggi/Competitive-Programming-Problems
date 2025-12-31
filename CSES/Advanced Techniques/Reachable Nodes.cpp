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

const int MAXN=5e4+1;

vector<ll>grafo[MAXN];
bitset<MAXN>arrived[MAXN],vis;
ll id[MAXN], ans[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, a, b, i;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        grafo[b].pb(a);
        id[a]++;
    }
    queue<ll>q;
    for(i=1; i<=n; i++)
    {
        arrived[i][i]=1;
        if(id[i]==0)
            q.push(i);
    }
    while(sz(q))
    {
        ll nod=q.front();
        q.pop();
        vis[nod]=1;
        for(auto k:grafo[nod])
        {
            arrived[k]|=arrived[nod];
            id[k]--;
            if(vis[k]||id[k])
                continue;
            vis[k]=1;
            q.push(k);
        }
        ans[nod]=arrived[nod].count();
    }
    for(i=1; i<=n; i++)
        cout << ans[i] << ' ';
    return 0;
}
