//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define LLONG_MAX INT_MAX
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second

using namespace std;
const int MAXN=1e5+1;
const int LOG=18;
vector<pair<ll,ll>>grafo[MAXN];
vector<ll>comp[MAXN], lcas[MAXN], seg, I, D;
unordered_map<ll,ll>ans[MAXN];
ll id[MAXN], up[MAXN][LOG], prof[MAXN], pot=1;

bool unionfind(ll a, ll b)
{
    if(id[a]==id[b])
        return 0;
    ll x=id[a],y=id[b];
    if(sz(comp[x])<sz(comp[y]))
        swap(x,y);
    for(auto k:comp[y])
    {
        comp[x].pb(k);
        id[k]=x;
    }
    return 1;
}

void DFS(ll nod, ll pad, ll pro)
{
    prof[nod]=pro;
    up[nod][0]=pad;
    for(ll i=1; i<LOG; i++)
        up[nod][i]=up[up[nod][i-1]][i-1];
    for(auto k:grafo[nod])
        if(k.fr!=pad)
            DFS(k.fr,nod,pro+1);
}
map<pair<ll,ll>,ll>ma;
ll calc(ll a, ll b)
{
    if(prof[a]<prof[b])
        swap(a,b);
    ll nodA=a, nodB=b, mi=LLONG_MAX;
    while(prof[nodA]>prof[nodB])
    {
        mi=min(ma[mp(nodA,up[nodA][0])],mi);
        nodA=up[nodA][0];
    }
    while(nodA!=nodB)
    {
        mi=min(ma[mp(nodA,up[nodA][0])],mi);
        nodA=up[nodA][0];

        mi=min(ma[mp(nodB,up[nodB][0])],mi);
        nodB=up[nodB][0];
    }
    return mi;
}

ll lca(ll a, ll b)
{
    ll i, j, dif;
    if(prof[a]<prof[b])
        swap(a,b);
    dif=prof[a]-prof[b];
    for(i=LOG-1; i>=0; i--)
    {
        j=1<<i;
        if(dif&j)
            a=up[a][i];
    }
    if(a==b)
        return a;
    for(i=LOG-1; i>=0; i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}


void update(ll nod, ll x)
{
    seg[nod]=x;
    nod/=2;
    while(nod>0)
    {
        seg[nod]=min(seg[nod*2],seg[nod*2+1]);
        nod/=2;
    }
}

ll segCalc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return LLONG_MAX;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    return min(segCalc(a,b,nod*2),segCalc(a,b,nod*2+1));
}

void DFSC(ll nod, ll pad, ll pro)
{
    ans[nod][nod]=LLONG_MAX;
    for(auto k:lcas[nod])
    {
        ll pr=prof[k]-1ll;
        ans[nod][k]=segCalc(pot+pr,pot+pro,1);
    }
    for(auto k:grafo[nod])
    {
        if(k.fr!=pad)
        {
            update(pro+pot,k.se);
            DFSC(k.fr,nod,pro+1);
        }
    }
    update(pro+pot,LLONG_MAX);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, q, a, b, c;
    cin >> n >> m;
    for(i=1; i<=n; i++)
    {
        id[i]=i;
        comp[i].pb(i);
    }
    vector<vector<ll>>conexs(m,vector<ll>(3));
    for(i=0; i<m; i++)
    {
        cin >> conexs[i][1] >> conexs[i][2] >> conexs[i][0];
    }
    sort(all(conexs));
    for(i=m-1; i>=0; i--)
        if(unionfind(conexs[i][1],conexs[i][2]))
        {
            grafo[conexs[i][1]].pb({conexs[i][2],conexs[i][0]});
            grafo[conexs[i][2]].pb({conexs[i][1],conexs[i][0]});
            ma[mp(conexs[i][1],conexs[i][2])]=conexs[i][0];
            ma[mp(conexs[i][2],conexs[i][1])]=conexs[i][0];
        }
    DFS(1,0,1);
    cin >> q;
    vector<pair<ll,ll>>querys;
    vector<ll>lcs;
    while(q--)
    {
        cin >> a >> b;
        querys.pb({a,b});
        ll lc=lca(a,b);
        lcs.pb(lc);
        if(lc!=a)
            lcas[a].pb(lc);
        if(lc!=b)
            lcas[b].pb(lc);
    }
    while(pot<n)
        pot*=2;
    seg.resize(pot*2,LLONG_MAX);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot*2; i++)
        D[i]=I[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    DFSC(1,0,0);
    for(i=0; i<sz(querys); i++)
    {
        cout << min(ans[querys[i].fr][lcs[i]],ans[querys[i].se][lcs[i]])-1ll << '\n';
    }
    return 0;
}
