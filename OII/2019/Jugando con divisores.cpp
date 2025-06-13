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

const int MOD=1000003;

ll memo[MOD];

void prec()
{
    for(ll i=1; i<MOD; i++)
        for(ll j=i+i; j<MOD; j+=i)
            memo[j]+=(i*i);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, x, m, b, calc, res, i, j, tot=0;
    prec();
    cin >> n >> q;
    vector<ll>v(n);
    map<ll,ll>pos;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        pos[v[i]]=i;
    }

    vector<ll>dp(1<<n), f(1<<n,0);
    dp[0]=0;
    for(i=1; i<sz(dp); i++)
    {
        calc=1;
        for(j=0; j<n; j++)
            if((1<<j)&i)
                calc=(calc*v[j])%MOD;
        if(calc<=1)
            dp[i]=0;
        else
        {
            res=memo[calc];
            dp[i]=res;
        }
        tot+=dp[i];
    }
    f=dp;
    for (i = 0; i < n; ++i)
        for (int mask = 0; mask < (1 << n); ++mask)
            if ((mask & (1 << i)) == 0)
                f[mask] += f[mask | (1 << i)];
    while(q--)
    {
        cin >> m;
        if(m==0)
        {
            cout << tot << ' ';
            continue;
        }
        b=0;
        for(i=0; i<m; i++)
        {
            cin >> x;
            b=b|(1<<pos[x]);
        }
        cout << f[b] << ' ';
    }
    return 0;
}
