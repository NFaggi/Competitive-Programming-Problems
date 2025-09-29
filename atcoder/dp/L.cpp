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

const int MAXN=3001;
ll n, v[MAXN], memo[2][MAXN][MAXN], INF=LLONG_MAX;

ll calc(ll k, ll i, ll j)
{
    if(memo[k][i][j]!=INF)
        return memo[k][i][j];
    if(k==0)
    {
        if(i==j)
            return memo[k][i][j]=v[i];
        return memo[k][i][j]=max(calc(1,i,j-1)+v[j],calc(1,i+1,j)+v[i]);
    }
    if(i==j)
        return -v[i];
    return memo[k][i][j]=min(calc(0,i+1,j)-v[i],calc(0,i,j-1)-v[j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, j, k;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> v[i];
    for(k=0; k<2; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                memo[k][i][j]=INF;
    cout << calc(0,0,n-1);
    return 0;
}
