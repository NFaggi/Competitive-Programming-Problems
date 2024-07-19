#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<long long>>arbol;
vector<long long>cant;
vector<bool>visitados;
long long n;
 
long long DFS(long long nodo)
{
    visitados[nodo] = true;
    for(long long i=0; i<arbol[nodo].size(); i++)
    {
        if(!visitados[arbol[nodo][i]])
        {
            cant[nodo]+=DFS(arbol[nodo][i]);
        }
    }
    return cant[nodo]+1;
 
}
 
int main()
{
    long long i, a;
    cin >> n;
    arbol.resize(n+1);
    visitados.resize(n+1,0);
    cant.resize(n+1,0);
    for(i=1; i<n; i++)
    {
        cin >> a;
        arbol[a].push_back(i+1);
    }
    DFS(1);
    for(i=1; i<=n; i++)
    {
        cout << cant[i] << ' ';
    }
    return 0;
}
