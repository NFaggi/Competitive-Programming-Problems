//Link: https://juez.oia.unsam.edu.ar/task/142
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;
struct Nodo
{
    int hijos[26];
    int fin=0;
    void iniciar()
    {
        fin=0;
        for(int i=0; i<26; i++)
        {
            hijos[i]=-1;
        }
    }
};
Nodo Trie[int(1e6+1)];
int tam=1, raiz=0;
void Agregar(string &s)
{
    int nod=raiz,x;
    for(auto c:s)
    {
        x=c-'A';
        if(Trie[nod].hijos[x]==-1)
        {
            Trie[tam].iniciar();
            Trie[nod].hijos[x]=tam;
            tam++;
        }
        nod=Trie[nod].hijos[x];
    }
    Trie[nod].fin=1;
}
int dp[int(1e5+1)];
string s;
void Search(int i)
{
    int nod=raiz,x;
    for(int j=i; j<int(s.size()); j++)
    {
        x=s[j]-'A';
        if(Trie[nod].hijos[x]==-1)
        {
            break;
        }
        nod=Trie[nod].hijos[x];
        if(Trie[nod].fin==1)
        {
            dp[j+1]=min(dp[j+1],dp[i]);
        }
    }
}
int cubrecadena(string &S, vector<string> &t)
{
    Trie[0].iniciar();
    int i, n=int(t.size()), m=int(S.size()),mi;
    mi=m;
    for(i=0;i<n; i++)
    {
        Agregar(t[i]);
    }
    s=S;
    for(i=0; i<=int(S.size()); i++)
    {
        dp[i]=i;
    }
    for(i=0; i<int(S.size()); i++)
    {
        dp[i+1]=min(dp[i]+1,dp[i+1]);
        Search(i);
    }
    for(i=1; i<=int(S.size()); i++)
    {
        mi=min(mi,dp[i]+m-i);

    }
    return mi;
}