//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/57
#include <bits/stdc++.h>

using namespace std;

struct Fecha { int dia, mes, anno; };
vector<Fecha>v;
vector<int>I;
vector<int>D;
int pos, pot = 1, res;

int maxF(Fecha a, Fecha b)
{
    if (a.anno > b.anno)
    {
        return 0;
    }
    else if (a.anno < b.anno)
    {
        return 1;
    }
    else
    {
        if (a.mes > b.mes)
        {
            return 0;
        }
        else if (a.mes < b.mes)
        {
            return 1;
        }
        else
        {
            if (a.dia > b.dia)
            {
                return 0;
            }
            else if (a.dia < b.dia)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    return 2;
}

void ins(Fecha a)
{
    int aPos;
    v[pos] = a;
    aPos = pos;
    int nuevo;
    while (pos > 1)
    {
        pos /= 2;
        nuevo = maxF(a, v[pos]);
        if (nuevo == 0)
            v[pos] = a;
        else
            break;
    }
    pos = aPos;
    pos++;
}
int enojo(int nodo, Fecha a)
{
    int val = maxF(a, v[nodo]), der;
    if (val == 0||val==2)
        return 0;
    else if (val == 1 && I[nodo] == D[nodo])
        return res-(nodo - (pot - 1));
    if (I[nodo] == D[nodo])
        return 0;
    der = enojo(nodo * 2, a);
    if(der>0)
        return der;
    else
        return enojo(nodo * 2+1, a);
}

int fila(vector<Fecha> orden, vector<int>& enojados)
{
    vector<pair<int, int>>en;
    int ma = 0, act, i;
    while (pot < orden.size())
        pot *= 2;
    pos = pot;
    v.resize(pot * 2);
    I.resize(pot * 2);
    D.resize(pot * 2);
    for (i = pot; i < I.size(); i++)
    {
        I[i] = i;
        D[i] = i;
    }
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
    }
    for (i = 0; i < orden.size(); i++)
    {
        ins(orden[i]);
        res=i+1;
        act = enojo(1, orden[i]);
        if (act > ma)
        {
            ma = act;
        }
        if (act > 0)
        {
            en.push_back({ -act,i + 1 });
        }
    }
    sort(en.begin(), en.end());
    for (auto par : en)
    {
        enojados.push_back(par.second);
    }
    return ma;
}