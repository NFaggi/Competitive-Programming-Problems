//Link: https://codeforces.com/problemset/problem/1702/E
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

ll match[MAXN], ap[MAXN];

set<ll>grafo[MAXN];
vector<ll> doms[MAXN];

bool ans;

void dfs(ll nod)
{
    queue<ll>q;
    q.push(nod);
    while(sz(q))
    {
        nod=q.front();
        q.pop();
        for(auto k:grafo[nod])
        {
            if(match[k]==match[nod])
            {
                ans=0;
                return;
            }
            if(match[k]>0)
                continue;
            if(match[nod]==1)
                match[k]=2;
            else
                match[k]=1;
            q.push(k);
        }
    }
}
void solve()
{
    ll n, a, b, i;
    cin >> n;
    ans=1;
    for(i=1; i<=n; i++)
    {
        doms[i].resize(0);
        grafo[i].clear();
        match[i]=ap[i]=0;
    }
    vector<pair<ll,ll>>x;
    for(i=1; i<=n; i++)
    {
        cin >> a >> b;
        x.pb({a,b});
        ap[a]++;
        ap[b]++;
        if(ap[a]>2||ap[b]>2)
            ans=0;
    }
    if(ans==0)
    {
        cout << "NO\n";
        return;
    }
    for(i=1; i<=n; i++)
    {
        a=x[i-1].fr;
        b=x[i-1].se;
        if(a==b)
            ans=0;
        for(auto &k:doms[a])
        {
            grafo[i].insert(k);
            grafo[k].insert(i);
        }
        for(auto &k:doms[b])
        {
            grafo[i].insert(k);
            grafo[k].insert(i);
        }
        doms[a].pb(i);
        doms[b].pb(i);
    }
    for(i=1; i<=n; i++)
    {
        if(!ans)
            break;
        if(match[i]==0)
        {
            match[i]=1;
            dfs(i);
        }
    }
    if(ans)
        cout << "YES\n";
    else
        cout << "NO\n";
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
