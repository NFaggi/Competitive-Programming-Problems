//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/150

#include <bits/stdc++.h>

using namespace std;

bool can(int k, long long c, vector<int> x)
{
    unsigned long long sum=0;
    for(int i=0; i<x.size(); i++)
    {
        sum+=min(c,x[i]*1ll);
    }
    sum/=(k*1ll);
    return sum>=c;
}

long long bombones(int K, vector<int> &x)
{
    long long mi=0, ma=LLONG_MAX, vMa=0;
    long long piv;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(K, piv, x))
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
