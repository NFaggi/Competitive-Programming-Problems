//Score: 100/100
#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
vector<long long> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m)
{
    vector<long long> res(2,LLONG_MAX);
    int n=N, h=int(a.size()), i;
    vector <vector <pair<int,pair <long long, int>> > > grafo(n+1);

    for(i=0; i<h; i++)
    {
        int x, y;
        long long z, l;
        x=a[i];
        y=b[i];
        z=d[i];
        l=m[i];
        grafo[x].push_back({y,{z,l}});
    }

    priority_queue <pair<long long, pair<int,int>> > pq;
    vector <vector<bool>> procesado(n+1, vector<bool>(1001,false));
    vector <vector<long long>> dist(n+1, vector<long long>(1001,INF));
    pq.push({0, {0,1}});
    dist[1][0] = 0;
    while(pq.size())
    {
        int nodo = pq.top().second.second, mil=-pq.top().second.first;
        pq.pop();
        if(procesado[nodo][mil])
            continue;
        procesado[nodo][mil] = true;
        for(auto par:grafo[nodo])
        {
            int vecino = par.first, cMil=par.second.second;
            long long costo = par.second.first;
            if(dist[vecino][mil] > dist[nodo][mil]+costo)
            {
                dist[vecino][mil] = dist[nodo][mil]+costo;
                pq.push({-dist[vecino][mil],{-mil,vecino}});
            }
            if(cMil>=0&&mil+cMil<=1000)
            {
                 if(dist[vecino][mil+cMil] > dist[nodo][mil])
                    {
                        dist[vecino][mil+cMil] = dist[nodo][mil];
                        pq.push({-dist[vecino][mil+cMil],{-(mil+cMil),vecino}});
                    }
            }
        }
    }
    for(i=0; i<=1000; i++)
    {
        if(dist[n][i]<res[0])
        {
            res[0]=dist[n][i];
            res[1]=i;
        }
    }
    return res;
}
