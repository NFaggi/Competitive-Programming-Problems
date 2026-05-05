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

void solve()
{
    ll n, i, j, sum, a, b, k;
    bool band=0;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)  
        cin >> v[i];
    
    for(i=1; i<(1<<n); i++)
    {
        vector<ll>v2;
        sum=0;
        for(j=0; j<n; j++)
            if((1<<j)&i)
            {
                v2.pb(v[j]);
                sum+=abs(v[j]);
            }
        for(j=0; j<(1<<sz(v2)); j++)
        {
            a=sum;
            b=0;
            for(k=0; k<sz(v2); k++)
            {
                if((1<<k)&j)
                {
                    b+=abs(v2[k]);
                    a-=abs(v2[k]);
                }
            }
            if(a==b)
            {
                band=1;
                break;
            }
        }
        if(band)
            break;
    }
    if(band)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
