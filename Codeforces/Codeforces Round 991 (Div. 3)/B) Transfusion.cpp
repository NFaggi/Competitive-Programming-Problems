//Link: https://codeforces.com/contest/2050/problem/B
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, i,tot=0,x,par=0,imp=0;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        tot+=v[i];
        if(i%2!=0)
            imp+=v[i];
        else
            par+=v[i];    
    }
    
    x=tot/n;
    
    if(n%2!=0)
    {
        par-=x;
    }
    //cout << x << ' ' << tot << ' ' << imp << ' ' << par << ' ';
    if(x*n!=tot)
    {
        cout << "NO\n";
        return;
    }
    if(par==imp)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}