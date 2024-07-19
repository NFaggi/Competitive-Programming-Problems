#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>tree;
vector<long long> dist;
vector<long long> res;
vector<int>suba;
int n;
int DFS(int nodo, int padre, long long dis)
{
    int sub=1;
    dist[nodo]=dis;
    for(auto k:tree[nodo])
    {
        if(k!=padre)
            sub+=DFS(k,nodo,dis+1);
    }
    suba[nodo]=sub;
    return sub;
}
void DFS2(int nodo, int padre)
{
    if(padre!=-1)
    {
        res[nodo]=res[padre]-suba[nodo]+(n-suba[nodo]);
    }
    for(auto k:tree[nodo])
    {
        if(k!=padre)
        DFS2(k,nodo);
    }
}
int main()
{
    int i, a, b;
    long long a1=0;
    cin >> n;
    tree.resize(n+1);
    dist.resize(n+1,0);
    suba.resize(n+1);
    res.resize(n+1);
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    DFS(1,-1,0);
    for(auto k:dist)
        a1+=k;
    res[1]=a1;    
    DFS2(1,-1);
    for(i=1; i<int(res.size()); i++)
        cout << res[i] << ' ';
    return 0;
}
