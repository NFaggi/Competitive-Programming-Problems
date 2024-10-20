//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/129
#include <bits/stdc++.h>
using namespace std;
const int MOD = 112345687;

long long pot2(long long b, long long a=2)
{
    long long ans=1;
    while(b>0)
    {
        if((b&1)>0)
        {
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
long long inv(long long a)
{
    long long res = pot2(MOD-2,a);
    return res;
}
int toriis(int N, vector<int> &inicio, vector<int> &fin, vector<long long> &cantidad) {
    vector<vector<pair<long long, long long>>> grafo(N + 1);
    vector<long long> v(N + 1, 0);
    vector<pair<long long,long long>> v2(N + 1, {0,0});

    for (int i = 0; i < inicio.size(); i++) {
        grafo[inicio[i]].push_back({fin[i], cantidad[i]});
        v[fin[i]]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (v[i] == 0) {
            v2[i] = {0,1};
            q.push(i);
        }
    }

    while (!q.empty()) {
        int nod = q.front();
        q.pop();
        for (auto k : grafo[nod]) {
            long long pot = pot2(k.second), po2=pot2(k.second-1);
            if(pot>1ll)
            {
                v2[k.first].first = (v2[k.first].first+(v2[nod].first*pot)%MOD)%MOD;
                v2[k.first].first = (v2[k.first].first+(v2[nod].second*po2)%MOD)%MOD;
            }
            else
            {
                v2[k.first].first=(v2[k.first].first+v2[nod].first)%MOD;
                v2[k.first].second=(v2[k.first].second+v2[nod].second)%MOD;
            }
            v[k.first]--;
            if (v[k.first] == 0)
                q.push(k.first);
        }
    }

    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        if (grafo[i].empty()) {
            sum = (sum + v2[i].first) % MOD;
            sum = (sum + v2[i].second) % MOD;
        }
    }
    return (sum)%MOD;
}
