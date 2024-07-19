#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>>grafo;
vector<long long> sum;
vector<long long> v;
vector<long long>in,fi;
vector<int>padres;
long long tim=0;
vector<long long>sumt,segt,D,I;
void DFS(int nodo, long long padre)
{
    padres[nodo]=padre;
    sum[nodo]=v[nodo];
    in[nodo]=tim;
    tim++;
    sumt.push_back(sum[nodo]);
    for(auto hijo:grafo[nodo])
    {
        if(hijo!=padre)
        {
            DFS(hijo,nodo);
            sum[nodo]+=sum[hijo];
        }
    }
    fi[nodo]=tim;
    tim++;
    sumt.push_back(0);
    
}
void update(int nodo, long long val)
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
    return sumC(a, b, nodo * 2) + sumC(a, b, nodo * 2 + 1);
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
    while(pot<int(sumt.size()))
    pot*=2;
    segt.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot+int(sumt.size()); i++)
        segt[i]=sumt[i-pot];
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>=1; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        segt[i]=segt[i*2]+segt[i*2+1];
    }
    while(q--)
    {
        
        cin >> a >> b;
        if(a==1)
        {
            cin >> c;
            update(in[b]+pot,c);
        }
        else
        {
            cout << sumC(in[b]+pot,fi[b]+pot,1) << endl;
        }
    }
    return 0;
}
