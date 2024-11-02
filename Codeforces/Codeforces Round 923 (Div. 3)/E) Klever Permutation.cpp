//Link: https://codeforces.com/contest/1927/problem/E
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> construir(ll n, ll k)
{
    ll i, mi=1, ma=n, op=0, j;
    vector<ll>v(n,0);
    for(i=0; i<n; i++)
    {
        if(v[i]==0)
        {
            for(j=i; j<n; j+=k)
            {
                if(op==0)
                {
                    v[j]=mi;
                    mi++;
                }
                else
                {
                    v[j]=ma;
                    ma--;
                }
            }
        }
        if(op==0)
            op=1;
        else
            op=0;
    }
    return v;
}
int main()
{
    ll n, k, i, t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<ll> v=construir(n,k);
        for(i=0; i<n; i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
