//Link: https://codeforces.com/problemset/problem/1999/F
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
const int MOD=1e9+7;

ll fact[MAXN];

ll binpow(ll a, ll b)
{
    if(b==1)
        return a;
    if(b==0)
        return 1;
    ll ans=binpow(a,b/2);
    ans=(ans*ans)%MOD;
    if(b%2==0)
        return ans;
    ans=(ans*a)%MOD;
    return ans;
}

ll inv(ll x)
{
    return binpow(x,MOD-2);
}

void solve()
{
    ll i, n, k, un=0, ce=0, x, cant=0, formasUn, formasCe;
    cin >> n >> k;
    for(i=0; i<n; i++)
    {
        cin >> x;
        if(x)
            un++;
        else
            ce++;
    }
    for(i=(k/2+1); i<=un&&i<=k; i++)
    {
        if(ce<(k-i))
            continue;
        formasUn=(fact[un]*inv((fact[i]*fact[un-i])%MOD))%MOD;
        formasCe=(fact[ce]*inv((fact[k-i]*fact[ce-(k-i)])%MOD))%MOD;
        cant=(cant+(formasUn*formasCe)%MOD)%MOD;
    }
    cout << cant << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t, i;
    cin >> t;
    fact[0]=1;
    fact[1]=1;
    for(i=2; i<MAXN; i++)
        fact[i]=(fact[i-1]*i)%MOD;
    while(t--)
        solve();
    return 0;
}
