#include <bits/stdc++.h>
 
long long INF = LLONG_MAX;
using namespace std;
vector<pair<long long, long long>>v;
vector<long long>vOr;
vector<long long>I;
vector<long long>D;
 
long long SrcDel(long long p, long long nodo)
{
    long long der, izq, ant;
    if (v[nodo].first == 0)
    {
        return 0;
    }
    if (p > D[nodo] || p < I[nodo])
        return -1;
    if (p == I[nodo] && p == D[nodo])
    {
        ant = v[nodo].first;
        v[nodo].second--;
        v[nodo].first = 0;
        return ant;
    }
    izq = SrcDel(p, nodo * 2);
    if (izq > 0)
    {
        v[nodo].first -= izq;
        v[nodo].second--;
        return izq;
    }
    else
    {
        der = SrcDel(p + vOr[nodo * 2] - v[nodo * 2].second, nodo * 2 + 1);
        if (der > 0)
        {
            v[nodo].first -= der;
            v[nodo].second--;
        }
        return der;
    }
}
 
int main() {
    long long n, pot = 1, i, q, p;
    cin >> n;
    q = n;
    while (pot < n)
        pot *= 2;
    v.resize(pot * 2, { 0,0 });
    vOr.resize(pot * 2, 1);
    I.resize(pot * 2);
    D.resize(pot * 2);
    for (i = pot; i < pot + n; i++)
    {
        cin >> v[i].first;
        v[i].second = 1;
    }
    for (i = pot; i < I.size(); i++)
    {
        I[i] = i;
        D[i] = i;
    }
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
        v[i].first = v[i * 2].first + v[i * 2 + 1].first;
        v[i].second = v[i * 2].second + v[i * 2 + 1].second;
        vOr[i] = v[i].second;
    }
    while (q--)
    {
        cin >> p;
        cout << SrcDel(p+ pot - 1, 1) << ' ';
    }
    return 0;
}
