#include <bits/stdc++.h>
const int MOD = 1e9+7;
 
using namespace std;
 
long long binpow(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
 
int main()
{
    long long n, a, b, c;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c;
        long long bc = binpow(b, c, MOD-1);
        cout << binpow(a, bc, MOD) << "\n";
    }
    return 0;
}