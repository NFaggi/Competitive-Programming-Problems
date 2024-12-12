//Link: https://codeforces.com/problemset/problem/1311/D
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t, i;
    cin >> t;
    vector<vector<ll>>v(20001);
    for(i=1; i<=20000; i++)
    {
        for(ll j=1; j<=sqrt(i); j++)
        {
            if(i%j==0)
            {
                v[i].push_back(j);
                if(i/j!=j)
                {
                    v[i].push_back(i/j);
                }
            }
        }
    }
    while(t--)
    {

        ll a, b, c, dis,mi=LLONG_MAX,ra=1,rb=1,rc=1;
        cin >> a >> b >> c;
        for(i=1; i<=20000; i++)
        {
            for(auto j:v[i])
            {
                for(auto k:v[j])
                {
                    dis=abs(i-c)+abs(j-b)+abs(k-a);
                    if(mi>dis)
                    {
                        rc=i;
                        rb=j;
                        ra=k;
                        mi=dis;
                    }
                }
            }
        }
        cout << mi << '\n';
        cout << ra << ' ' << rb << ' ' << rc <<'\n';
    }
    return 0;
}
