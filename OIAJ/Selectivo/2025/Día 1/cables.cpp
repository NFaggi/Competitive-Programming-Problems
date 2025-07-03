//Link: https://juez.oia.unsam.edu.ar/task/173
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
 
const int MAXN=5005;
const int MAXM=MAXN*MAXN;
 
vector<pair<ll,ll>>grafo[MAXN];
ll n, act, put[MAXN], pads[MAXM], use[MAXM];
 
void dfs(ll nod, ll pad, ll cost, vector<long long>&dp, vector<ll>&nods)
{
    vector<long long>nDP(n+5,LLONG_MAX);
    vector<ll>nNods(n+5,-1);
    ll i;
    if(nod!=0)
    {
        for(i=1; i<n+5; i++)
        {
            if(dp[i-1]!=LLONG_MAX)
            {
                nDP[i]=dp[i-1]+cost;
                use[act]=nod;
                pads[act]=nods[i-1];
                nNods[i]=act++;
            }
        }
    }
    else
        nDP[0]=0;
    for(auto k:grafo[nod])
    {
        if(k.fr==pad)
            continue;
        dfs(k.fr,nod,k.se,nDP,nNods);
    }
    for(i=0; i<n+5; i++)
    {
        if(dp[i]>nDP[i])
        {
            dp[i]=nDP[i];
            nods[i]=nNods[i];
        }
    }
}
 
int cables(vector<int> &P, vector<int> &L, long long M, vector<int> &elegidos)
{
    n=sz(P)+5;
    ll i;
    for(i=0; i<sz(P); i++)
    {
        grafo[P[i]].pb({i+1,L[i]});
        grafo[i+1].pb({P[i],L[i]});
    }
    vector<long long>dp(n+5,LLONG_MAX);
    vector<ll>nods(n+5,-1);
    dp[0]=0;
    dfs(0,-1,0,dp,nods);
    ll ans=0;
    for(i=0; i<n+5; i++)
        if(dp[i]<=M)
            ans=i;
    ll nod=nods[ans];
    while(nod!=-1)
    {
        if(put[use[nod]]==0)
        {
            put[use[nod]]=1;
            if(use[nod]>0)
                elegidos.pb(use[nod]-1);
        }
        nod=pads[nod];
    }
    return sz(P)-ans;
}
