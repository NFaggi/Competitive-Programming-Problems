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

const int MAXN=2e5+6;
const int LOG=19;

vector<ll> grafo[MAXN];

ll v[MAXN], nsz[MAXN], up[MAXN][LOG], act=0, n, id[MAXN], depth[MAXN], tp[MAXN], seg[MAXN*2];

void update(ll nod, ll x)
{
    seg[nod]=x;
    nod/=2;
    while(nod>0)
    {
        seg[nod]=max(seg[nod*2],seg[nod*2+1]);
        nod/=2;
    }
}

ll dfs_sz(ll nod, ll pad)
{
    nsz[nod]=1;
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        up[k][0]=nod;
        nsz[nod]+=dfs_sz(k,nod);
    }
    return nsz[nod];
}

void dfs_hld(ll nod, ll pad, ll top)
{
    id[nod]=act++;
    tp[nod]=top;
    update(id[nod]+n,v[nod]);
    ll masz=0, hc=0;
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        if(masz<nsz[k])
        {
            masz=nsz[k];
            hc=k;
        }
    }
    if(hc==0)
        return;
    dfs_hld(hc,nod,top);
    for(auto k:grafo[nod])
    {
        if(k==pad||k==hc)
            continue;
        dfs_hld(k,nod,k);
    }
}

void init_lca(ll nod, ll pad)
{
    depth[nod]=depth[pad]+1;
    for(ll i=1; i<LOG; i++)
        up[nod][i]=up[up[nod][i-1]][i-1];
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        init_lca(k,nod);
    }
}

ll kth_ancestor(ll v, ll k) {
    for (ll i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            v = up[v][i];
            if (v == -1) break;
        }
    }
    return v;
}


ll lca(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);

    ll diff = depth[u] - depth[v];
    u = kth_ancestor(u, diff);

    if (u == v) return u;

    for (ll i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

ll calc(ll l, ll r)
{
    ll L=0, R=0;
    for(; l < r; l /= 2, r /= 2)
    {
        if(l%2!=0) L = max(L, seg[l++]);
        if(r%2!=0) R = max(seg[--r],R);
    }
    return max(L,R);
}

ll path(ll a, ll b)
{
    ll ma=0;
    while(a!=b)
    {
        if(tp[a]==a)
        {
            ma=max(ma,v[a]);
            a=up[a][0];
        }
        else if(depth[tp[a]]>depth[b])
        {
            ma=max(calc(id[tp[a]]+n,id[a]+n+1),ma);
            a=tp[a];
        }
        else
        {
            ma=max(calc(id[b]+1+n,id[a]+n+1),ma);
            break;
        }
    }
    return ma;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, i, a, b, x, c;
    cin >> n >> q;
    for(i=1; i<=n; i++)
        cin >> v[i];
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    
    dfs_sz(1,0);
    dfs_hld(1,0,1);
    init_lca(1,0);
    while(q--)
    {
        cin >> x >> a >> b;
        if(x==1)
        {
            update(id[a]+n,b);
            v[a]=b;
        }
        else
        {
            c=lca(a,b);
            cout << max(max(path(a,c),path(b,c)),v[c]) << '\n';
        }
    }
    return 0;
}