#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<long long>>arbol;
vector<bool>visitados;
long long n, cant=0;
 
bool DFS(long long nodo)
{
    bool pos=0;
    if(visitados[nodo])
        return 0;
    visitados[nodo] = true;
    for(long long i=0; i<arbol[nodo].size(); i++)
    {
        if(!visitados[arbol[nodo][i]])
        {
            bool act;
            act = DFS(arbol[nodo][i]);
            if(act==0&&pos==0)
            {
                pos=1;
                cant++;
            }
        }
    }
    return pos;
 
}
 
int main()
{
    long long i, a, b, nod=1;
    cin >> n;
    arbol.resize(n+1);
    visitados.resize(n+1,0);
    for(i=1; i<n; i++)
    {
        cin >> a >> b;
        arbol[a].push_back(b);
        arbol[b].push_back(a);
    }
    for(i=1; i<=n; i++)
    {
        DFS(i);
    }
 
    cout << cant;
    return 0;
}
