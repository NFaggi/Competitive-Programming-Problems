//Link: https://www.spoj.com/problems/APIO10A/
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

vector<pair<ll,ll>>ch;

bool bad(pair<ll,ll>a, pair<ll,ll>b, pair<ll,ll>c)
{

    return (__int128(__int128(a.se-c.se)*__int128(b.fr-a.fr))>=__int128(__int128(a.se-b.se)*__int128(c.fr-a.fr)));
}

void ins(ll m, ll b)
{
    while(sz(ch)>=2&&bad(ch[sz(ch)-2],ch.back(),{m,b}))
        ch.pop_back();
    ch.pb({m,b});
}
ll can(ll piv, ll x)
{
    if(piv>0&&x*(ch[piv-1].fr-ch[piv].fr)>(ch[piv].se-ch[piv-1].se))
        return -1;
    if(piv<sz(ch)-1&&(ch[piv+1].se-ch[piv].se)>x*(ch[piv].fr-ch[piv+1].fr))
        return 1;
    return 0;
}

ll query(ll x)
{
    ll l=0, r=sz(ch)-1, piv, pos=0, ret;
    while(l<=r)
    {
        piv=(l+r)/2;
        ret=can(piv,x);
        if(!ret)
            return ch[piv].fr*x+ch[piv].se;
        else if(ret==1)
            l=piv+1;
        else
            r=piv-1;
    }
    return ch[l].fr*x+ch[l].se;
}
void solve()
{
    ch.resize(0);
    ll n, a, b, c, i;

    cin >> n >> a >> b >> c;

    vector<ll>x(n+1), suf(n+1);

    for(i=0; i<n; i++)
        cin >> x[i];

    suf[n]=0;
    for(i=n-1; i>=0; i--)
        suf[i]=suf[i+1]+x[i];

    vector<ll>dp(n+1);

    dp[0]=0;
    ins(-2*suf[0]*a,dp[0]+a*suf[0]*suf[0]+b*suf[0]);
    for(i=1; i<=n; i++)
    {
        dp[i]=a*suf[i]*suf[i]-b*suf[i]+c+query(suf[i]);
        ins(-2*suf[i]*a,dp[i]+a*suf[i]*suf[i]+b*suf[i]);
    }
    cout << dp[n] << '\n';
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
