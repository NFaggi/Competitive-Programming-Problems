//Link: https://juez.oia.unsam.edu.ar/task/169
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define fr first
#define se second
using namespace std;
struct Point
{
    ll x=0, y=0;
    int half() const
    {
        return int(y<0||(x<0&&y==0));
    }
};

ll cruz(Point a, Point b)
{
    return a.x*b.y-a.y*b.x;
}

Point c;
vector<Point> ver;
bool comp(const int A, const int B)
{
    Point a=ver[A], b=ver[B];
    a.x-=c.x;
    b.x-=c.x;
    a.y-=c.y;
    b.y-=c.y;
    if(a.half()!=b.half())
        return a.half()<b.half();
    return cruz(a,b)>0;
}

vector<vector<int>>find_faces(vector<Point>vert, vector<vector<int>>grafo)
{
    ver=vert;
    ll i, n=sz(vert), j;
    vector<vector<bool>>vis(n);
    for(i=0; i<n; i++)
    {
        vis[i].resize(sz(grafo[i]),0);
        c=vert[i];
        sort(all(grafo[i]),comp);
    }
    vector<vector<int>>faces;
    for(i=0; i<n; i++)
    {
        for(j=0; j<sz(grafo[i]); j++)
        {
            if(vis[i][j])
                continue;
            vector<int>face;
            ll v=i, e=grafo[i][j], e1=j;
            while(!vis[v][e1])
            {
                e=grafo[v][e1];
                vis[v][e1]=1;
                face.pb(v);
                c=vert[e];
                e1=lower_bound(all(grafo[e]),v,comp)-grafo[e].begin();
                v=e;
                e1=(e1+1)%sz(grafo[e]);
                e=grafo[v][e1];
            }
            reverse(all(face));
            ll sum=0;
            Point in=vert[face[0]];
            for(ll k=0; k<sz(face); k++)
            {
                ll sig=(k+1)%sz(face);
                Point a=vert[face[k]], b=vert[face[sig]];
                b.x-=a.x;
                b.y-=a.y;
                a.x-=in.x;
                a.y-=in.y;
                sum+=cruz(a,b);
            }
            if(sum<=0)
            {
                reverse(all(faces));
                faces.pb(face);
                reverse(all(faces));
            }
            else
                faces.pb(face);
            
        }
    }
    return faces;
}

vector<vector<ll>>grafo2;
vector<bool>vis2;

void dfs(ll nod)
{
    vis2[nod]=1;
    for(auto k:grafo2[nod])
    {
        if(vis2[k])
            continue;
        dfs(k);
    }
}

pair<ll,ll>mp(ll a, ll b)
{
    return {min(a,b),max(a,b)};
}

vector<int> pompeya(vector<int> &x, vector<int> &y, vector<int> &a, vector<int> &b, vector<int> &t)
{
    ll i, n = sz(x), m = sz(a);
    vector<Point> vert(n);
    Point p;
    for (i = 0; i < n; i++)
    {
        p.x = x[i];
        p.y = y[i];
        vert[i] = p;
    }
    vector<vector<int>> grafo(sz(x));
    set<pair<ll,ll>>tip;
    for (i = 0; i < m; i++)
    {
        grafo[a[i]].pb(b[i]);
        grafo[b[i]].pb(a[i]);
        if(t[i])
            tip.insert(mp(a[i], b[i]));
    }

    vector<vector<int>> faces = find_faces(vert, grafo);
    vector<set<ll>> grafoDual(sz(faces));
    map<pair<ll, ll>, set<ll>> fArs;
    for (i = 0; i < sz(faces); i++)
    {
        for (ll j = 0; j < sz(faces[i]); j++)
        {
            ll sig = (j + 1) % sz(faces[i]);
            auto it=tip.find(mp(faces[i][j], faces[i][sig]));
            if (it!=tip.end())
                continue;
            fArs[mp(faces[i][j], faces[i][sig])].insert(i);
        }
    }

    for (i = 0; i < sz(faces); i++)
    {
        for (ll j = 0; j < sz(faces[i]); j++)
        {
            ll sig = (j + 1) % sz(faces[i]);
            auto it=tip.find(mp(faces[i][j], faces[i][sig]));
            if (it!=tip.end())
                continue;
            for (auto k : fArs[{faces[i][j], faces[i][sig]}])
            {
                if (k == i)
                    continue;
                grafoDual[i].insert(k);
                grafoDual[k].insert(i);
            }
        }
    }

    queue<ll> q, nq;
    vector<ll> vis(sz(faces), 0);
    vis[0] = 1;
    nq.push(0);
    int cant = 0;
    set<pair<ll, ll>> s;
    while (nq.size())
    {
        swap(nq, q);
        while (q.size())
        {
            ll nod = q.front();
            q.pop();
            for (auto k : grafoDual[nod])
            {
                if (!vis[k])
                {
                    nq.push(k);
                    vis[k] = 1;
                    for (i = 0; i < sz(faces[k]); i++)
                    {
                        ll sig = (i + 1) % sz(faces[k]);
                        s.insert(mp(faces[k][i], faces[k][sig]));
                    }
                }
            }
        }
        cant++;
    }
    for (i = 0; i < sz(faces[0]); i++)
    {
        ll sig = (i + 1) % sz(faces[0]);
        auto it=
        s.insert(mp(faces[0][i], faces[0][sig]));
    }
    for(auto k:tip)
    {
        auto it=s.find(k);
        if(it!=s.end())
            s.erase(k);
    }
    ll ars2=sz(a)-(sz(s)), nods=0, comps=0;
    grafo2.resize(n);
    vis2.resize(n,0);
    for(i=0; i<m; i++)
    {
        auto it=s.find(mp(a[i],b[i]));
        if(it==s.end())
        {
            grafo2[a[i]].pb(b[i]);
            grafo2[b[i]].pb(a[i]);
        }
    }
    for(i=0; i<n; i++)
    {
        if(sz(grafo2[i]))
        {
            nods++;
            if(vis2[i]==0)
            {
                comps++;
                dfs(i);
            }
        }
    }
    return {cant - 1, int(comps-nods+ars2)};
}
