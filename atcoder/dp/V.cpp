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

vector<ll>arb[MAXN], rets[MAXN];
ll ans[MAXN];
ll m;
ll dfs(ll nod, ll pad)
{
    ll cant=1;
    rets[nod].resize(sz(arb[nod]));
    for(ll i=0; i<sz(arb[nod]); i++)
    {
        rets[nod][i]=1;
        if(pad==arb[nod][i])
            continue;
        rets[nod][i]=dfs(arb[nod][i],nod);
        cant=(cant*rets[nod][i])%m;
    }
    return (cant+1)%m;
}

void dfs2(ll nod, ll pad, ll mult)
{
    ll rpad=0, i, res=1;
    for(i=0; i<sz(arb[nod]); i++)
    {
        if(arb[nod][i]==pad)
        {
            rpad=i;
            break;
        }
    }
    rets[nod][rpad]=mult;
    vector<ll>pref(sz(arb[nod])),pref2(sz(arb[nod]));
    pref[0]=rets[nod][0];
    pref2[sz(arb[nod])-1]=rets[nod][sz(arb[nod])-1];
    for(i=1; i<sz(arb[nod]); i++)
    {
        pref[i]=(pref[i-1]*rets[nod][i])%m;
    }
    for(i=sz(arb[nod])-2; i>=0; i--)
    {
        pref2[i]=(pref2[i+1]*rets[nod][i])%m;
    }
    for(auto k:rets[nod])
    {
        res=(res*k)%m;
    }
    ans[nod]=res;
    for(i=0; i<sz(arb[nod]); i++)
    {
        if(arb[nod][i]==pad)
            continue;
        ll ant=1;
        if(i>0)
        {
            ant=(ant*pref[i-1])%m;
        }
        if(i+1<sz(arb[nod]))
        {
            ant=(ant*pref2[i+1])%m;
        }
        dfs2(arb[nod][i],nod,(ant+1)%m);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, a, b, an;
    cin >> n >> m;
    if(n==1)
    {
        cout << 1%m;
        return 0;
    }
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        arb[a].pb(b);
        arb[b].pb(a);
    }

    ans[1]=dfs(1,0)-1;
    if(ans[1]<0)
        ans[1]+=m;

    vector<ll>pref(sz(arb[1])),pref2(sz(arb[1]));
    pref[0]=rets[1][0];
    pref2[sz(arb[1])-1]=rets[1][sz(arb[1])-1];
    for(i=1; i<sz(arb[1]); i++)
    {
        pref[i]=(pref[i-1]*rets[1][i])%m;
    }
    for(i=sz(arb[1])-2; i>=0; i--)
    {
        pref2[i]=(pref2[i+1]*rets[1][i])%m;
    }
    for(i=0; i<sz(arb[1]); i++)
    {
        ll ant=1;
        if(i>0)
        {
            ant=(ant*pref[i-1])%m;
        }
        if(i+1<sz(arb[1]))
        {
            ant=(ant*pref2[i+1])%m;
        }
        dfs2(arb[1][i],1,(ant+1)%m);
    }
    for(i=1; i<=n; i++)
        cout << ans[i] << '\n';
    return 0;
}
