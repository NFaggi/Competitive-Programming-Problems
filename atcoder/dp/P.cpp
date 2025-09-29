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

const int MAXN = 1e5+1;
const int MOD=1e9+7;

vector<ll>grafo[MAXN];

pair<ll,ll>dfs(ll nod, ll pad)
{
    pair<ll,ll>ret,ans={1,1};
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        ret=dfs(k,nod);
        ans.fr=(ans.fr*(ret.fr+ret.se)%MOD)%MOD; 
        ans.se=(ans.se*ret.fr)%MOD; 
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, x, y, res;
    cin >> n;
    for(i=0; i<n-1; i++)
    {
        cin >> x >> y;
        grafo[x].pb(y);
        grafo[y].pb(x);
    }
    pair<ll,ll>p=dfs(1,-1);
    res=(p.fr+p.se)%MOD;
    cout << res;
    return 0;
}
