//Link: https://codeforces.com/problemset/problem/2020/A
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll n, k, i,ma=LLONG_MAX,num,cant=0;
    cin >> n >> k;
    if(k==1)
    {
        cout << n << '\n';
        return;
    }
    ma=ma/k;
    vector<ll>v;
    num=1;
    while(num<=ma)
    {
        v.push_back(num);
        num*=k;
    }
    v.push_back(num);
    for(i=int(v.size())-1; i>=0; i--)
    {
        cant+=n/v[i];
        n=n%v[i];
    }
    cout << cant << '\n';
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
