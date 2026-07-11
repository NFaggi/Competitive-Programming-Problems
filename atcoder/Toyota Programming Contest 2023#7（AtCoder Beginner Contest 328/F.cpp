//Link: https://atcoder.jp/contests/abc328/tasks/abc328_f
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define fore(i, a, b) for (i = (a); i < (b); i++)
using namespace std;

const int MAXN = 2e5 + 1;
const int LOG = 19;

ll id[MAXN], up[MAXN][LOG], sum[MAXN][LOG], prof[MAXN];
vector<pair<ll, ll>> grafo[MAXN];
vector<ll> comp[MAXN];
ll k, i, x;
void calc(ll nod, ll pad, ll d)
{
    up[nod][0]=pad;
    sum[nod][0]=d;
    fore(i,1,LOG)
    {
        up[nod][i]=up[up[nod][i-1]][i-1];
        sum[nod][i]=sum[nod][i-1]+sum[up[nod][i-1]][i-1]; 
    }
}

void dfs(ll nod, ll pad)
{
    prof[nod]=prof[pad]+1;
    for (auto &k : grafo[nod])
    {
        if (k.fr == pad)
            continue;
        calc(k.fr, nod, k.se);
        dfs(k.fr, nod);
    }
}

void unir(ll a, ll b, ll d)
{
    ll x = id[a], y = id[b];
    if (sz(comp[x]) > sz(comp[y]))
    {
        swap(a, b);
        d = -d;
        swap(x,y);
    }

    calc(a, b, d);
    dfs(a, b);

    for (auto &k : comp[x])
    {
        comp[y].pb(k);
        id[k] = y;
    }
    comp[x].resize(0);
}

ll k_ans(ll a, ll k)
{
    fore(i,0,LOG)
        if((1ll<<i)&k)
            a=up[a][i];
    return a;
}

ll lca(ll a, ll b)
{
    if(prof[a]<prof[b])
        swap(a,b);
    a=k_ans(a,prof[a]-prof[b]);
    if(a==b)
        return a;
    for(i=LOG-1; i>=0; i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}


ll su(ll a, ll b)
{
    k=prof[a]-prof[b];
    x=0;
    fore(i,0,LOG)
    {
        if((1ll<<i)&k)
        {
            x+=sum[a][i];
            a=up[a][i];
        }
    }
    return x;
}


ll c;

bool check(ll a, ll b, ll d)
{
    c=lca(a,b);
    return (d==(su(a,c)-su(b,c)));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, j, a, b, d;
    cin >> n >> q;

    fore(i, 1, n + 1)
    {
        id[i] = i;
        comp[i] = {i};
    }

    vector<ll> ans;
    fore(j, 1, q + 1)
    {
        cin >> a >> b >> d;
        if (id[a] != id[b])
        {
            grafo[a].pb({b, -d});
            grafo[b].pb({a, d});
            unir(a, b, d);
            ans.pb(j);
        }
        else if (check(a, b, d))
            ans.pb(j);
    }

    for (auto &k : ans)
        cout << k << ' ';
    return 0;
}
