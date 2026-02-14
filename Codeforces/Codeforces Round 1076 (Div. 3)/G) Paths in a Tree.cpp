//Link: https://codeforces.com/contest/2193/problem/G
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
vector<ll>grafo[MAXN];
ll vis[MAXN],match[MAXN], cal[MAXN], prof[MAXN];
bool dfs(ll nod)
{
    vis[nod]=1;
    for(auto k:grafo[nod])
    {
        if(!vis[k])
        {
            if(!dfs(k))
            {
                match[nod]=k;
                match[k]=nod;
                return 1;
            }
        }
    }
    return 0;
}

void calc(ll nod, ll pad, ll pro)
{
    prof[nod]=pro;
    for(auto k:grafo[nod])
    {
        if(pad==k)
            continue;
        calc(k,nod,pro+1);
    }
}

bool query(ll a, ll b)
{
    cout << "? " << a << ' ' << b << '\n';
    cout.flush();
    ll ans;
    cin >> ans;
    if(ans==-1)
        exit(1);
    return ans;
}

void init(ll n)
{
    ll i;
    for(i=0; i<=n; i++)
    {
        grafo[i].resize(0);
        vis[i]=0;
        match[i]=-1;
        prof[i]=cal[i]=0;
    }
}

void ans(ll x)
{
    cout << "! " << x << '\n';
    cout.flush();
}

void solve()
{
    ll n, t, i, j, a, b;
    cin >> n;
    init(n);
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    calc(1,0,0);
    for(i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);
    for(i=1; i<=n; i++)
    {
        if(match[i]==-1||cal[i])
            continue;
        if(query(i,match[i]))
        {
            if(query(i,i))
            {
                ans(i);
                return;
            }
            else
            {
                ans(match[i]);
                return;
            }
        }
        cal[i]=1;
        cal[match[i]]=1;
    }
    vector<pair<ll,ll>>v;
    for(i=1; i<=n; i++)
    {
        if(match[i]==-1)
            v.pb({-prof[i],i});
    }
    sort(all(v));
    while(sz(v)>1)
    {
        a=v.back().se;
        b=v[sz(v)-2].se;
        if(query(a,b))
        {
            if(query(a,a))
            {
                ans(a);
                return;
            }
            else
            {
                ans(b);
                return;
            }
        }
        v.pop_back();
        v.pop_back();
    }
    ans(v.back().se);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
