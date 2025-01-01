#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD=1e9+7;

ll binpow(ll a, ll b)
{
    if(b==1ll)
        return a;
    if(b==0ll)
        return 1ll;
    ll res=binpow(a,b/2ll)%MOD;
    res=(res*res)%MOD;
    if(b%2ll!=0ll)
        res=(res*a)%MOD;
    return res;
}

ll inv(ll n)
{
    return binpow(n,MOD-2);
}
ll inv2;
ll gauss(ll n)
{
    return (((n*(n+1ll))%MOD)*inv2)%MOD;
}

int main()
{
    ll n, i=1, cant=0, q, pos=0, tot=0,calc;
    cin >> n;
    inv2=inv(2ll);
    while(i<=n)
    {
        q=n/i;
        cant=(n/q)-(i-1);
        calc=(gauss((pos+cant)%MOD)-gauss(pos%MOD));
        if(calc<0)
            calc=calc+MOD;
        tot=(tot+((calc%MOD)*q)%MOD)%MOD;
        i=(i+cant);
        pos=i-1;
    }
    cout << tot;
    return 0;
}
