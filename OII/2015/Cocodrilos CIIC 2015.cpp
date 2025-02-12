//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN=1e5+1;

vector<ll> grafo[MAXN];
ll vis[MAXN], ciclo[MAXN], hijo[MAXN], pad[MAXN], acum[MAXN], tim[MAXN], ult[MAXN];

void marcar(ll k, ll nod)
{
    ciclo[k]=1;
    if(k==nod)
        return;
    marcar(hijo[k],nod);
}

void dfs(ll nod)
{
    vis[nod]=1;

    ll k=hijo[nod];
    if(vis[k]==0)
        dfs(k);
    else if(vis[k]==1)
        marcar(k,nod);

    vis[nod]=2;
}

void dfs2(ll nod, ll env, ll dist, ll ori)
{
    acum[env]+=10ll;
    if(tim[env]<dist)
    {
        tim[env]=dist;
        ult[env]=ori;
    }
    for(auto k:grafo[nod])
    {
        dfs2(k,pad[env],dist+1, ori);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, i, x, ma=0, ti=0, ul;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        hijo[i]=x;
        grafo[x].pb(i);
    }
    for(i=1; i<=n; i++)
    {
        if(vis[i]==0)
            dfs(i);
    }
    for(i=1; i<=n; i++)
        if(ciclo[i])
        {
            acum[i]=10;
            ult[i]=i;
            pad[hijo[i]]=i;
        }

    for(i=1; i<=n; i++)
        if(ciclo[i])
            for(auto k:grafo[i])
                if(ciclo[k]!=1)
                    dfs2(k,i,1,i);

    for(i=1; i<=n; i++)
    {
        if(ma<acum[i])
        {
            ma=acum[i];
            ti=tim[i];
            ul=ult[i];
        }
        else if(ma==acum[i]&&ti>tim[i])
        {
            ti=tim[i];
            ul=ult[i];
        }
    }
    cout << ti*5ll << ' ' << ma << ' ' << ul;
    return 0;
}
