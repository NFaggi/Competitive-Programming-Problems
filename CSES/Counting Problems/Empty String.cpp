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

const int MAXN=501;
const int MOD=1e9+7;

string s;
ll dp[MAXN][MAXN], vis[MAXN][MAXN], fact[MAXN], invFact[MAXN];

ll binpow(ll a, ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%MOD;
    ll ans=binpow(a,b/2);
    ans=(ans*ans)%MOD;
    if(b%2!=0)
        ans=(ans*(a%MOD))%MOD;
    return ans;
}

ll inv(ll a)
{
    return binpow(a,MOD-2);
}

ll calc(ll l, ll r)
{
    if(l>r)
        return 1;
    if(r-l+1==2)
        return s[l]==s[r];
    if(vis[l][r])
        return dp[l][r];
    vis[l][r]=1;

    if(s[l]==s[r])
        dp[l][r]=(dp[l][r]+calc(l+1,r-1))%MOD;

    ll x=(r-l+1)/2, a, b, su;
    for(ll i=l+1; i<r; i+=2)
    {
        if(s[l]==s[i])
        {
            a=(i-l+1)/2;
            b=(r-i)/2;
            su=(((fact[x]*invFact[a])%MOD)*invFact[b])%MOD;
            dp[l][r]=(dp[l][r]+(((calc(l+1,i-1)*calc(i+1,r))%MOD)*su)%MOD)%MOD;
        }
    }
    return dp[l][r];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    fact[0]=1;
    invFact[0]=inv(fact[0]);
    for(ll i=1; i<MAXN; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        invFact[i]=inv(fact[i]);
    }
    if(sz(s)%2!=0)
    {
        cout << 0 << '\n';
        return 0;
    }
    cout << calc(0,sz(s)-1) << '\n';
    return 0;
}
