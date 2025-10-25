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
ll en[MAXN],ex[MAXN];
vector<ll>v;
 
bool vis[MAXN];
bool can[MAXN];
void dfs(ll nod)
{
    ll k;
    while(sz(grafo[nod]))
    {
        k=grafo[nod].back();
        grafo[nod].pop_back();
        dfs(k);
    }
    v.pb(nod);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, a, b, in=-1, fin=-1;
    cin >> n >> m;
    
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        en[b]++;
        ex[a]++;
        can[a]=1;
        can[b]=1;
    }
    bool pos=1;
    for(i=1; i<=n; i++)
    {
        if(en[i]+1==ex[i])
        {
            if(in==-1)
                in=i;
            else
                pos=0;
        }
        else if(en[i]==ex[i]+1)
        {
            if(fin==-1)
                fin=i;
            else
                pos=0;
        }
        else if(en[i]!=ex[i])
            pos=0;
    }
    if(!pos||fin!=n||in!=1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    dfs(in);
    reverse(all(v));
    for(i=0; i<sz(v); i++)
        vis[v[i]]=1;
    for(i=1; i<=n; i++)
        if(!vis[i]&&can[i])
            pos=0;
    if(!pos)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(auto k:v)
        cout << k << ' ';
    return 0;
}
