//Link: https://www.spoj.com/problems/DINOSM/
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define fore(i, a, b) for (i = (a); i <= (b); i++)
using namespace std;

const ll INF = 1e18;
const ll EPS=100000;
const int MAXN=601;

vector<pair<ll,ll>>v;

vector<ll> comp[MAXN];

ll id[MAXN], n, w, h, keke;

void init()
{
    ll i;
    fore(i,0,n+10)
    {
        id[i]=i;
        comp[i].resize(0);
        comp[i].pb(i);
    }
}

__int128 dist(ll a, ll b)
{
    __int128 x=v[a].fr-v[b].fr, y=v[a].se-v[b].se;
    x=x*x;
    y=y*y;
    return x+y; 
}

void unir(ll a, ll b)
{
    if(id[a]==id[b])
        return;
    ll x=id[a], y=id[b];
    if(sz(comp[x])<sz(comp[y]))
    {
        swap(x,y);
        swap(a,b);
    }

    for(auto &k:comp[y])
    {
        id[k]=x;
        comp[x].pb(k);
    }
}

bool can(ll inx)
{
    init();
    __int128 x=inx;
    x=x*x;
    ll i, j;
    __int128 d;
    fore(i,0,n-1)
    {
        fore(j,i+1,n-1)
        {
            d=dist(i,j);
            if(__int128(d)<__int128(x*__int128(4ll)))
            {
                unir(i,j);
            }
        }

        if(__int128(__int128(v[i].fr)*__int128(v[i].fr))+__int128(__int128(v[i].se)*__int128(v[i].se))<x)
            return 0;

        if(v[i].fr<inx)
            unir(i,n);
        if(v[i].se<inx)
            unir(i,n+1);
        if(w-v[i].fr<inx)
            unir(i,n+2);
        if(h-v[i].se<inx)
            unir(i,n+3);
    }

    if(id[n]==id[n+1]||id[n]==id[n+2]||id[n+1]==id[n+3]||id[n+2]==id[n+3])
        return 0;
    return 1;
}

void solve()
{    
    ll i;
    cin >> n >> w >> h;

    if(n==-1)
        exit(0);

    w=w*EPS;
    h=h*EPS;

    v.resize(0);
    v.resize(n);

    for(i=0; i<n; i++)
    {
        cin >> v[i].fr >> v[i].se;
        v[i].fr=v[i].fr*EPS;
        v[i].se=v[i].se*EPS;
    }

    ll maxD=1e7;
    ll l=0, r=maxD*EPS, piv, pos=0;

    while(l<=r)
    {
        piv=(l+r)/2;
        if(can(piv))
        {
            l=piv+1;
            pos=piv;
        }
        else
            r=piv-1;
    }

    pos=pos+50;
    pos=pos/100;

    double ans=double(double(pos)/double(1000));

    printf("%.3f\n",ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
        solve();
    return 0;
}
