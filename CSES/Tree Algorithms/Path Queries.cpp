#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>>grafo;
vector<long long> sum;
vector<long long> v;
vector<long long>in,fi;
vector<int>padres;
long long tim=0;
vector<long long>segt,D,I;
void DFS(int nodo, long long padre)
{
    padres[nodo]=padre;
    in[nodo]=tim;
    tim++;
    for(auto hijo:grafo[nodo])
    {
        if(hijo!=padre)
        {
            DFS(hijo,nodo);
        }
    }
    fi[nodo]=tim;
    tim++;
 
}
void update(int a, int b, int nodo, long long val, long long ant)
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
long long sumC(int a)
{
    long long res=segt[a];
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b, c,pot=1;
    int n, q, i;
    cin >> n >> q;
    v.resize(n+1);
    sum.resize(n+1,0);
    in.resize(n+1);
    fi.resize(n+1);
    padres.resize(n+1,-1);
    grafo.resize(n+1);
    for(i=1; i<=n; i++)
    {
        cin >> v[i];
    }
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    DFS(1,-1);
    while(pot<tim)
    pot*=2;
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
    for(i=1; i<int(v.size()); i++)
    {
        update(in[i]+pot,fi[i]+pot,1,v[i],0);
    }
    while(q--)
    {
 
        cin >> a >> b;
        if(a==1)
        {
            cin >> c;
            update(in[b]+pot,fi[b]+pot,1,c,v[b]);
            v[b]=c;
        }
        else
        {
            cout << sumC(in[b]+pot) << endl;
        }
    }
    return 0;
}
