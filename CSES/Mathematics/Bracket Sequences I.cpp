#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;
const int MX = 1e6+1;
long long dp[MX];
long long frec[26];
 
long long fact(long long n) {
    if(dp[n] != 0)
        return dp[n];
    dp[n] = (1ll * n * fact(n-1)) % MOD;
    return dp[n];
}
 
long long binpow(long long a, long long b) {
    long long ans = 1;
    while(b > 0) {
        if((b & 1) > 0) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
 
long long inv(long long a) {
    return binpow(a, MOD-2);
}
 
long long calc(long long a, long long b) {
    long long num = fact(a);
    long long den = (fact(b) * fact(a-b)) % MOD;
    return (num * inv(den)) % MOD;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0] = 1;
    dp[1] = 1;
 
    long long n;
    cin >> n;
 
    if(n % 2 != 0) {
        cout << 0;
        return 0;
    }
 
    n /= 2;
    long long res = (calc(n*2, n) - calc(n*2, n+1)) % MOD;
 
    if(res < 0) {
        res += MOD;
    }
 
    cout << res;
    return 0;
}
