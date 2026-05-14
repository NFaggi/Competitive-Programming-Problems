//Link: https://codeforces.com/contest/1083/problem/E
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

const int MAXN=1e6+1;

ll dp[MAXN];

vector<pair<ll,ll>>ch;

bool bad(pair<ll,ll>a,pair<ll,ll>b,pair<ll,ll>c)
{
    return __int128(__int128(a.se-c.se)*__int128(b.fr-a.fr))>=__int128(__int128(a.se-b.se)*__int128(c.fr-a.fr));
}

void ins(pair<ll,ll>x)
{
    while(sz(ch)>=2&&bad(ch[sz(ch)-2],ch.back(),x))
        ch.pop_back();
    ch.pb(x);
}

ll inRange(ll piv, ll x)
{
    if(piv>0&&x*(ch[piv-1].fr-ch[piv].fr)>(ch[piv].se-ch[piv-1].se))
        return -1;
    if(piv+1<sz(ch)&&x*(ch[piv].fr-ch[piv+1].fr)<(ch[piv+1].se-ch[piv].se))
        return 1;
    return 0;
}

ll query(ll x)
{
    ll l=0, r=sz(ch)-1, piv, ret;
    while(l<=r)
    {
        piv=(l+r)/2;
        ret=inRange(piv,x);
        if(ret==0)
            return ch[piv].fr*x+ch[piv].se;
        if(ret==-1)
            r=piv-1;
        else
            l=piv+1;
    }
    return ch[l].fr*x+ch[l].se;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, ans=0;
    cin >> n;
    vector<vector<ll>>v(n,vector<ll>(3));
    for(i=0; i<n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    sort(all(v));

    ins({0,0});
    for(i=0; i<n; i++)
    {
        dp[i]=-v[i][2]+v[i][1]*v[i][0]+query(v[i][1]);
        ans=max(dp[i],ans);
        ins({-v[i][0],dp[i]});
    }
    cout << ans;
    return 0;
}
