//Link: https://juez.oia.unsam.edu.ar/task/47
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

struct Nodo
{
    int hijo[58], fin=0;
    long long imps=0;
    void iniciar()
    {
        for(int i=0; i<58; i++)
        {
            hijo[i]=-1;
        }
    }
};
struct cal
{
    int nod, us, pos;
};
const int largo = 300001;

Nodo trie[largo];
long long sum=0;
int raiz = 0, tam = 1;
void calc(string & s, long long imp)
{
    int nod = raiz, n=int(s.size()), i;
    cal ne, ne2;
    queue<cal>q;
    ne.nod=nod;
    ne.us=0;
    ne.pos=0;
    q.push(ne);
    while(q.size())
    {
        ne = q.front();
        q.pop();
        if(ne.pos>=n)
        {
            if(trie[ne.nod].fin==1)
            {
                sum+=abs(imp-trie[ne.nod].imps);
            }
            continue;
        }
        int x=s[ne.pos]-'A';
        if(trie[ne.nod].hijo[x]!=-1)
        {
            ne2=ne;
            ne2.pos++;
            ne2.nod=trie[ne.nod].hijo[x];
            q.push(ne2);
        }
        if(ne.us==1)
            continue;
        for(i=0; i<58; i++)
        {
            if(i==x)
                continue;
            if(trie[ne.nod].hijo[i]!=-1)
            {
                ne2=ne;
                ne2.pos++;
                ne2.us=1;
                ne2.nod=trie[ne.nod].hijo[i];
                q.push(ne2);
            }
        }
    }
}
void Agregar(string & s, long long imp)
{
    int nod = raiz;
    for(auto c : s)
    {
        int x = c-'A';
        if(trie[nod].hijo[x]==-1)
        {
            trie[tam].iniciar();
            trie[nod].hijo[x]=tam;
            tam++;
        }
        nod = trie[nod].hijo[x];
    }
    trie[nod].imps+=imp;
    trie[nod].fin=1;
}

long long curry(vector<string> &palabras, vector<int> &significados)
{
    trie[0].iniciar();
    int i;
    for(i=0; i<int(palabras.size()); i++)
    {
        calc(palabras[i],significados[i]);
        Agregar(palabras[i],significados[i]);
    }
    return sum;
}
