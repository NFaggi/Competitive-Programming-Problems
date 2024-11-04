//Link: https://juez.oia.unsam.edu.ar/task/160
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;
vector <vector <int> > comp;
vector <int> id;

bool unionfind(int a, int b)
{
    if(id[a] == id[b])
        return false;
    int x = id[a], y = id[b];
    if(comp[x].size() < comp[y].size())
    {
        swap(a, b);
        swap(x, y);
    }
    for(int i:comp[y])
    {
        comp[x].push_back(i);
        id[i] = x;
    }
    return true;
}
long long gcd(long long a, long long b) {
    while (b != 0ll) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


long long costo(long long x, long long y)
{
    long long mcd=gcd(x,y);
    return (x/mcd)+(y/mcd);
}
long long escribiendo(long long C, vector<long long> &numeros)
{
    int n=int(numeros.size()), i, j;
    for(i=0; i<n; i++)
    {
        comp.push_back({i});
        id.push_back(i);
    }
    vector <pair<long long,pair<int,int>> > v;
    pair<long long,pair<int,int>>tup;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            tup.second.first=i;
            tup.second.second=j;
            tup.first=min(C,costo(numeros[i],numeros[j]));
            v.push_back(tup);
        }
    }
    sort(v.begin(), v.end());
    long long res = 0;
    for(i=0; i<int(v.size()); i++)
    {
        if(unionfind(v[i].second.first, v[i].second.second))
        {
            res += v[i].first;
        }
    }
    res+=C;
    return res;
}
