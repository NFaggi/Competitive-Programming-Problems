//Link: https://omegaup.com/arena/problem/OMI-2019-Progresion
//Score: 100/100
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
const int MAXN=1e5+1;
const int INF=1e9+7;
ll v[MAXN],n;

ll solve(ll k)
{
    ll x, y, sum, mi=INF, i, j;
    vector<vector<ll>>dp(n,vector<ll>(3,INF));
    dp[0][0]=1;
    dp[0][1]=0;
    dp[0][2]=1;
    for(i=0; i<n-1; i++)
        for(j=0; j<3; j++)
        {
            if(j==0)
                sum=1;
            else if(j==1)
                sum=0;
            else
                sum=-1;
            x=v[i]+1;
            if((x-(v[i+1]+sum))==k)
                dp[i+1][j]=min(dp[i][0]+abs(sum),dp[i+1][j]);
            x=v[i];
            if((x-(v[i+1]+sum))==k)
                dp[i+1][j]=min(dp[i][1]+abs(sum),dp[i+1][j]);
            x=v[i]-1;
            if((x-(v[i+1]+sum))==k)
                dp[i+1][j]=min(dp[i][2]+abs(sum),dp[i+1][j]);
        }
    for(i=0; i<3; i++)
        mi=min(mi,dp[n-1][i]);
    return mi;
}

int main()
{

    ll i, mi=INF, j;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> v[i];
    if(n==1)
    {
        cout << 0;
        return 0;
    }
    set<ll>s;
    for(i=-1; i<=1; i++)
        for(j=-1; j<=1; j++)
            s.insert((v[0]+i)-(v[1]+j));
    for(auto t:s)
        mi=min(mi,solve(t));
    if(mi==INF)
        cout << -1;
    else
        cout << mi;
    return 0;
}
