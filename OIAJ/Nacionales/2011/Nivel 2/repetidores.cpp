//Link: https://juez.oia.unsam.edu.ar/task/111
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;
vector<char>nodo,nodo2;
vector<vector<int>>grafo;
vector<int>cost1,cost2;
char a, b, c;
pair<int,int> DFS(int nod, int padre)
{
    int cost=1,act;
    pair<int,int>p= {0,0};
    pair<int,int>sum= {0,0};
    if(nodo[nod]==a)
    {
        for(auto k:grafo[nod])
        {
            if(k==padre)
                continue;
            p=DFS(k,nod);
            sum.first+=p.second;
            sum.second+=p.first;
        }
        sum.second++;
    }
    else if(nodo[nod]==b)
    {
        for(auto k:grafo[nod])
        {
            if(k==padre)
                continue;
            p=DFS(k,nod);
            sum.first+=p.second;
            sum.second+=p.first;
        }
        sum.first++;
    }
    else
    {
        long long costA=0, costB=0;
        for(auto k:grafo[nod])
        {
            if(k==padre)
                continue;
            p=DFS(k,nod);
            sum.first+=p.second;
            sum.second+=p.first;
        }
        sum.second++;
        sum.first++;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin ("repetidores.in");
    ofstream cout ("repetidores.out");
    int n, i, x, m, j, k, op=0;
    char l;
    cin >> n;
    if(n==0)
    {
        cout << "0 A C\n";
        return 0;
    }
    vector<int>in(n+1,0);
    nodo.resize(n+1);
    nodo2.resize(n+1);
    grafo.resize(n+1);
    cost1.resize(n+1,0);
    cost2.resize(n+1,0);
    for(i=0; i<n; i++)
    {
        cin >> x >> l >> m;
        nodo[x]=l;
        nodo2[x]=l;
        for(j=0; j<m; j++)
        {
            cin >> k;
            grafo[x].push_back(k);
            in[k]++;
        }
    }
    int raiz=0;
    for(i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            raiz=i;
            break;
        }
    }
    int mi, act;
    pair<int,int>p;
    a='A';
    b='B';
    c='C';
    p=DFS(raiz,0);
    mi=min(p.first,p.second);
    a='A';
    b='C';
    c='B';
    p=DFS(raiz,0);
    if(p.first<mi)
    {
        mi=p.first;
        op=1;
    }
    if(p.second<mi)
    {
        mi=p.second;
        op=1;
    }
    a='B';
    b='C';
    c='A';
    p=DFS(raiz,0);
    if(p.first<mi)
    {
        mi=p.first;
        op=2;
    }
    if(p.second<mi)
    {
        mi=p.second;
        op=2;
    }
    cout << mi << ' ';
    if(op==0)
        cout << "A B\n";
    else if(op==1)
        cout << "A C\n";
    else
        cout << "B C\n";
    return 0;
}
