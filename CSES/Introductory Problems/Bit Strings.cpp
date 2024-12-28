#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
ll binpow(ll a, ll b)
{
    if(b==1)
        return a;
    if(b==0)
        return 1;
    ll ans;
    ans=binpow(a,b/2)%MOD;
    ans=(ans*ans)%MOD;
    if(b%2!=0)
        ans=(ans*a)%MOD;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << binpow(2,n);
    return 0;
}
