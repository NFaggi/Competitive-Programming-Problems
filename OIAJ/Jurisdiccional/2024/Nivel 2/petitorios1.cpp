//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>grafo;
double t;
int DFS(int nod, int pad)
{
    if(int(grafo[nod].size())==0)
        return 1;
    vector<int>hijos;
    int x;
    for(auto k:grafo[nod])
    {
        x=DFS(k,nod);
        hijos.push_back(x);
    }
    sort(hijos.begin(),hijos.end());
    double mi=ceil(double(int(hijos.size())*t));
    int miI=mi, res=0;
    for(int i=0; i<mi; i++)
    {
        res+=hijos[i];
    }
    return res;
}
int petitorios(int T, vector<int> & jefes)
{
    t=T;
    t/=double(100);
    grafo.resize(int(jefes.size())+1);
    for(int i=0; i<int(jefes.size()); i++)
        grafo[jefes[i]].push_back(i+1);
    return DFS(0,-1);
}
