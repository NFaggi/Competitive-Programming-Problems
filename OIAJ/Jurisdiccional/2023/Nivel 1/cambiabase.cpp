//Link: https://juez.oia.unsam.edu.ar/task/141
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

vector<string> cambiabase(vector<int> &numeros, int base)
{
    vector<string>v;
    string num;
    for(int i=0; i<int(numeros.size()); i++)
    {
        num="";
        while(numeros[i]>1)
        {
            num+=to_string(numeros[i]%base);
            numeros[i]/=base;
        }
        num+=to_string(numeros[i]);
        while(num.size()&&num[int(num.size())-1]=='0')
        {
            num.pop_back();
        }
        if(!num.size())
            num="0";
        reverse(num.begin(),num.end());
        v.push_back(num);
    }
    return v;
}
