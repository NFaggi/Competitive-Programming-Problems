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
    ll x, y;

    Point(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }

    ll cross(const Point &p) const
    {
        return x * p.y - y * p.x;
    }

    ll cross(const Point &p, const Point &q) const
    {
        return (p - *this).cross(q - *this);
    }

    int half() const
    {
        return int(y < 0 || (y == 0 && x < 0));
    }
};

vector<vector<int>> find_faces(vector<Point> vertices, vector<vector<int>> adj)
{
    int n = vertices.size();
    vector<vector<char>> used(n);
    for (int i = 0; i < n; i++)
    {
        used[i].resize(adj[i].size());
        used[i].assign(adj[i].size(), 0);
        auto compare = [&](int l, int r)
        {
            Point pl = vertices[l] - vertices[i];
            Point pr = vertices[r] - vertices[i];
            if (pl.half() != pr.half())
                return pl.half() < pr.half();
            return pl.cross(pr) > 0;
        };
        sort(adj[i].begin(), adj[i].end(), compare);
    }

    vector<vector<int>> faces;
    for (int i = 0; i < n; i++)
    {
        for (int edge_id = 0; edge_id < adj[i].size(); edge_id++)
        {
            if (used[i][edge_id])
                continue;

            vector<int> face;
            int v = i;
            int e = edge_id;

            while (!used[v][e])
            {
                used[v][e] = true;
                face.push_back(v);
                int u = adj[v][e];
                int e1 = lower_bound(adj[u].begin(), adj[u].end(), v, [&](int l, int r)
                                     {
                    Point pl = vertices[l] - vertices[u];
                    Point pr = vertices[r] - vertices[u];
                    if (pl.half() != pr.half())
                        return pl.half() < pr.half();
                    return pl.cross(pr) > 0; }) -
                         adj[u].begin();
                e1 = (e1 + 1) % adj[u].size();
                v = u;
                e = e1;
            }

            reverse(face.begin(), face.end());
            Point p1 = vertices[face[0]];
            ll sum = 0;
            for (int j = 0; j < (int)face.size(); ++j)
            {
                Point p2 = vertices[face[j]];
                Point p3 = vertices[face[(j + 1) % face.size()]];
                sum += (p2 - p1).cross(p3 - p2);
            }

            if (sum <= 0)
                faces.insert(faces.begin(), face);
            else
                faces.emplace_back(face);
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
