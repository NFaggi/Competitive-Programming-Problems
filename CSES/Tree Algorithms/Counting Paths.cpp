#include <bits/stdc++.h>
#define SIZE(x) int(x.size())
using namespace std;
vector<vector<int>>arbol;
vector<int>vsum;
vector<int>res;
int tim=0;
vector<pair<int,int>>vt;
vector<pair<int,int>>tAct;
vector<int> inicio;
vector<int> fin;
vector<pair<int,int>>segt;
vector<int>I,D;
int tiempo=0,pot=1;
pair<int,int> busMin(int a, int b, int nod)
{
    pair<int,int>mi,au;
    if(I[nod]>b||D[nod]<a)
    return {-INT_MAX,1};
    else if(I[nod]>=a&&D[nod]<=b)
    {
        return segt[nod];
    }
    mi=busMin(a,b,nod*2);
    au=busMin(a,b,nod*2+1);
    if(mi.first>au.first)
    {
        return mi;
    }
    else
    {
        return au;
    }
 
}
int LCA(int a, int b)
{
    int nodo=1;
    auto k=busMin(a+pot,b+pot,1);
    nodo=k.second;
    return nodo;
}
void dfs(int nodo, int padre,int dis)
{
    inicio[nodo]=tiempo;
    vt.push_back({nodo,1});
    tAct.push_back({-dis,nodo});
    tiempo++;
    for (int hijo:arbol[nodo])
    {
        if (hijo!=padre)
        {
            dfs(hijo, nodo,dis+1);
            tAct.push_back({-dis,nodo});
        }
    }
    vt.push_back({nodo,0});
    fin [nodo]= tiempo;
    tiempo++;
}
int DFS(int nodo, int padre)
{
    int sum=0;
    for (int hijo:arbol[nodo])
    {
        if (hijo!=padre)
        {
            sum+=DFS(hijo, nodo);
        }
    }
    vsum[nodo]+=sum;
    return vsum[nodo]-res[nodo];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,a,b,i,c;
    cin >> n >> m;
    arbol.resize(n+1);
    vsum.resize(n+1,0);
    res.resize(n+1,0);
    inicio.resize(n+1);
    fin.resize(n+1);
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        arbol[a].push_back(b);
        arbol[b].push_back(a);
    }
    dfs(1,0,0);
    while(SIZE(vt)+1>pot)
    {
        pot*=2;
    }
    I.resize(pot*2);
    D.resize(pot*2);
    segt.resize(pot*2,{-INT_MAX,1});
    for(i=pot; i<pot+SIZE(tAct); i++)
    {
        segt[i]=tAct[i-pot];
    }
    for(i=pot; i<SIZE(I); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        segt[i]=segt[i*2];
        if(segt[i].first<segt[i*2+1].first)
        {
            segt[i]=segt[i*2+1];
        }
    }
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        c=LCA(min(inicio[a],inicio[b]),max(inicio[a],inicio[b]));
        if(c!=a&&c!=b)
        {
            res[c]++;
            vsum[c]--;
            vsum[b]++;
            vsum[a]++;
        }
        else if(c==a)
        {
            res[a]++;
            vsum[b]++;
        }
        else
        {
            res[b]++;
            vsum[a]++;
        }
    }
    DFS(1,0);
    for(i=1; i<=n; i++)
    {
        cout << vsum[i] << " ";
    }
    return 0;
}
