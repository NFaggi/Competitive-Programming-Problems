//Link: https://codeforces.com/problemset/problem/2050/G
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
vector<vector<ll>>grafo;
ll ma;
ll dfs(ll nod, ll pad)
{
    ll cant=sz(grafo[nod]),ans=-1e9,ans2=-1e9,pa=0,act,antC;
    if(pad!=-1)
        cant--;
    antC=cant;
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        act=dfs(k,nod)-1;
        if(act>ans)
        {
            ans2=ans;
            ans=act;
        }
        else if(act>ans2)
            ans2=act;
    }
    cant+=max(ans,0ll);
    if(pad==-1)
    antC=max(antC-2,0ll);
    else
    {
        antC=max(antC-1,0ll);
    }
    ma=max(max(max(cant,ans+2),ma),(ans+1+ans2+1)+antC);
    return cant;
}
void solve()
{
    grafo.resize(0);
    ma=0;
    ll n,i,a,b;
    cin >> n;
    grafo.resize(n+1);
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    dfs(1,-1);
    cout << ma << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
