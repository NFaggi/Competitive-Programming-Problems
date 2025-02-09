//Link: https://codeforces.com/gym/103809/problem/B
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
    ll a, b,num, div, i;
    cin >> a >> b;

    if(a%2==0||b%2==0)
        cout << a+b << '\n';
    else
        cout << abs(a-b) << '\n';

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
