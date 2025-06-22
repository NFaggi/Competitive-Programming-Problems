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

const int MAXN=5e5+1;
const int LOG=20;

vector<pair<ll,ll>>grafo[MAXN];
ll ma1[MAXN], ma2[MAXN], ma3[MAXN]; ///Caminos rectos hacia abajo mas largos
ll p1[MAXN], p2[MAXN], p3[MAXN]; ///A que nodo se dirige el camino mas largo

ll ma4[MAXN]; ///Camino mas largo que se puede armar con los nodos arriba mio e incluyendo a este nodo

ll maU[MAXN]; ///Camino mas largo que hacen los de arriba sin usar tus hijos

ll ma5[MAXN], ma6[MAXN]; ///Camino mas largo de tus hijos
ll p5[MAXN], p6[MAXN]; ///en que nodo esta ese camino mas largo


ll ma7[MAXN]; ///Armar ma5
ll dfs(ll nod, ll pad)
{
    ll x;
    for(auto k:grafo[nod])
    {
        if(k.fr==pad)
            continue;
        x=dfs(k.fr,nod)+k.se;
        if(ma5[nod]<ma7[k.fr])
        {
            ma6[nod]=ma5[nod];
            p6[nod]=p5[nod];
            ma5[nod]=ma7[k.fr];
            p5[nod]=k.fr;
        }
        else if(ma6[nod]<ma7[k.fr])
        {
            ma6[nod]=ma7[k.fr];
            p6[nod]=k.fr;
        }
        if(ma1[nod]<x)
        {
            ma3[nod]=ma2[nod];
            p3[nod]=p2[nod];

            ma2[nod]=ma1[nod];
            p2[nod]=p1[nod];

            ma1[nod]=x;
            p1[nod]=k.fr;
        }
        else if(ma2[nod]<x)
        {
            ma3[nod]=ma2[nod];
            p3[nod]=p2[nod];

            ma2[nod]=x;
            p2[nod]=k.fr;
        }
        else if(ma3[nod]<x)
        {
            ma3[nod]=x;
            p3[nod]=k.fr;
        }
    }
    ma7[nod]=max(ma5[nod],ma1[nod]+ma2[nod]);
    return ma1[nod];
}

void dfs2(ll nod, ll pad, ll ant, ll maA)
{
    ll x, m;
    ma4[nod]=ant;
    maU[nod]=maA;
    ll mA;
    for(auto k:grafo[nod])
    {
        if(k.fr==pad)
            continue;
        if(k.fr==p1[nod])
            m=ma2[nod];
        else
            m=ma1[nod];
        x=m+k.se;
        x=max(x,ant+k.se);

        if(k.fr==p1[nod])
            mA=ma2[nod]+ma3[nod];
        else if(k.fr==p2[nod])
            mA=ma1[nod]+ma3[nod];
        else
            mA=ma1[nod]+ma2[nod];
        mA=max(mA,m+ant);
        if(k.fr==p5[nod])
            mA=max(mA,ma6[nod]);
        else
            mA=max(mA,ma5[nod]);
        dfs2(k.fr,nod,x,max(mA,maA));
    }
}

ll bin[MAXN][LOG], dep[MAXN], pads[MAXN];

void in(ll nod, ll pad)
{
    pads[nod]=pad;
    for(ll i=1; i<LOG; i++)
    {
        bin[nod][i]=bin[bin[nod][i-1]][i-1];
    }
    for(auto k:grafo[nod])
    {
        if(k.fr==pad)
            continue;
        dep[k.fr]=dep[nod]+1;
        bin[k.fr][0]=nod;
        in(k.fr,nod);
    }
}

ll k_ans(ll a, ll x)
{
    if(x==0)
        return a;
    for(ll i=0; i<LOG; i++)
    {
        if((1<<i)&x)
            a=bin[a][i];
    }
    return a;
}

ll lca(ll a, ll b)
{
    if(a==b)
        return a;
    if(dep[a]<dep[b])
        swap(a,b);
    a=k_ans(a,abs(dep[b]-dep[a]));
    if(a==b)
        return a;
    for(ll i=LOG-1; i>=0; i--)
    {
        if(bin[a][i]!=bin[b][i])
        {
            a=bin[a][i];
            b=bin[b][i]; 
        }
    }
    return bin[a][0];
}

ll calc(ll nod, ll ant)
{
    if(pads[nod]==ant)
        return ma7[nod];
    ll ans=maU[nod];
    if(ant!=p1[nod])
        ans=max(ans,ma4[nod]+ma1[nod]);
    else
        ans=max(ans,ma4[nod]+ma2[nod]);
    if(ant==p1[nod])
        ans=max(ans,ma2[nod]+ma3[nod]);
    else if(ant==p2[nod])
        ans=max(ans,ma1[nod]+ma3[nod]);
    else
        ans=max(ans,ma1[nod]+ma2[nod]);
    if(ant!=p5[nod])
        ans=max(ans,ma5[nod]);
    else
        ans=max(ans,ma6[nod]);
    return ans;
}

ll calcNod(ll a, ll b, ll c, ll pos) {
    ll da = dep[a] - dep[c];
    if (pos <= da)
        return k_ans(a, pos);
    else
        return k_ans(b, (dep[b] - dep[c]) - (pos - da));
}

ll calc2(ll a, ll b, ll pos, ll c, ll dis, ll &v1, ll &v2)
{
    ll z = calcNod(a, b, c, pos);
    ll x = (pos > 0) ? calcNod(a, b, c, pos - 1) : a;
    ll y = (pos + 1 <= dis) ? calcNod(a, b, c, pos + 1) : b;
    v1 = calc(x, z);
    v2 = calc(y, z);
    return abs(v1 - v2);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b, c, i, q, d, auA, auB, dis;
    cin >> n;
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b >> c;
        grafo[a].pb({b,c});
        grafo[b].pb({a,c});
    }
    dfs(1,0);
    dfs2(1,0,0,0);
    in(1,0);
    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        auA=a;
        auB=b;
        c=lca(a,b);
        ll ans=LLONG_MAX;
        dis=(dep[auA]-dep[c]+1)+(dep[auB]-dep[c]+1)-1;
        ll l=0, r=dis-3, piv;
        while(l<=r)
        {
            piv=(l+r)/2;
            ans=min(calc2(auA,auB,piv+1,c,dis-2,a,b),ans);
            if(a==b)
                break;
            if(a<b)
                l=piv+1;
            else
                r=piv-1;
        }

        if(ans==LLONG_MAX)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}
