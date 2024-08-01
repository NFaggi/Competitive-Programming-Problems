#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>arbol;
vector<bool>vis;
vector<long long>tam;
long long DFS(int nodo, int pad)
{
    long long ma=0;
    if(vis[nodo])
        return tam[nodo];
    vis[nodo]=1;
    for(auto k:arbol[nodo])
    {
        if(k!=nodo)
        {
            ma=max(ma,DFS(k,nodo));
        }
    }
    tam[nodo]=ma+1ll;
    return tam[nodo];
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, m, i, a, b;
    cin >> n >> m;
    arbol.resize(n+1);
    vis.resize(n+1,0);
    tam.resize(n+1,0);
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        arbol[a].push_back(b);
    }
    long long ma=0;
    for(i=1; i<=n; i++)
    {
        if(vis[i]==0)
            ma=max(DFS(i,0)-1ll,ma);
    }
    cout << ma;
    return 0;
}
