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
const int LOG=19;
vector<ll>grafo[MAXN];

ll cant[MAXN], up[MAXN][LOG], depth[MAXN];
map<pair<ll,ll>,ll>m;

void inLCA(ll nod, ll pad)
{
    for(ll i=1; i<LOG; i++)
    {
        up[nod][i]=up[up[nod][i-1]][i-1];
    }
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        up[k][0]=nod;
        depth[k]=depth[nod]+1;
        inLCA(k,nod);
    }
}

ll k_ans(ll x, ll dif)
{
    for(ll i=0; i<LOG; i++)
    {
        if(1<<i&dif)
            x=up[x][i];
    }
    return x;
}

ll lca(ll a, ll b)
{
    if(depth[a]<depth[b])
        swap(a,b);
    if(a==b)
        return a;
    a=k_ans(a,depth[a]-depth[b]);
    if(a==b)
        return a;
    for(ll i=LOG-1; i>=0; i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}

ll dfs(ll nod, ll pad)
{
    ll hijos=cant[nod], x;
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        x=dfs(k,nod);
        m[mp(min(nod,k),max(nod,k))]=x;
        hijos+=x;
    }
    return hijos;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, a, b, q, c;
    cin >> n;
    vector<pair<ll,ll>>ars;
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
        ars.pb({min(a,b),max(a,b)});
    }
    depth[1]=1;
    inLCA(1,0);
    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        c=lca(a,b);
        cant[a]++;
        cant[b]++;
        cant[c]-=2;
    }
    dfs(1,0);
    for(auto k:ars)
    {
        cout << m[k] << ' ';
    }
    return 0;
}
