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

const int MAXN=2e5+1;

struct bus
{
    int b;
    ll t, I, f;
};

vector<bus>grafo[MAXN];
bool vis[MAXN];
ll dist[MAXN];
int n, m, a, b, i;
ll l, t, I, f;
ll solve(ll in)
{
    for(i=0; i<n; i++)
        dist[i]=LLONG_MAX;
    dist[0]=in;
    priority_queue<pair<ll,int>>pq;
    pq.push({-in,0});
    memset(vis,0,sizeof(vis));
    while(pq.size())
    {
        int nod=pq.top().second;
        ll hora=-pq.top().first;
        pq.pop();
        vis[nod]=1;
        if(nod==n-1)
            break;
        for(auto k:grafo[nod])
        {
            if(vis[k.b])
                continue;
            ll horaFin=hora+k.t;
            if(hora<=k.I)
                horaFin+=k.I-hora;
            else if((hora-k.I)%k.f!=0)
            {
                horaFin+=(k.f-(hora-k.I)%k.f);
            }
            if(horaFin<dist[k.b])
            {
                dist[k.b]=horaFin;
                pq.push({-horaFin,k.b});
            }
        }
    }
    return dist[n-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll mi=1, ma=-1, res=0, piv,subTLE=1,cal;
    cin >> n >> m >> l;
    ma=l;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> t >> I >> f;
        if(I!=0||f!=1)
            subTLE=0;
        bus x;
        x.b=b;
        x.t=t;
        x.I=I;
        x.f=f;
        grafo[a].pb(x);
    }
    cal=solve(0);
    if(cal>l)
    {
        cout << -1;
        return 0;
    }
    if(subTLE)
    {
        cout << l-cal;
        return 0;
    }
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(solve(piv)<=l)
        {
            mi=piv+1;
            res=max(res,piv);
        }
        else
            ma=piv-1;
    }
    cout << res;
    return 0;
}
