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
 
const int MAXM=1001;
const int MAXMASK=(1<<10);
ll dp[MAXM][MAXMASK];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, mask, i, j, lim;
    bool band;
    cin >> n >> m;
    mask=(1<<n);
    lim=mask-1;
    for(i=0; i<mask; i++)
    {
        band=1;
        for(j=0; j<n; j++)
        {
            if((1<<j)&i)
            {
                if((1<<(j+1))&i)
                    j++;
                else
                {
                    band=0;
                    break;
                }
            }
        }
        if(!band)
            continue;
        dp[0][i]=1;
    }
 
    for(i=1; i<m; i++)
    {
        for(j=0; j<mask; j++)
        {
            ll smask=(~j)&lim, act, x;
            dp[i][smask]=(dp[i][smask]+dp[i-1][j])%MOD;
            act=smask;
            while(act+1<mask)
            {
                act++;
                act|=smask;
                x=act&j;
                dp[i][act]=(dp[i][act]+dp[i-1][j]*dp[0][x])%MOD;
            }
        }
    }
    cout << dp[m-1][lim];
    return 0;
}
