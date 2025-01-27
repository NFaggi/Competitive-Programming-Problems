//Link: https://juez.oia.unsam.edu.ar/task/34
//Score: 100/100
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=1e4+1;

vector<pair<ll,ll>>lib[MAXN];
vector<pair<ll,pair<ll,ll>>> obs[MAXN];

int main()
{
    ifstream cin ("ciudad.in");
    ofstream cout ("ciudad.out");
    ll n, g, o, i, a, b, c, op=0, cost=LLONG_MAX;
    cin >> n >> g >> o;
    for(i=0; i<g; i++)
    {
        cin >> a >> b >> c;
        lib[a].push_back({b,c});
        lib[b].push_back({a,c});
    }

    for(i=0; i<o; i++)
    {
        cin >> a >> b >> c;
        obs[a].push_back({b,{c,i+1}});
        obs[b].push_back({a,{c,i+1}});
    }

    priority_queue<pair<ll,pair<ll,ll>>>pq; //costo, destruidos, nodo
    vector<vector<ll>>dist(n+1,vector<ll>(3,LLONG_MAX));
    vector<vector<pair<ll,ll>>>destr(n+1,vector<pair<ll,ll>>(3));
    vector<vector<bool>>vis(n+1,vector<bool>(3,0));
    pq.push({0,{0,1}});
    while(pq.size())
    {
        pair<ll,pair<ll,ll>>p=pq.top();
        pq.pop();
        ll nod=p.second.second, des=p.second.first, cost=-p.first;
        if(vis[nod][des])
            continue;
        vis[nod][des]=1;
        for(auto k:lib[nod])
        {
            if(dist[k.first][des]>cost+k.second)
            {
                dist[k.first][des]=cost+k.second;
                destr[k.first][des]=destr[nod][des];
                pq.push({-dist[k.first][des],{des,k.first}});
            }
        }
        if(des<2)
        for(auto k:obs[nod])
        {
            if(dist[k.first][des+1]>cost+k.second.first)
            {
                dist[k.first][des+1]=cost+k.second.first;
                destr[k.first][des+1]=destr[nod][des];
                if(!des)
                    destr[k.first][des+1].first=k.second.second;
                else
                    destr[k.first][des+1].second=k.second.second;
                pq.push({-dist[k.first][des+1],{des+1,k.first}});
            }
        }
    }
    for(i=0; i<3; i++)
    {
        if(dist[n][i]<cost)
        {
            cost=dist[n][i];
            op=i;
        }
    }
    if(op==0)
    {
        cout << 1 << ' ' << cost;
    }
    else if(op==1)
    {
        cout << 2 << ' ' << destr[n][1].first << ' ' << cost;
    }
    else
    {
        cout << 3 << ' ' << destr[n][2].first << ' ' << destr[n][2].second << ' ' << cost;
    }
    return 0;
}
