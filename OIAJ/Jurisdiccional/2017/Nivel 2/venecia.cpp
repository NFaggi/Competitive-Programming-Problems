//link: https://juez.oia.unsam.edu.ar/task/133
//score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+1;
const int MAXM=3e5+1;
vector<pair<ll,ll>>grafo[MAXN];
ll vis[MAXM];
vector<ll>res;
void DFS(ll nod)
{
    for(auto k:grafo[nod])
    {
        if(vis[k.second]==0)
        {
            vis[k.second]=1;
            res.push_back(k.second);
            DFS(k.first);
            res.push_back(k.second);
        }
    }
}
int main()
{
    ll n, m, s, i, a, b, l;
    cin >> n >> m >> s;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> l;
        grafo[a].push_back({b,i+1});
        grafo[b].push_back({a,i+1});
    }
    DFS(s);
    cout << res.size() << '\n';
    for(auto k:res)
        cout << k << ' ';
    return 0;
}
