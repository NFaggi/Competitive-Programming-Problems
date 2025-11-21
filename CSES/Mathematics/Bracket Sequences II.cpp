#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
 
using namespace std;
const int MOD = 1e9 + 7;
const int MX = 1e6 + 1;
ll dp[MX];
 
ll fact(ll n)
{
    if (dp[n] != 0)
        return dp[n];
    dp[n] = (1ll * n * fact(n - 1)) % MOD;
    return dp[n];
}
 
ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if ((b & 1) > 0)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
 
ll inv(ll a)
{
    return binpow(a, MOD - 2);
}
 
ll calc(ll a, ll b)
{
    ll num = fact(a);
    ll den = (fact(b) * fact(a - b)) % MOD;
    return (num * inv(den)) % MOD;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0] = 1;
    dp[1] = 1;
    ll n, ap = 0, i, ans;
    cin >> n;
    string s;
    cin >> s;
    if(n%2!=0)
    {
        cout << 0;
        return 0;
    }
    for (i = 0; i < sz(s); i++)
    {
        if (s[i] == '(')
            ap++;
        else
            ap--;
        if (ap < 0 || (n - i - 1) - ap < 0)
        {
            cout << 0;
            return 0;
        }
    }
 
    ll h = ap;
    ll R = n - sz(s);
 
    ll b = (R + h) / 2;     
 
    ll comb = calc(R, b);
    ans = comb * ((h + 1) % MOD) % MOD;
    ans = ans * inv(b + 1) % MOD;
 
    cout << ans;
    return 0;
}
