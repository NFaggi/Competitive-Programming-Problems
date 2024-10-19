//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/97
#include <bits/stdc++.h>

using namespace std;
vector<long long>I,D,seg;
void update(long long x)
{
    seg[x]++;
    x/=2;
    while(x>0)
    {
        seg[x]=seg[x*2]+seg[x*2+1];
        x/=2;
    }
}
long long calc(long long a, long long b, long long nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    return calc(a,b,nod*2)+calc(a,b,nod*2+1);        
}
long long plantas(vector<int> &h)
{
    long long n=int(h.size()),i, tot=0, pot=1;
    vector<pair<long long, long long>>v;
    while(pot<n)
        pot*=2;
    I.resize(pot*2);
    D.resize(pot*2);
    seg.resize(pot*2,0);    
    for(i=0; i<n; i++)
    {
        v.push_back({-h[i],i});
    }
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    sort(v.begin(),v.end());
    for(i=0; i<n; i++)
    {
        tot+=min(calc(pot,v[i].second+pot,1),calc(v[i].second+pot,int(I.size())-1,1));
        update(v[i].second+pot);
    }
    return tot;
}