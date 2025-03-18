#include<bits/stdc++.h>
#define ll int
#define pb push_back
using namespace std;

const int MAXN=1e5+1;

set<ll>grafo[MAXN];
vector<ll>path;
void DFSconst(ll nod)
{
    while(grafo[nod].size())
    {
        auto it2=prev(grafo[nod].end());
        ll k=*it2;
        grafo[nod].erase(it2);
        auto it=grafo[k].find(nod);
        grafo[k].erase(it);
        DFSconst(k);
        
    }
    path.pb(nod);
}
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, M, i, a, b;
    cin >> n >> M;

    for(i=0; i<M; i++)
    {
        cin >> a >> b;
        grafo[a].insert(b);
        grafo[b].insert(a);
    }
    for(i=1; i<=n; i++)
        if(int(grafo[i].size())%2!=0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    DFSconst(1);
    if(int(path.size())!=M+1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(i=M; i>=0; i--)
        cout << path[i] << ' ';
    return 0;
}