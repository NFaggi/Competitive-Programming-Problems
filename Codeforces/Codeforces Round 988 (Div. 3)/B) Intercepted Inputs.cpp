//Link: https://codeforces.com/contest/2037/problem/B
#include<bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
using namespace std;
void solve()
{
    ll n, i, x, a,b;
    cin >> n;
    multiset<ll>s;
    for(i=0; i<n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    n-=2;
    for(i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            auto it=s.find(i);
            if(it!=s.end())
            {
                b=n/i;
                auto it2=s.find(b);
                if(it2!=s.end())
                {
                    a=i;
                    break;
                }
            }
        }
    }
    cout << a << ' ' << b << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
