#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=1e5+1;
const int MOD=1e9+7;

ll n, A, B, C, D;

vector<pair<ll,ll>>grafo[MAXN];

void ab()
{
    priority_queue<pair<ll,ll>>pq;
    pq.push({0,1});
    vector<bool>vis(n+1,0);
    vector<ll>dist(n+1,LLONG_MAX),cant(n+1,0);
    ll nod, cost;
    dist[1]=0;
    cant[1]=1;
    while(pq.size())
    {
        nod=pq.top().second;
        pq.pop();
        if(vis[nod])
            continue;
        vis[nod]=1;
        for(auto k:grafo[nod])
        {
            if(vis[k.first])
                continue;
            if(dist[k.first]>dist[nod]+k.second)
            {
                dist[k.first]=dist[nod]+k.second;
                cant[k.first]=cant[nod];
                pq.push({-dist[k.first],k.first});
            }
            else if(dist[k.first]==dist[nod]+k.second)
            {
                cant[k.first]=(cant[k.first]+cant[nod])%MOD;
            }
        }
    }
    A=dist[n];
    B=cant[n];
}
void c()
{
    priority_queue<pair<ll,pair<ll,ll>>>pq;
    pq.push({0,{0,1}});
    vector<bool>vis(n+1,0);
    vector<ll>dist(n+1,LLONG_MAX),large(n+1,LLONG_MAX);
    ll nod, cost;
    dist[1]=0;
    large[1]=0;
    while(pq.size())
    {
        nod=pq.top().second.second;
        pq.pop();
        if(vis[nod])
            continue;
        vis[nod]=1;
        for(auto k:grafo[nod])
        {
            if(vis[k.first])
                continue;
            if(dist[k.first]>dist[nod]+k.second)
            {
                dist[k.first]=dist[nod]+k.second;
                large[k.first]=large[nod]+1ll;
                pq.push({-dist[k.first],{-large[k.first],k.first}});
            }
            else if(dist[k.first]==dist[nod]+k.second&&large[k.first]>large[nod]+1ll)
            {
                large[k.first]=large[nod]+1ll;
                pq.push({-dist[k.first],{-large[k.first],k.first}});
            }
        }
    }
    C=large[n];
}
void d()
{
    priority_queue<pair<ll,pair<ll,ll>>>pq;
    pq.push({0,{0,1}});
    vector<bool>vis(n+1,0);
    vector<ll>dist(n+1,LLONG_MAX),large(n+1,0);
    ll nod, cost;
    dist[1]=0;
    while(pq.size())
    {
        nod=pq.top().second.second;
        pq.pop();
        if(vis[nod])
            continue;
        vis[nod]=1;
        for(auto k:grafo[nod])
        {
            if(vis[k.first])
                continue;
            if(dist[k.first]>dist[nod]+k.second)
            {
                dist[k.first]=dist[nod]+k.second;
                large[k.first]=large[nod]+1ll;
                pq.push({-dist[k.first],{large[k.first],k.first}});
            }
            else if(dist[k.first]==dist[nod]+k.second&&large[k.first]<large[nod]+1ll)
            {
                large[k.first]=large[nod]+1ll;
                pq.push({-dist[k.first],{large[k.first],k.first}});
            }
        }
    }
    D=large[n];
}

int main()
{
    ll i, m, a, b, x;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> x;
        grafo[a].push_back({b,x});
    }

    ab();
    c();
    d();
    cout << A << ' ' << B << ' ' << C << ' ' << D;
    return 0;
}
