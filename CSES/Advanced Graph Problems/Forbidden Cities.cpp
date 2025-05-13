#include <bits/stdc++.h>
using namespace std;
vector<int>vis,low;
vector<int>INcomps;
vector<vector<int>>grafo;
vector<vector<int>>arbol;
set<pair<int,int>>s2;
vector<bool>art;
vector<int>comps;
int act=0, nods=0, n;
stack<pair<int,int>>s;
map<int,int>m;
int comp=1,comps2=1;
 
const int MAXN = 200000;
const int LOG = 18;
 
int up[MAXN][LOG];
int depth[MAXN];
 
void DFS(int nod, int pad)
{
    INcomps[nod]=comps2;
    int hijos=0;
    act++;
    low[nod]=act;
    vis[nod]=act;
    for(auto k:grafo[nod])
    {
        if(vis[k]==-1)
        {
            hijos++;
            s.push({nod,k});
            DFS(k,nod);
            low[nod]=min(low[nod],low[k]);
            if(pad!=0&&low[k]>=vis[nod]||hijos>1&&pad==0)
            {
                if(m[nod]==0)
                {
                    m[nod]=++nods;
                }
                art[nod]=1;
                if(m[comp+n]==0)
                    m[comp+n]=++nods;
                while(s.top()!= make_pair(nod,k))
                {
                    comps[s.top().first]=comp;
                    comps[s.top().second]=comp;
                    s.pop();
                }
                comps[s.top().first]=comp;
                comps[s.top().second]=comp;
                s.pop();
                comp++;
                m[comp+n]=++nods;
            }
 
        }
        else if(k!=pad&&vis[k]<vis[nod])
        {
            s.push({nod,k});
            low[nod]=min(low[nod],vis[k]);
        }
    }
}
void dfsBin(int v, int parent)
{
    vis[v]=1;
    up[v][0] = parent;
    for (int i = 1; i < LOG; ++i)
    {
        if (up[v][i-1] != -1)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        else
        {
            up[v][i] = -1;
        }
    }
    for (int u : arbol[v])
    {
        if (u != parent&&vis[u]==0)
        {
            depth[u] = depth[v] + 1;
            dfsBin(u, v);
        }
    }
}
 
int kth_ancestor(int v, int k)
{
    for (int i = 0; i < LOG; ++i)
    {
        if (k & (1 << i))
        {
            v = up[v][i];
            if (v == -1) break;
        }
    }
    return v;
}
int actV=1;
void dfs3(int nod, int pad)
{
    vis[nod]=actV;
    for(auto k:arbol[nod])
    {
        if(k!=pad)
        {
            dfs3(k,nod);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m2, i, a, b, q, c;
    cin >> n >> m2 >> q;
    INcomps.resize(n+1,0);
    grafo.resize(n+1);
    vis.resize(n+1,-1);
    low.resize(n+1);
    comps.resize(n+1,0);
    art.resize(n+1,0);
    for(i=0; i<m2; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for(i=1; i<=n; i++)
    {
        if(vis[i]==-1)
        {
            DFS(i,0);
            while(!s.empty())
            {
                comps[s.top().first]=comp;
                comps[s.top().second]=comp;
                s.pop();
            }
            comp++;
            comps2++;
        }
    }
    int ma=0;
    arbol.resize(nods+1);
    vis.resize(nods+1,0);
    for(i=1; i<=n; i++)
    {
        if(art[i]==1)
        {
            for(auto k:grafo[i])
            {
                int a, b;
                a=m[i];
                if(art[k]!=1)
                {
                    b=m[comps[k]+n];
                    if(a>b)
                        swap(a,b);
                    s2.insert({a,b});
                }
            }
        }
    }
    for(auto k:s2)
    {
        arbol[k.first].push_back(k.second);
        arbol[k.second].push_back(k.first);
    }
    s2.clear();
    for(i=0; i<int(arbol.size()); i++)
    {
        if(vis[i]==0)
        {
            dfs3(i,0);
            actV++;
        }
    }
    for(i=1; i<=n; i++)
    {
        if(art[i]==1)
        {
            for(auto k:grafo[i])
            {
                int a, b;
                a=m[i];
                if(art[k]==1&&vis[m[i]]!=vis[m[k]])
                {
                    b=m[k];
                    if(a>b)
                        swap(a,b);
                    s2.insert({a,b});
                }
            }
        }
    }
    for (int i = 0; i < MAXN; ++i)
    {
        for (int j = 0; j < LOG; ++j)
        {
            up[i][j] = -1;
        }
    }
    for(auto k:s2)
    {
        arbol[k.first].push_back(k.second);
        arbol[k.second].push_back(k.first);
    }
    vis.resize(0);
    vis.resize(arbol.size(),0);
    for(i=1; i<int(arbol.size()); i++)
    {
        if(vis[i]==0)
        {
            depth[i] = 0;
            dfsBin(i, -1);
        }
    }
    while(q--)
    {
        bool pos=1;
        cin >> a >> b >> c;
        if(INcomps[a]!=INcomps[b]||a==c||b==c)
        {
            cout << "NO\n";
            continue;
        }
        if(INcomps[a]!=INcomps[c]||(comps[a]==comps[b])||art[c]==0)
        {
            cout << "YES\n";
            continue;
        }
        if(art[a])
            a=m[a];
        else
            a=m[comps[a]+n];
        if(art[b])
            b=m[b];
        else
            b=m[comps[b]+n];
        c=m[c];
        //cout << depth[a] << ' ' << depth[b] << ' ' << depth[c] << '\n';
        if(depth[a]<=depth[c]&&depth[b]<=depth[c])
        {
            cout << "YES\n";
            continue;
        }
        if(depth[b]>depth[c]&&depth[a]>depth[c])
        {
            if(kth_ancestor(b,(depth[b]-depth[c])-1)==kth_ancestor(a,(depth[a]-depth[c])-1))
            {
                cout << "YES\n";
                continue;
            }
        }
        if(depth[b]>depth[c])
        {
            if(kth_ancestor(b,depth[b]-depth[c])==c)
            {
                cout << "NO\n";
                continue;
            }
        }
        if(depth[a]>depth[c])
        {
            if(kth_ancestor(a,depth[a]-depth[c])==c)
            {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
    }
    return 0;
}
