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
const int MAXN = 5e5+1;

ll dp[MAXN], res[27];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, sum, x;
    string s;
    cin >> s;

    for(i=0; i<sz(s); i++)
    {
        x=s[i]-'a';
        sum=1;
        if(i>0)
        {
            sum=(sum+dp[i-1])%MOD;
            dp[i]=dp[i-1];
        }
        sum=sum-res[x];

        if(sum<0)
            sum=sum+MOD;

        res[x]=(res[x]+sum)%MOD;

        dp[i]=(dp[i]+sum)%MOD;
    }
    cout << dp[sz(s)-1];
    return 0;
}
