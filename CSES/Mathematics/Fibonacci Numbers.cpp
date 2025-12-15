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

const ll MOD=1e9+7;

ll mul(ll a, ll b)
{
    return (a*b)%MOD;
}

ll sum(ll a, ll b)
{
    return (a+b)%MOD;
}

vector<vector<ll>> mulMat(vector<vector<ll>>&a, vector<vector<ll>>&b)
{
    vector<vector<ll>>ans(2,vector<ll>(2,0));
    ans[0][0]=sum(mul(a[0][0],b[0][0]),mul(a[0][1],b[1][0]));
    ans[0][1]=sum(mul(a[0][0],b[0][1]),mul(a[0][1],b[1][1]));
    ans[1][0]=sum(mul(a[1][0],b[0][0]),mul(a[1][1],b[1][0]));
    ans[1][1]=sum(mul(a[1][0],b[0][1]),mul(a[1][1],b[1][1]));
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i;
    cin >> n;
    if(n==0)
    {
        cout << 0;
        return 0;
    }
    if(n<=2)
    {
        cout << 1;
        return 0;
    }
    vector<vector<ll>>a(2,vector<ll>(2,1)),b, in, ans;
    a[1][1]=0;
    in=a;
    b=a;
    if(n&1)
        ans=in;
    for(i=1; i<=60; i++)
    {
        a=mulMat(a,b);
        if((1ll<<i)&n)
        {
            if(sz(ans))
                ans=mulMat(a,ans);
            else
                ans=a;
        }
        b=a;
    }
    cout << ans[1][0];
    return 0;
}
