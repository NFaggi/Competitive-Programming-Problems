#include <bits/stdc++.h>
using namespace std;
vector<bool> visitados;
vector<vector<long long> > grafo;
long long maxDist=-1, nodoMax;
void DFS(long long nodo, long long dist)
{
    if(dist>maxDist)
    {
        maxDist=dist;
        nodoMax=nodo;
    }
    visitados[nodo] = true;
    for(long long i=0; i<grafo[nodo].size(); i++)
    {
        if(!visitados[grafo[nodo][i]])
        {
            DFS(grafo[nodo][i], dist+1);
        }
    }
 
}
int main() {
    long long n,i;
    cin >> n;
    visitados.resize(n+1, false);
    grafo.resize(n+1);
    for(i=0; i<n-1; i++)
    {
        long long a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    DFS(1,0);
    visitados.resize(0);
    visitados.resize(n+1, false);
    maxDist=-1;
    DFS(nodoMax,0);
    cout << maxDist;
    return 0;
}
