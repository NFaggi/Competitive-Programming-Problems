//Score: 100/100
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll v[30][30];
unordered_map<ll,ll>m;
ll dp(ll x)
{
    if(x==0)
        return 0;
    auto it=m.find(x);
    if(it!=m.end())
        return it->second;
    ll lsb=x&-x, ma=0;
    ll act=x^lsb,in=x^lsb,cal;
    cal=__builtin_ctz(lsb);
    while(act)
    {
        lsb=act&-act;
        act^=lsb;
        ma=max(ma,dp(in^lsb)+v[cal][__builtin_ctz(lsb)]);
    }    
    m[x]=ma;
    return ma;
}
int main()
{
    ll n, i, j;
    cin >> n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << dp((1<<n)-1);
    return 0;
}
