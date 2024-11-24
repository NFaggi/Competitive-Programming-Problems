//Link: https://juez.oia.unsam.edu.ar/task/144
//Score: 100/100
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
int id[MAXN];
vector<int>comps[MAXN];
bool unionfind(int a, int b)
{
    if(id[a]==id[b])
        return false;
    int x=id[a],y=id[b];
    if(comps[x].size()<comps[y].size())
        swap(x,y);
    for(auto k: comps[y])
    {
        comps[x].push_back(k);
        id[k]=id[x];
    }
    return true;
}
long long desalambrando(int N, vector<int> &a, vector<int> &b, vector<int> &costo)
{
    int m=int(a.size()), i;
    long long sum=0,tot=0;
    for(i=1; i<=N; i++)
    {
        id[i]=i;
        comps[i].push_back(i);
    }
    vector<vector<int>>v(m,vector<int>(3));
    for(i=0; i<m; i++)
    {
        tot=tot+costo[i];
        v[i][0]=-costo[i];
        v[i][1]=a[i];
        v[i][2]=b[i];
    }
    sort(v.begin(),v.end());
    for(i=0; i<m; i++)
    {
        if(unionfind(v[i][1],v[i][2]))
        {
            sum=sum+(-v[i][0]);
        }
    }
    return tot-sum;
}
