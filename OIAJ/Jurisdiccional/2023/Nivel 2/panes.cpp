//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/146
#include <bits/stdc++.h>

using namespace std;
bool can(vector<int> ci, vector<int> p, int c)
{
    long long i, sald = 0, sob;
    for(i=0; i<ci.size(); i++)
    {
        ci[i]-=c;
    }
    for(i=0; i<ci.size(); i++)
    {
        if(sald+ci[i]>=0&&sald+ci[i]<=p[i])
        {
            sald=0;
            continue;
        }
        sald+=ci[i];
        if(i<p.size())
        {
            sald-=p[i];
        }
    }
    return sald >= 0;
}
int panes(vector<int> &ciudades, vector<int> &peajes)
{
    long long mi=0, ma=2147483647, vMa=0;
    long long piv;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(ciudades, peajes, piv))
        {
            vMa=piv;
            mi = piv+1;
        }
        else
        {
            ma=piv-1;
        }
    }
    return vMa;
}
