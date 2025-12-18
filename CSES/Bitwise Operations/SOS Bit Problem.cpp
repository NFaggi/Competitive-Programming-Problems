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
ll bits=20;
ll negar(ll x)
{
    ll i, num=0;
    for(i=0; i<bits; i++)
        if(!((1<<i)&x))
            num=num|(1<<i);
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, i, j;
    cin >> n;
    vector<ll>v(n);
    vector<ll>dp((1<<bits),0), dp2((1<<bits),0), cant((1<<bits),0);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        cant[v[i]]++;
        dp[v[i]]++;
        dp2[v[i]]++;
    }

    for(i=0; i<bits; i++)
    {
        for(j=0; j<(1<<bits); j++)
        {
            if((1<<i)&j)
                dp[j]+=dp[j^(1<<i)];
            else
                dp2[j]+=dp2[j^(1<<i)];
        }
    }
    for(i=0; i<n; i++)
        cout << dp[v[i]] << ' ' << dp2[v[i]] << ' ' << n-dp[negar(v[i])] << '\n';
    return 0;
}
