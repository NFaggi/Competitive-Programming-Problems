//Link: https://codeforces.com/problemset/problem/2025/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD=1e9+7;
const int MAXN=1e5+1;
const int MAXT=1e5+1;

ll ns[MAXT], ks[MAXT];

ll binpow(ll a, ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    ll res;
    if(b%2==0)
    {
        res=binpow(a,b/2);
        res=(res*res)%MOD;
    }
    else
    {
        res=binpow(a,b/2);
        res=(res*res)%MOD;
        res=(res*a)%MOD;
    }
    return res;
}

ll inv(ll x)
{
    return binpow(x,MOD-2);
}

int main()
{
    ll t, i, n, k, num ,div;
    cin >> t;

    for(i=0; i<t; i++)
        cin >> ns[i];
    for(i=0; i<t; i++)
        cin >> ks[i];

    for(i=0; i<t; i++)
    {
        if(ns[i]==ks[i]||ks[i]==0)
            cout << 1 << '\n';
        else
            cout << binpow(2,ks[i]) << '\n';
    }
    return 0;
}
