//Link: https://codeforces.com/contest/2037/problem/C
#include<bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
using namespace std;
bool esPrimo(ll x, ll y)
{
    ll num=x+y, i;
    for(i=2; i<=sqrt(num); i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    ll n, i, p1=-1,p2=0,i1=-1,i2;
    cin >> n;
    if(n<=4)
    {
        cout << -1 << '\n';
        return;
    }
    for(i=2; i<=n; i+=2)
    {
        cout << i << ' ';
        p2=i;
    }
    vector<ll>vis(n+1,0);
    for(i=n; i>=1; i--)
    {
        if(i%2!=0&&esPrimo(i,p2)==0)
        {
            cout << i << ' ';
            vis[i]=1;
            break;
        }
    }
    for(i=n; i>=1; i--)
    {
        if(i%2!=0&&vis[i]==0)
        {
            cout << i << ' ';
        }
    }
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
