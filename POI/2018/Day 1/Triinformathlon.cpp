//Score: 100/100
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

const int MAXN=5e5+1;
ll a[MAXN], b[MAXN], c[MAXN], pos[MAXN], miPos[MAXN], pot=1, n,v2[3][MAXN];
vector<ll>seg,I,D;
bool dir(ll i, ll j)
{
    ll pts=0;
    if(a[i]<a[j])
        pts++;
    if(b[i]<b[j])
        pts++;
    if(c[i]<c[j])
        pts++;
    return pts>=2;
}

vector<ll>calc(ll l, ll r)
{   
    vector<ll>ret,iz,der;
    if(l==r)
    {
        ret={l};
        return ret;
    }

    ll mid=(l+r)/2, i=0, j=0;
    iz=calc(l,mid);
    der=calc(mid+1,r);

    while(i<sz(iz)&&j<sz(der))
    {
        if(dir(iz[i],der[j]))
        {
            ret.pb(iz[i]);
            i++;
        }
        else
        {
            ret.pb(der[j]);
            j++;
        }
    }
    while(i<sz(iz))
    {
        ret.pb(iz[i]);
        i++;
    }
    while(j<sz(der))
    {
        ret.pb(der[j]);
        j++;
    }
    return ret;
}

void ini()
{
    seg.resize(0);
    seg.resize(pot*2,n+1);
}

void update(ll nod, ll x)
{
    seg[nod]=min(seg[nod],x);
    nod/=2;
    while(nod>0)
    {
        seg[nod]=min(seg[nod*2],seg[nod*2+1]);
        nod/=2;
    }
}

ll cal(ll l, ll r, ll nod)
{
    if(I[nod]>r||D[nod]<l)
        return n+1;
    if(I[nod]>=l&&D[nod]<=r)
        return seg[nod];
    return min(cal(l,r,nod*2),cal(l,r,nod*2+1));
}

void calcab(ll xa, ll xb)
{
    ini();
    vector<pair<ll,pair<ll,ll>>>v;
    ll i, j=0;
    for(i=0; i<n; i++)
    {
        v.pb({-v2[xa][i],{v2[xb][i],i}});
    }
    sort(all(v));
    i=0;
    for(j=0; j<n; j++)
    {
        ll ult=v[j].fr;
        while(i<sz(v)&&ult>=v[i].fr)
        {
            update(v[i].se.fr+pot,pos[v[i].se.se]);
            i++;
        }
        miPos[v[j].se.se]=min(miPos[v[j].se.se],cal(v[j].se.fr+pot,pot*2-1,1));
    }
}

ll comps[MAXN], comp=1, vi[MAXN];
vector<ll>grafo[MAXN], invGrafo[MAXN];

vector<ll>topo;

void dfs(ll nod)
{
    vi[nod]=1;
    for(auto k:grafo[nod])
    {
        if(vi[k])
            continue;
        dfs(k);
    }
    topo.pb(nod);
}

void dfs2(ll nod)
{
    comps[nod]=comp;
    for(auto k:invGrafo[nod])
    {
        if(comps[k])
            continue;
        dfs2(k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, i, e, d, j;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
        v2[0][i]=a[i];
    }
    for(i=0; i<n; i++)
    {
        cin >> b[i];
        v2[1][i]=b[i];
    }
    for(i=0; i<n; i++)
    {
        cin >> c[i];
        v2[2][i]=c[i];
    }
    
    vector<ll>path=calc(0,n-1);
    for(i=0; i<sz(path); i++)
        miPos[path[i]]=pos[path[i]]=i;
    while(pot<n)
        pot*=2;
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }

    calcab(0,1);
    calcab(0,2);
    calcab(1,2);

    for(i=0; i<n; i++)
    {
        grafo[i].pb(path[miPos[i]]);
        if(pos[i]+1<n)
            grafo[i].pb(path[pos[i]+1]);
        invGrafo[path[miPos[i]]].pb(i);
        if(pos[i]+1<n)
            invGrafo[path[pos[i]+1]].pb(i);

    }
    for(i=0; i<n; i++)
    {
        if(!vi[i])
        {
            dfs(i);
        }
    }
    reverse(all(topo));
    for(i=0; i<n; i++)
    {
        if(!comps[topo[i]])
        {
            dfs2(topo[i]);
            comp++;
        }
    }
    cin >> q;
    while(q--)
    {
        cin >> e >> d;
        e--;d--;
        if(comps[e]<=comps[d])
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
    return 0;
}
