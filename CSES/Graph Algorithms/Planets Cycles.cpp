#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN=2e5+1;

ll grafo[MAXN], tam[MAXN], dist[MAXN], cic[MAXN], ciclo[MAXN], vis[MAXN], num;
void marcar(ll nod, ll fin)
{
    vis[nod]=2;
    ciclo[nod]=num;
    tam[num]++;
    if(nod==fin)
        return;
    marcar(grafo[nod],fin);
}

bool DFS(ll nod)
{
    vis[nod]=1;
    ll k=grafo[nod];
    if(vis[k]==0)
    {
        if(!DFS(k))
        {
            vis[nod]=2;
            return 0;
        }
    }
    else if(vis[k]==1)
    {
        num++;
        marcar(k,nod);
        vis[nod]=2;
        return 0;
    }
    vis[nod]=2;
    return 1;
}

void DFS2(ll nod)
{
    vis[nod]=3;
    if(ciclo[nod]!=0)
    {
        cic[nod]=ciclo[nod];
        dist[nod]=0;
        return;
    }
    ll k=grafo[nod];
    if(vis[k]!=3)
        DFS2(k);
    dist[nod]=dist[k]+1;
    cic[nod]=cic[k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, i;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        grafo[i]=x;
    }
    for(i=1; i<=n; i++)
        if(vis[i]==0)
            DFS(i);
    for(i=1; i<=n; i++)
    {
        if(vis[i]!=3)
            DFS2(i);
    }
    for(i=1; i<=n; i++)
    {
        cout << tam[cic[i]]+dist[i] << ' ';
    }
    return 0;
}
