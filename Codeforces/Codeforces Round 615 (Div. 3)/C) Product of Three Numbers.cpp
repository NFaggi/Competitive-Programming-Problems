//Link: https://codeforces.com/problemset/problem/1294/C
#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll,ll> calc(ll x, ll us)
{
    ll i, s;
    s=sqrt(x);
    for(i=2; i<=s; i++)
    {
        if(x%i==0&&i!=us&&x/i!=us&&i!=x/i)
        {
            return {i,x/i};
        }
    }
    return {-1,-1};
}
int main()
{
    ll t, n, i,s,pos;
    pair<ll,ll>p;
    cin >> t;
    while(t--)
    {
        cin >> n;
        s=sqrt(n);
        pos=0;
        for(i=2; i<=s; i++)
        {
            if(n%i==0)
            {
                p=calc(n/i,i);
                if(p.first!=-1)
                {
                    cout << "YES\n" << i << ' ' << p.first << ' ' << p.second << '\n';
                    pos=1;
                    break;
                }
                p=calc(i,n/i);
                if(p.first!=-1)
                {
                    cout << "YES\n" << n/i << ' ' << p.first << ' ' << p.second << '\n';
                    pos=1;
                    break;
                }
            }
        }
        if(!pos)
            cout << "NO\n";
    }
    return 0;
}
