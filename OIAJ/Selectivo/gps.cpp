//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/63
#include <bits/stdc++.h>

using namespace std;
long long INF = LLONG_MAX;

vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo)
{
    vector <vector <int > > grafo(N + 1);

    for (int i = 0; i < M; i++)
    {
        grafo[origen[i]].push_back(i);
    }

    priority_queue <pair<long long, int> > pq;
    vector <int> vueltas(N+1, 0);
    vector<long long>res;
    pq.push({ 0, comienzo });
    while (pq.size())
    {
        int nodo = pq.top().second;
        long long dis = -pq.top().first;
        vueltas[nodo]++;
        if (nodo == fin)
        {
            res.push_back(-pq.top().first);
        }
        pq.pop();
        if(vueltas[nodo]>K)
            continue;
        for (auto i : grafo[nodo])
        {
            int vecino = destino[i];
            long long costo = tiempo[i];
            if(vueltas[vecino]<=K)
            {
                pq.push({ -(dis+costo), vecino });
            }
        }
        if (res.size() == K)
            break;
    }
    return res;
}
