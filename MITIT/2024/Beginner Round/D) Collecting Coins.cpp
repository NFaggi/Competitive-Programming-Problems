//Link: https://codeforces.com/gym/104936/problem/D
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

vector<pair<ll,pair<ll,ll>>>grafo[MAXN];

ll n, inf=1e14+1;

bool can(ll x)
{
    priority_queue<pair<ll,ll>>pq;
    pq.push({x,1});
    vector<ll>coins(n+1,-1);
    vector<bool>vis(n+1,0),vInf(n+1,0);
    coins[1]=x;
    ll restCoins;
    while(pq.size())
    {
        ll nod=pq.top().second;
        pq.pop();
        if(coins[nod]!=inf)
        {
            if(vis[nod])
                continue;
            vis[nod]=1;
        }
        else
        {
            if(vInf[nod])
                continue;
            vis[nod]=1;
            vInf[nod]=1;
        }
        for(auto k:grafo[nod])
        {
            if(coins[nod]!=inf)
            {
                if(vis[k.first])
                    continue;
                restCoins=coins[nod]-k.second.first;
                if(restCoins<0)
                    continue;
                restCoins+=k.second.second;
                if(k.second.second>k.second.first)
                    restCoins=inf;
            }
            else
            {
                if(vInf[k.first])
                    continue;
                restCoins=inf;
            }
            if(coins[k.first]<restCoins)
            {
                coins[k.first]=restCoins;
                pq.push({restCoins,k.first});
            }
        }
    }
    if(coins[n]==-1)
        return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m, i, a, b, c, d, mi=0, ma=1e14, piv, pos=LLONG_MAX;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> c >> d;
        grafo[a].push_back({b,{c,d}});
        grafo[b].push_back({a,{c,d}});
    }
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(piv))
        {
            ma=piv-1;
            pos=min(piv,pos);
        }
        else
            mi=piv+1;
    }
    cout << pos;
    return 0;
}
