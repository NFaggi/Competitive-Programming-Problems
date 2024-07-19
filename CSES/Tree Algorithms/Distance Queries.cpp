#include <bits/stdc++.h>
#define SIZE(x) int(x.size())
using namespace std;
 
vector<vector<int>>grafo;
vector<int> sum;
vector<int> v;
vector<int>in,fi;
vector<pair<int,int>>tAct;
vector<pair<int,int>>vt;
vector<int>padres;
int tim=0,pot=1,pot2=1;
vector<int>segt,D,I,I2,D2;
vector<pair<int,int>>segt2;
pair<int,int> busMin(int a, int b, int nod)
{
    pair<int,int>mi,au;
    if(I2[nod]>b||D2[nod]<a)
        return {-INT_MAX,1};
    else if(I2[nod]>=a&&D2[nod]<=b)
    {
        return segt2[nod];
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
    auto k=busMin(a+pot2,b+pot2,1);
    nodo=k.second;
    return nodo;
}
void DFS(int nodo, int padre,int dis)
{
    vt.push_back({nodo,1});
    padres[nodo]=padre;
    in[nodo]=tim;
    tAct.push_back({-dis,nodo});
    tim++;
    for(auto hijo:grafo[nodo])
    {
        if(hijo!=padre)
        {
            DFS(hijo,nodo,dis+1);
            tAct.push_back({-dis,nodo});
        }
    }
    vt.push_back({nodo,0});
    fi[nodo]=tim;
    tim++;
 
}
void update(int a, int b, int nodo, int val, int ant)
{
    if (a > D[nodo] || b < I[nodo])
        return;
    if (a <= I[nodo] && b >= D[nodo])
    {
        segt[nodo]-=ant;
        segt[nodo]+=val;
        return;
    }
    update(a, b, nodo * 2,val,ant);
    update(a, b, nodo * 2 + 1,val,ant);
 
}
int sumC(int a)
{
    int res=segt[a];
    a/=2;
    while(a>=1)
    {
        res+=segt[a];
        a/=2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c,lc,caS, n, q, i;
    cin >> n >> q;
    v.resize(n+1,1);
    sum.resize(n+1,0);
    in.resize(n+1);
    fi.resize(n+1);
    padres.resize(n+1,-1);
    grafo.resize(n+1);
    v[0]=0;
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    DFS(1,-1,0);
    while(SIZE(vt)+1>pot2)
    {
        pot2*=2;
    }
 
    while(pot<tim)
        pot*=2;
    segt2.resize(pot2*2,{-INT_MAX,1});
    I2.resize(pot2*2);
    D2.resize(pot2*2);
    segt.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>=1; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    for(i=pot2; i<pot2+SIZE(tAct); i++)
    {
        segt2[i]=tAct[i-pot2];
    }
    for(i=pot2; i<int(I2.size()); i++)
    {
        I2[i]=i;
        D2[i]=i;
    }
    for(i=pot2-1; i>=1; i--)
    {
        I2[i]=I2[i*2];
        D2[i]=D2[i*2+1];
        segt2[i]=segt2[i*2];
        if(segt2[i].first<segt2[i*2+1].first)
        {
            segt2[i]=segt2[i*2+1];
        }
    }
    for(i=1; i<int(v.size()); i++)
    {
        update(in[i]+pot,fi[i]+pot,1,v[i],0);
    }
    while(q--)
    {
 
        cin >> a >> b;
        lc = LCA(min(in[a],in[b]),max(in[a],in[b]));
        caS=sumC(in[a]+pot)+sumC(in[b]+pot)-sumC(in[lc]+pot)*2;
        cout << caS << endl;
        
    }
    return 0;
}
