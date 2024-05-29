//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/155
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>grafo;
vector<long long> v;
vector<long long>in,fi;
vector<int>padres;
long long tim=0;
vector<long long>D,I;
vector<long long>segt;
vector<long long>segt2;
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
void update(int nodo, bool val)
{
    int pos=nodo/2;
    segt[nodo]=val;
    while(pos>=1)
    {
        segt[pos]=segt[pos*2]+segt[pos*2+1];
        pos/=2;
    }

}
long long sumC(int a, int b, int nodo)
{
    if (a > D[nodo] || b < I[nodo])
        return 0;
    if (a <= I[nodo] && b >= D[nodo])
        return segt[nodo];
    return sumC(a, b, nodo * 2)+sumC(a, b, nodo * 2 + 1);
}
void update2(int a, int b, int nodo, bool val, bool ant)
{
    if (a > D[nodo] || b < I[nodo])
        return;
    if (a <= I[nodo] && b >= D[nodo])
    {
        segt2[nodo]-=1ll*ant;
        segt2[nodo]+=1ll*val;
        return;
    }
    update2(a, b, nodo * 2,val,ant);
    update2(a, b, nodo * 2 + 1,val,ant);

}
long long sumC2(int a)
{
    long long res=segt2[a];
    a/=2;
    while(a>=1)
    {
        res+=segt2[a];
        a/=2;
    }
    return res;
}
vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo)
{
    vector<int>res(tipo.size());
    long long a, b, c,pot=1;
    int n, q, i;
    bool per=false;
    n=padre.size();
    q=tipo.size();
    vector<bool>v(n+1,0);
    in.resize(n+1);
    fi.resize(n+1);
    padres.resize(n+1,-1);
    grafo.resize(n+1);

    for(i=0; i<padre.size(); i++)
    {
        a=padre[i];
        b=i+1;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    DFS(0,-1);
    while(pot<tim)
        pot*=2;
    //cout << pot << " " << sumt.size() << endl;
    segt.resize(pot*2,0);
    segt2.resize(pot*2,0);
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
    //cout << segt[1] << endl;
    for(i=0; i<q; i++)
    {
        res[i]=0;
        if(tipo[i]==0)
        {
            if(v[nodo[i]]!=1)
            {
                long long ob=sumC2(in[nodo[i]]+pot)+sumC(in[nodo[i]]+pot,fi[nodo[i]]+pot,1);
                per=((ob>0)?1:0);
                if(per==0)
                {
                    update(in[nodo[i]]+pot,1);
                    update2(in[nodo[i]]+pot,fi[nodo[i]]+pot,1,1,0);
                    res[i]=1;
                    v[nodo[i]]=1;
                }
            }
        }
        else
        {
            if(v[nodo[i]]!=0)
            {
                v[nodo[i]]=0;
                update(in[nodo[i]]+pot,0);
                update2(in[nodo[i]]+pot,fi[nodo[i]]+pot,1,0,1);
                res[i]=1;
            }
        }
    }
    return res;
}