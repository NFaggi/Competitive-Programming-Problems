#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, j, sum, k, act;
    cin >> n;
    vector<ll> v(n), pref(n);
    vector<vector<ll>>dp(n,vector<ll>(n,LLONG_MAX)),bI(n,vector<ll>(n));

    for(i=0; i<n; i++)
    {
        cin >> v[i];
        pref[i]=v[i];
        if(i>0)
            pref[i]+=pref[i-1];
        dp[i][i]=0;
        bI[i][i]=i;
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n-i; j++)
        {
            sum=pref[j+i];
            if(j>0)
                sum-=pref[j-1];
            for(k=bI[j][j+i-1]; k<=bI[j+1][j+i]&&k<j+i; k++)
            {
                act=sum+dp[j][k]+dp[k+1][j+i];
                if(act<=dp[j][j+i])
                {
                    dp[j][j+i]=act;
                    bI[j][j+i]=k;
                }
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}
