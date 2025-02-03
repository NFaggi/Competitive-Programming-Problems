//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/13
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;
vector<pair<int,int>>I;
vector<int>avent;
int pot=1;
int SrcDel(int p, int nodo)
{
    int der, izq, ant;
    if (v[nodo].first == 0)
    {
        return 0;
    }
    if (p > I[nodo].second || p < I[nodo].first)
        return -1;
    if (p == I[nodo].first && p == I[nodo].second)
    {
        v[nodo].first--;
        ant=avent[nodo-pot];
        avent[nodo-pot]=0;
        return ant;
    }
    izq = SrcDel(p, nodo * 2);
    if (izq > 0)
    {
        v[nodo].first--;
        return izq;
    }
    else
    {
        der = SrcDel(p + v[nodo * 2].second - v[nodo * 2].first, nodo * 2 + 1);
        if (der > 0)
        {
            v[nodo].first--;
        }
        return der;
    }
}

int main() {
    int n, i, q, p, k, aum, pos;
    ifstream cin ("aventureros.in");
    ofstream cout ("aventureros.out");
    cin >> n;
    vector<int>turns(n-1);

    for(i=0; i<n-1; i++)
    {
        cin >> turns[i];
    }
    q = n;
    while (pot < n)
        pot *= 2;
    v.resize(pot * 2,{0,1});
    I.resize(pot * 2);
    avent.resize(n);
    for (i = pot; i < pot + n; i++)
    {
        avent[i-pot]=i-pot+1;
        v[i].first= 1;
    }
    for (i = pot; i < I.size(); i++)
    {
        I[i].first = i;
        I[i].second = i;
    }
    for (i = pot - 1; i > 0; i--)
    {
        I[i].first = I[i * 2].first;
        I[i].second = I[i * 2 + 1].second;
        v[i].first= v[i * 2].first+ v[i * 2 + 1].first;
        v[i].second = v[i].first;
    }
    q--;
    i=0;
    aum = 0;
    pos=0;
    while (q--)
    {
        aum=(pos+turns[i])%n;
        pos=aum;
        i++;
        n--;
        cout << SrcDel(aum+ pot, 1) <<" ";
    }
    cout << endl;
    cout << SrcDel(pot, 1);
    return 0;
}
