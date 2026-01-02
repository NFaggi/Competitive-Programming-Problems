//Link: https://www.spoj.com/problems/LUCKY/
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN = 1e5 + 1;

vector<ll> grafo[MAXN];

set<int>comps[MAXN];
ll vis[MAXN], low[MAXN], PA[MAXN], prof[MAXN], act, comp=1;
stack<pair<ll,ll>>p;
void DFS(ll nod, ll pad)
{
    ll hijos=0;
    vis[nod]=++act;
    low[nod]=vis[nod];
    for(auto k:grafo[nod])
    {
        if(vis[k]==0)
        {
            p.push({nod,k});
            hijos++;
            DFS(k,nod);
            low[nod] = min(low[nod], low[k]);
            if((hijos>1&&pad==0)||(pad!=0&&low[k]>=vis[nod]))
            {
                PA[nod]=1;
                while(p.top()!=make_pair(nod,k))
                {
                    comps[comp].insert(p.top().first);
                    comps[comp].insert(p.top().second);
                    p.pop();
                }
                comps[comp].insert(p.top().first);
                comps[comp].insert(p.top().second);
                p.pop();
                comp++;
            }
        }
        else if(k != pad) {
            if(vis[k] < vis[nod]) 
                p.push({nod,k});
            low[nod] = min(low[nod], vis[k]);
        }
    }
}

bool dfs(ll nod, ll pad)
{
    prof[nod]=prof[pad]+1;
    for(auto k:grafo[nod])
    {
        if(k==pad||comps[act].find(k)==comps[act].end())
            continue;
        if(prof[k])
        {
            if ((prof[nod]+prof[k]+1)%2)
                return 1;
        }
        else if(dfs(k,nod))
            return 1;
    }
    return 0;
}

void init()
{
    ll i;
    comp=1;
    act=0;
    memset(vis,0,sizeof(vis));
    memset(low,0,sizeof(low));
    memset(PA,0,sizeof(PA));
    memset(prof,0,sizeof(prof));
    while(sz(p))
        p.pop();
    for (i = 0; i < MAXN; i++)
    {
        grafo[i].resize(0);
        comps[i].clear();
    }
}

void solve()
{
    init();
    ll n, m, i, a, b;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            DFS(i, 0);
            if (!p.empty())
            {
                while (!p.empty())
                {
                    comps[comp].insert(p.top().first);
                    comps[comp].insert(p.top().second);
                    p.pop();
                }
                comp++;
            }
        }
    }
    set<ll>s;
    for(act=1; act<comp; act++)
    {
        if(sz(comps[act])==3||(sz(comps[act])>3&&dfs(*comps[act].begin(),0)))
            for(auto k:comps[act])
                s.insert(k);
        for(auto k:comps[act])
                prof[k]=0;
    }
    cout << sz(s) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
