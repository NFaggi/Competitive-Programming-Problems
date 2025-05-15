//Link: https://www.spoj.com/problems/HACKERS/
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

const int MAXN=3e3+10;
vector<pair<ll,ll>>grafo[MAXN];
vector<ll>ids[MAXN], comp[MAXN];

void unionfind(ll a, ll b, ll &ant)
{
    if(ids[ant][a]==ids[ant][b])
    {
        return;
    }
    ll act=ant+1;
    ids[act]=ids[ant];
    a=ids[act][a];
    b=ids[act][b];
    if(sz(comp[a])<sz(comp[b]))
        swap(a,b);
    for(auto k:comp[b])
    {
        ids[act][k]=a;
        comp[a].pb(k);
    }
    ant=act;
}

void solve(ll n, ll m, ll h)
{
    ll i, a, b, c, num=1, ant=0, j, mi=1, ma, piv, pos, unions=0;
    for(i=0; i<MAXN; i++)
    {
        ids[i].clear();
        grafo[i].clear();
        comp[i]={i};
        for(j=0; j<MAXN; j++)
        {
            ids[i].pb(j);
        }
    }
    vector<vector<ll>>ars;
    map<ll,ll>m3;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        grafo[a].pb({b,c});
        grafo[b].pb({a,c});
        ars.pb({c,a,b});
    }
    sort(all(ars));
    for(i=0; i<m; i++)
    {
        if(i>0&&ars[i-1][0]==ars[i][0])
            continue;
        num++;
    }
    for(i=0; i<m; i++)
    {
        unionfind(ars[i][1],ars[i][2],unions);
        if(ant!=unions)
        {
            m3[unions]=ars[i][0];
        }
        ant=unions;
    }
    for(i=0; i<h; i++)
    {
        cin >> a >> b;
        mi=0;
        ma=unions;
        pos=unions;
        while(mi<=ma)
        {
            piv=(mi+ma)/2;
            if(ids[piv][a]==ids[piv][b])
            {
                pos=min(pos,piv);
                ma=piv-1;
            }
            else
                mi=piv+1;
        }
        cout << m3[pos] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, h;
    cin >> n >> m >> h;
    while(n!=-1)
    {
        solve(n,m,h);
        cin >> n >> m >> h;
    }

    return 0;
}
