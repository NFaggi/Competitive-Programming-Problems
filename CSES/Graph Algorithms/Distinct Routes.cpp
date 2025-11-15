#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define fr first
#define se second
#define pb push_back
using namespace std;
const int MAXN=501;
vector<ll>grafo[MAXN], grafo2[MAXN], cam[MAXN], vis2[MAXN];
ll fluj[MAXN][MAXN], pad[MAXN], act;
ll band=1, cant, fin, vis[MAXN], tim=1;
 
 
bool bfs()
{
    queue<ll>q;
    q.push(1);
    memset(pad,-1,sizeof(pad));
    while(sz(q))
    {
        ll nod=q.front();
        q.pop();
        for(auto k:grafo[nod])
        {
            if(pad[k]!=-1||fluj[nod][k]==0)
                continue;
            pad[k]=nod;
            q.push(k);
        }
    }
    if(pad[fin]==-1)
        return 0;
    return 1;
}
void dfs(ll nod)
{
    cam[act].pb(nod);
    if(!sz(grafo2[nod]))
        return;
    dfs(grafo2[nod].back());
    grafo2[nod].pop_back();
}
int main()
{
    ll n, m, a, b, nod, i;
    cin >> n >> m;
    vector<pair<ll,ll>>ars;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        ars.pb({a,b});
        fluj[a][b]++;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    fin=n;
    ll res=0;
    while(bfs())
    {
        ll mi=LLONG_MAX;
        queue<ll>q;
        q.push(fin);
        while(q.size())
        {
            nod=q.front();
            q.pop();
            if(nod==1)
                break;
            mi=min(mi,fluj[pad[nod]][nod]);
            nod=pad[nod];
            q.push(nod);
        }
        res+=mi;
        q.push(fin);
        while(q.size())
        {
            nod=q.front();
            q.pop();
            if(nod==1)
                break;
            fluj[nod][pad[nod]]+=mi;
            fluj[pad[nod]][nod]-=mi;
            nod=pad[nod];
            q.push(nod);
        }
    }
    for(i=0; i<m; i++)
    {
        a=ars[i].fr;
        b=ars[i].se;
        if(fluj[a][b]==0)
            grafo2[a].pb(b);
    }
 
    while(sz(grafo2[1]))
    {
        dfs(1);
        act++;
    }
    cout << res << '\n';
    for(i=0; i<res; i++)
    {
        cout << sz(cam[i]) << '\n';
        for(auto k:cam[i])
            cout << k << ' ';
        cout << '\n';
    }
    return 0;
}
