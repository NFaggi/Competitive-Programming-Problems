//Link: https://juez.oia.unsam.edu.ar/task/113
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

vector<int> robosort(vector<int> &muestras)
{
    int i, j, k, mi=INT_MAX, pos=0;
    vector<int>res;
    for(i=0; i<int(muestras.size()); i++)
    {
        mi=INT_MAX;
        for(j=i; j<int(muestras.size()); j++)
        {
            if(mi>muestras[j])
            {
                mi=muestras[j];
                pos=j;
            }
        }
        res.push_back(pos+1);
        k=i;
        while(k<=pos)
        {
            swap(muestras[k],muestras[pos]);
            k++;
            pos--;
        }
    }
    return res;
}
