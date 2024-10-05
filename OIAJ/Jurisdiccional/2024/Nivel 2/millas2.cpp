//Score: 100/100
#include <bits/stdc++.h>

using namespace std;
struct arista
{
    long long pesos, millas;
    int nodo;
};
vector<long long> millas(int N, vector<int> & a, vector<int> & b, vector<int> & d, vector<int> & m)
{
    int i, M=int(a.size());
    vector<long long>v(2);
    vector<vector<arista>>grafo(N+1);
    arista x;
    for(i=0; i<M; i++)
    {
        x.nodo=b[i];
        x.pesos=d[i];
        x.millas=m[i];
        if(x.millas!=-1)
            x.pesos=0;
        grafo[a[i]].push_back(x);
    }
    vector<pair<long long, long long>>dists(N+1,{LLONG_MAX,LLONG_MAX});
    vector<bool>proc(N+1,0);
    priority_queue<pair<long long, pair<long long, int>>>pq;
    dists[1]={0,0};
    pq.push({0,{0,1}});
    while(pq.size())
    {
        int nod=pq.top().second.second;
        pq.pop();
        if(proc[nod])
            continue;
        proc[nod]=1;
        for(auto k:grafo[nod])
        {
            int vec=k.nodo;
            if(k.millas!=-1)
            {
                if(dists[vec].first>dists[nod].first+k.pesos||(dists[vec].first==dists[nod].first+k.pesos&&dists[vec].second>dists[nod].second+k.millas))
                {
                    dists[vec].first=dists[nod].first+k.pesos;
                    dists[vec].second=dists[nod].second+k.millas;
                    pq.push({-dists[vec].first,{-dists[vec].second,vec}});
                }
            }
            else
            {
                if(dists[vec].first>dists[nod].first+k.pesos||(dists[vec].first==dists[nod].first+k.pesos&&dists[vec].second>dists[nod].second))
                {
                    dists[vec].first=dists[nod].first+k.pesos;
                    dists[vec].second=dists[nod].second;
                    pq.push({-dists[vec].first,{-dists[vec].second,vec}});
                }
            }
        }
    }
    v[0]=dists[N].first;
    v[1]=dists[N].second;
    return v;
}
