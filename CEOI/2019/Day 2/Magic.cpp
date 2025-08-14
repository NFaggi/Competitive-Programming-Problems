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
 
vector<ll>grafo[MAXN];
ll d[MAXN], w[MAXN];
 
map<ll,ll>dp[MAXN];
 
void dfs(ll nod, ll pad)
{
    for(auto &k:grafo[nod])
    {
        if(k==pad)
            continue;
        dfs(k,nod);
        if(sz(dp[k])>sz(dp[nod]))
            swap(dp[k],dp[nod]);
        for(auto &l:dp[k])
            dp[nod][l.fr]+=l.se;
    }
    ll act;
    if(w[nod]>0)
    {
        dp[nod][d[nod]]+=w[nod];
        act=w[nod];
        auto it=dp[nod].lower_bound(d[nod]+1);
        while(it!=dp[nod].end()&&act>0)
        {
            it->second-=act;
            act=0;
            if(it->second<=0)
            {
                act=-(it->second);
                it=dp[nod].erase(it);
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, i, p;
    cin >> n >> m >> k;
 
    for(i=2; i<=n; i++)
    {
        cin >> p;
        grafo[p].pb(i);
        grafo[i].pb(p);
    }
 
    for(i=0; i<m; i++)
    {
        cin >> p;
        cin >> d[p] >> w[p];
    }
 
    dfs(1,0);
 
    ll tot=0;
    for(auto &k:dp[1])
        tot+=k.se;
    cout << tot;
    return 0;
}
