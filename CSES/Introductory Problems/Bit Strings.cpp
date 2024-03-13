#include <bits/stdc++.h>
const int MOD = 1e9+7;

using namespace std;

long long binpow(long long a, long long b)
{
    if (b == 1) return a;
    if (b == 0) return 1;
    long long tmp = binpow(a, b / 2);
    tmp = (tmp * tmp) % MOD;
    if (b % 2 == 1) tmp = (tmp * a) % MOD;
    return tmp;
}

int main()
{
    long long n;
    cin >> n;
    cout << binpow(2,n)%MOD;
    return 0;
}
