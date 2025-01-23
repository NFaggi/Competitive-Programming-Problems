//Link: https://codeforces.com/gym/105668/problem/A
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

void solve()
{
    ll pot=1,ma=5, n;
    cin >> n;
    if(n<=5)
    {
        cout << "MIT time" << '\n';
    }
    else
    {
        while(n>ma)
        {
            ma=ma*5ll;
            pot++;
            if(n<=ma)
            {
                cout << "MIT^" << pot << " time\n";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
