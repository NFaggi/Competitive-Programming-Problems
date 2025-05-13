#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>grafo,comps;
vector<int>ids;
int comp;
void uni(int a, int b)
{
    if(ids[a]==ids[b])
        return;
    a=ids[a];
    b=ids[b];    
    if(comps[a].size()<comps[b].size())
        swap(a,b);
    comp--;
    for(auto k:comps[b])
    {
        ids[k]=a;
        comps[a].push_back(k);
    }    
}
int main()
{
    int n, m, a, i, b, k;
    cin >> n >> m >> k;
    comp=n;
    grafo.resize(n+1);
    comps.resize(n+1);
    ids.resize(n+1);
    vector<pair<int,int>>q;
    for(i=1; i<=n; i++)
    {
        ids[i]=i;
        comps[i].push_back(i);
    }
    set<pair<int,int>>s;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        if(a>b)
        swap(a,b);
        s.insert({a,b});
    }
    
    while(k--)
    {
        cin >> a >> b;
        if(a>b)
        swap(a,b);
        q.push_back({a,b});
        auto it =s.find({a,b});
        s.erase(it);
    }
    for(auto k:s)
    {
        uni(k.first,k.second);
    }
    vector<int>res(q.size());
    for(i=int(q.size())-1; i>=0; i--)
    {
        res[i]=comp;
        uni(q[i].first,q[i].second);
    }
    for(i=0; i<int(q.size()); i++)
        cout << res[i] << ' ';
    return 0;
}
