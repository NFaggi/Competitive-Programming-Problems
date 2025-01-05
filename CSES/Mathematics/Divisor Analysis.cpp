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
    return (((n*(n+1))%MOD)*inv2)%MOD;
}
ll prop(ll r, ll n)
{
    return (((binpow(r,n)-1ll)%MOD)*inv((r-1ll)%MOD))%MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, k, a=1, b=1, c=1,bcal,ccal=1, i, j,pot,gau,sumK=1,ks;
    inv2=inv(2);
    cin >> n;
    vector<pair<ll,ll>>v(n);
    for(i=0; i<n; i++)
    {
        cin >> x >> k;
        v[i].fr=x;
        v[i].se=k;
        sumK=(sumK+k)%MOD;
        a=(a*(k+1ll)%MOD)%MOD;
    }
    for(i=0; i<n; i++)
    {
        bcal=0;
        pot=1;
        x=v[i].fr%MOD;
        k=v[i].se%MOD;
        
        ks=sumK-k;
        bcal=prop(x,(k+1ll)%MOD);
        
        b=(b*bcal)%MOD;
    }
    bool hayimp=0;
    ll imp, exp=1,tot=1;
    for(i=0; i<n; i++)
    {
        if(v[i].se%2ll!=0ll)
        {
            hayimp=1;
            imp=i;
        }
    }
    if(hayimp)
    {
        for(i=0; i<n; i++)
        {
            if(i==imp)
            {
                exp=(exp*((v[i].se+1ll)/2ll))%(MOD-1ll);
            }
            else
            {
                exp=(exp*(v[i].se+1ll))%(MOD-1ll);
            }
        }
        for(i=0; i<n; i++)
        {
            tot=(tot*binpow(v[i].fr,(v[i].se*exp)%(MOD-1)))%MOD;
        }
    }
    else
    {
        for(i=0; i<n; i++)
        {
            exp=(exp*(v[i].se+1ll))%(MOD-1);
        }
        for(i=0; i<n; i++)
        {
            tot=(tot*binpow(v[i].fr,((v[i].se/2ll)*exp)%(MOD-1)))%MOD;
        }
    }
    c=tot;
    cout << a << ' ' << b << ' ' << c;
    return 0;
}
