//Link: https://oj.uz/problem/view/eJOI19_rack
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=1e6+1;
ll levs[MAXN];
ll MOD=1e9+7;
ll n;
ll calc(ll act, ll lvl, ll pos)
{
    if(lvl==n)
        return pos%MOD;
    if(act%2!=0)
        return calc(act/2,lvl+1,(pos+levs[lvl])%MOD);
    return calc(act/2,lvl+1, pos);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k, tam, act, i;
    cin >> n >> k;
    levs[n-1]=1;
    for(i=n-2; i>=0; i--)
        levs[i]=(levs[i+1]*2)%MOD;
    act=k-1;
    cout << calc(act, 0, 1);
    return 0;
}
