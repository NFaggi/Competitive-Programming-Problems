#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int>>arbol;
vector<long long>dist;
vector<long long>dist2;
void DFSI(int nodo, int padre, long long dis)
{
    dist[nodo]=dis;
    for(auto k:arbol[nodo])
    {
        if(k!=padre)
        {
            DFSI(k,nodo,dis+1ll);
        }
    }
}
void DFSD(int nodo, int padre, long long dis)
{
    dist2[nodo]=dis;
    for(auto k:arbol[nodo])
    {
        if(k!=padre)
        {
            DFSD(k,nodo,dis+1ll);
        }
    }
}
int main()
{
    int n, i, a, b, nod1=1,nod2=1;
    long long ma1=0, ma2=0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    arbol.resize(n+1);
    dist.resize(n+1);
    dist2.resize(n+1);
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        arbol[a].push_back(b);
        arbol[b].push_back(a);
    }
    DFSI(1,-1,0);
    for(i=1; i<=n; i++)
    {
        if(dist[i]>ma1)
        {
            ma1=dist[i];
            nod1=i;
        }
    }
    DFSI(nod1,-1,0);
    for(i=1; i<=n; i++)
    {
        if(dist[i]>ma2)
        {
            ma2=dist[i];
            nod2=i;
        }
    }
    DFSD(nod2,-1,0);
    for(i=1; i<=n; i++)
    {
        cout << max(dist[i],dist2[i]) << ' ';
    }
    return 0;
}
