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

ll id[MAXN];
vector<ll>comp[MAXN];

vector<ll>grafo[MAXN];
map<ll,vector<ll>>gC[MAXN];

void unir(ll a, ll b)
{
    ll x=id[a], y=id[b];
    if(x==y)
        return;
    if(sz(comp[x])<sz(comp[y]))
        swap(x,y);
    
    for(auto k:comp[y])
    {
        id[k]=x;
        comp[x].pb(k);
    }
}

pair<ll,ll>p;

ll vis[MAXN], act;

ll dfs(ll nod)
{
    ll cant=sz(comp[nod]);
    vis[nod]=act;
    for(auto k:gC[nod][p.se])
    {
        if(vis[k]==act)
            continue;
        swap(p.fr,p.se);
        cant+=dfs(k);
        swap(p.fr,p.se);
    }
    gC[nod][p.se].resize(0);
    return cant;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, i, a, b;
    cin >> n >> m;
    vector<ll>c(n);
    for(i=0; i<n; i++)
    {
        id[i]=i;
        comp[i]={i};
        cin >> c[i];
    }

    vector<pair<ll,ll>>ars;

    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        ars.pb({a,b});
        grafo[a].pb(b);
        grafo[b].pb(a);
        if(c[a]==c[b])
            unir(a,b);
    }


    ll ma=0;

    for(i=0; i<n; i++)
    {
        ma=max(ma,1ll*sz(comp[id[i]]));
        for(auto &k:grafo[i])
            if(id[i]!=id[k])
                gC[id[i]][c[k]].pb(id[k]);
    }

    for(auto k:ars)
    {
        p={c[k.fr],c[k.se]};
        act++;
        ma=max(ma,dfs(id[k.fr]));
    }
    
    cout << ma;
    return 0;
}
