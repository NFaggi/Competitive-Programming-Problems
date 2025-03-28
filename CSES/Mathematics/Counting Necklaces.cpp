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

const int MOD=1e9+7;

ll binpow(ll a, ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    ll ans=binpow(a,b/2);
    ans=(ans*ans)%MOD;
    if(b%2!=0)
        ans=(ans*a)%MOD;
    return ans;
}

ll inv(ll x)
{
    return binpow(x,MOD-2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m, n, res=0, i;
    cin >> n >> m;
    for(i=0; i<n; i++)
    {
        res=(binpow(m,__gcd(i,n)%MOD)+res)%MOD;
    }
    cout << (res*inv(n))%MOD;
    return 0;
}
