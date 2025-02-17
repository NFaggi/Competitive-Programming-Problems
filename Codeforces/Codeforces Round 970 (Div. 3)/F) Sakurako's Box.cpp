//Link: https://codeforces.com/problemset/problem/2008/F
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

ll MOD=1e9+7;
ll binpow(ll a, ll b)
{
    if(b==1)
        return a;
    if(b==0)
        return 1;
    ll ans=binpow(a,b/2)%MOD;
    ans=(ans*ans)%MOD;
    if(b%2!=0)
        ans=(ans*a)%MOD;
    return ans;
}

ll inv(ll x)
{
    return binpow(x%MOD,MOD-2);
}

void solve()
{
    ll n, i, j, num=0, ans, div=0;
    cin >> n;
    vector<ll>v(n), pref(n,0);
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=n-2; i>=0; i--)
    {
        pref[i]=(pref[i+1]+v[i+1])%MOD;
        num=(num+(pref[i]*v[i])%MOD)%MOD;
    }
    for(i=n-1; i>0; i--)
    {
        div+=i;
    }
    ans=(num*inv(div))%MOD;
    cout << ans << '\n';
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
