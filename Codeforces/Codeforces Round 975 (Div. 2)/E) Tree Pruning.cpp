//Link: https://codeforces.com/problemset/problem/2019/E
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll maxLevel, cant;
vector<vector<ll>>grafo,levels;
vector<ll>prefix,vis,pads,hijos,prof;
void dfs(ll nod, ll pad, ll lev)
{
    pads[nod]=pad;
    bool hoja=1;
    prof[nod]=lev;
    prefix[lev]++;
    for(auto k:grafo[nod])
    {
        if(k!=pad)
        {
            hoja=0;
            hijos[nod]++;
            dfs(k,nod,lev+1);
        }
    }
    if(hoja)
        levels[lev].push_back(nod);
    maxLevel=max(maxLevel,lev);        
}

void borrar(ll nod)
{
    if(nod==0)
        return;
    if(vis[nod])
        return;
    if(hijos[nod]>0)
        return;        
    vis[nod]=1;
    hijos[pads[nod]]--;
    cant--;
    borrar(pads[nod]);    
}

void solve()
{
    ll n, a, b, i, mi=LLONG_MAX;
    cin >> n;
    grafo.resize(0);
    grafo.resize(n+1);
    levels.resize(0);
    levels.resize(n+1);
    vis.resize(0);
    vis.resize(n+1,0);
    pads.resize(0);
    pads.resize(n+1,0);
    hijos.resize(0);
    hijos.resize(n+1,0);
    prefix.resize(0);
    prefix.resize(n+10,0);
    prof.resize(0);
    prof.resize(n+1,0);
    cant=n;
    maxLevel=0;
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    
    dfs(1,0,1);
    
    for(i=n-1; i>=0; i--)
        prefix[i]+=prefix[i+1];
    for(i=0; i<=maxLevel; i++)
    {
        for(auto k:levels[i])
            borrar(k);
        mi=min(mi,n-cant+prefix[i+2]);
    }    
  cout << mi << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}