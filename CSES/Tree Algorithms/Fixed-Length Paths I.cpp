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

const int MAXN=2e5+1;

vector<ll>arbol[MAXN];
ll n, K, hijos[MAXN], cant1[MAXN], cant2[MAXN], szC1, szC2;
bitset<MAXN>vis;
long long ans=0;

ll DFSCalc(ll nod, ll pad)
{
    hijos[nod]=1;
    for(auto k:arbol[nod])
    {
        if(k==pad||vis[k])
            continue;
        hijos[nod]+=DFSCalc(k,nod);
    }
    return hijos[nod];
}

ll DFS(ll nod, ll pad)
{
    for(auto k:arbol[nod])
    {
        if(k==pad||vis[k])
            continue;
        if(hijos[k]>n)
            return DFS(k,nod);
    }
    return nod;
}

void DFSDists(ll nod, ll pad, ll dist)
{
    if(dist>K)
        return;
    szC2=max(szC2,dist+1);
    cant2[dist]++;
    for(auto k:arbol[nod])
    {
        if(k==pad||vis[k])
            continue;
        DFSDists(k,nod,dist+1);
    }
}

void calc(ll nod)
{
    szC1=1;
    DFSCalc(nod,-1);
    n=hijos[nod]/2;
    ll cent=DFS(nod,-1), i;
    vis[cent]=1;
    cant1[0]=1;
    for(auto k:arbol[cent])
    {
        if(vis[k])
            continue;
        szC2=0;
        DFSDists(k,cent,1);
        for(i=0; i<szC2; i++)
        {
            ans+=(long long)cant1[K-i]*(long long)cant2[i];
        }
        for(i=0; i<szC2; i++)
        {
            cant1[i]+=cant2[i];
            cant2[i]=0;
        }
        szC1=max(szC1,szC2);
    }
    for(i=0; i<szC1; i++)
    {
        cant1[i]=0;
    }
    for(auto k:arbol[cent])
        if(!vis[k])
            calc(k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, a, b;
    cin >> n >> K;
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        arbol[a].pb(b);
        arbol[b].pb(a);
    }
    calc(1);

    cout << ans << '\n';
    return 0;
}
