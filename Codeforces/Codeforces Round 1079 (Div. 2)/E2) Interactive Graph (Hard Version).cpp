//Link: https://codeforces.com/contest/2197/problem/E2
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

const int MAXN=31;

vector<ll>grafo[MAXN];
bool vis[MAXN];
map<ll,bool>con;
ll cant[MAXN], mi=LLONG_MAX;
map<ll,vector<ll>>memo;
void init()
{
    mi=LLONG_MAX;
    memset(vis,0,sizeof(vis));
    memset(cant,0,sizeof(cant));
    con.clear();
    memo.clear();
    for(ll i=0; i<MAXN; i++)
    {
        grafo[i].resize(0);
    }
}

vector<ll> cons(ll k)
{
    if(k==1)
        return {1};
    if(k>=mi)
        return {};
    if(con[k])
        return memo[k];
    con[k]=1;
    cout << "? " << k << '\n';
    cout.flush();
    ll q;
    cin >> q;
    if(q==-1)
        exit(1);
    vector<ll>ans(q);
    for(ll i=0; i<q; i++)
        cin >> ans[i];
    if(q==0)
        mi=min(mi,k);
    memo[k]=ans;
    return ans;
}
bool ap(ll nod, vector<ll>ans)
{
    if(nod==0)
        return 1;
    if(sz(ans))
        ans.pop_back();
    if(!sz(ans))
        return 0;
    if(ans.back()==nod)
        return 1;
    return 0;
}
ll k;
ll calc(ll nod)
{
    if(vis[nod])
    {
        k+=cant[nod]-1;
        return cant[nod];
    }
    vis[nod]=1;
    cant[nod]=1;
    while(true)
    {
        k++;
        vector<ll>ans=cons(k);
        if(sz(ans)==0)
            return cant[nod];
        if(ap(nod,ans))
        {
            grafo[nod].pb(ans.back());
            cant[nod]+=calc(ans.back());
        }
        else
        {
            k--;
            break;
        }
    }
    return cant[nod];
}

void solve()
{
    k=0;
    init();
    ll n, i, q, m=0;
    cin >> n;
    calc(0);
    for(i=1; i<=n; i++)
        m+=sz(grafo[i]);
    cout << "! " << m << '\n';
    cout.flush();
    for(i=1; i<=n; i++)
    {
        for(auto o:grafo[i])
        {
            cout << i << ' ' << o << '\n';
            cout.flush();
        }
    }
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
