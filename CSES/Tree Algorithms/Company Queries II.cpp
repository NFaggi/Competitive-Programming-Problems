#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int>>grafo;
vector<pair<int,int>>segt;
vector<int>I,D,in,fi;
 
vector<pair<int,int>>act;
int tim=0,pot=1;
 
 
pair<int,int> buscMin(int a, int b, int nodo)
{
    if(I[nodo]>b||D[nodo]<a)
    return {-INT_MAX,1};
    else if(a<=I[nodo]&&b>=D[nodo])
        return segt[nodo];
    pair<int,int>ret, ret2;
    ret=buscMin(a,b,nodo*2);
    ret2=buscMin(a,b,nodo*2+1);
    if(ret.first>ret2.first)
        return ret;
    else
        return ret2;
}
 
int LCA(int a, int b)
{
    auto k=buscMin(a+pot,b+pot,1);
    return k.second;
}
 
void DFS(int nodo, int padre, int niv)
{
    in[nodo]=tim;
    act.push_back({-niv,nodo});
    tim++;
    for(auto k:grafo[nodo])
    {
        if(k!=padre)
        {
            DFS(k,nodo,niv+1);
            act.push_back({-niv,nodo});
        }
    }
    fi[nodo]=tim;
    tim++;
}
 
int main()
{
    int n, q, i, a, b;
    cin >> n >> q;
    grafo.resize(n+1);
    in.resize(n+1);
    fi.resize(n+1);
    for(i=0; i<n-1; i++)
    {
        cin >> a;
        b=i+2;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    DFS(1,0,0);
    while(int(act.size())>pot)
        pot*=2;
    segt.resize(pot*2,{-INT_MAX,-INT_MAX});
    D.resize(pot*2);
    I.resize(pot*2);
    for(i=pot; i<pot+int(act.size()); i++)
    {
        segt[i]=act[i-pot];
    }
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        segt[i]=segt[i*2];
        if(segt[i*2+1].first>segt[i].first)
        {
            segt[i]=segt[i*2+1];
        }
    }
    for(i=0; i<q; i++)
    {
        cin >> a >> b;
        if(in[a]>in[b])
            swap(a,b);
        cout << LCA(in[a],in[b]) << endl;
    }
    return 0;
}
