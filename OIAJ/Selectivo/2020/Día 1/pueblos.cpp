//Link: https://juez.oia.unsam.edu.ar/tasks/pueblos
/Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second

using namespace std;

struct nodo
{
    ll h[10], sum=0, pad;
};

const int MAXT=5e6+1;

nodo trie[MAXT];
ll act=1;
void inicializar(int Q,int M)
{
}

long long pueblo(string A, long long PA)
{
    ll x, ant, nod=0;
    for(auto k:A)
    {
        x=k-'0';
        if(trie[nod].h[x]==0)
        {
            trie[nod].h[x]=act++;
            trie[trie[nod].h[x]].pad=nod;
        }
        nod=trie[nod].h[x];    
    }
    ant=trie[nod].sum;
    trie[nod].sum=PA;
    while(nod>0)
    {
        nod=trie[nod].pad;
        trie[nod].sum+=PA-ant;
    }
    return ant;
}

ll der(string A, ll band)
{
    ll nod=0, x, i, sum=0;
    for(auto k:A)
    {
        x=k-'0';
        for(i=9; i>x; i--)
        {
            if(trie[nod].h[i])
                sum+=trie[trie[nod].h[i]].sum;
        }
        nod=trie[nod].h[x];
        if(nod==0)
            return sum;
    }
    if(band)
        sum+=trie[nod].sum;
    return sum;    
}
long long consulta(string A, string B)
{
    return der(A,1)-der(B,0);
}
