//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/143
#include <bits/stdc++.h>
using namespace std;
vector<int>fentre(int(1e6)+1,0);
vector<long long>p(int(1e6)+1);
void update(long long u, long long x)
{
    fentre[u]+=x;
    if((u+(u&-u))<=p.size()-1)
    update(u+(u&-u),x);
}
void inicializar()
{
    p[0]=-1;
    for(int i=1; i<int(1e6)+1; i++)
    {
        p[i]=i-(i & -i);
        //update(i,v[i-1]);
    }
}
int f(long long k)
{
    if(k==0)
        return 0;
    return fentre[k]+f(p[k]);
}
void nuevoNumero(int x)
{
    update(x,1ll);
}
int contar(int a, int b)
{
    return (f(b) - f(a-1));
}
