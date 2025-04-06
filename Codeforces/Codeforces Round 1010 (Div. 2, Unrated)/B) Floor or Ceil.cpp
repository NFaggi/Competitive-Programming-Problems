//Link: https://codeforces.com/contest/2082/problem/B
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        ll x, n, m, a, b, i;
        cin >> x >> n >> m;
        a=b=x;
        if(n<=30)
            a=floor((double)a/(1<<n));
        else
            a=0;
        if(m<=30)
        {
            a=ceil((double)a/(1<<m));
            b=ceil((double)b/(1<<m));
        }
        else
        {
            if(a>0)
                a=1;
            else
                a=0;
            if(b>0)
                b=1;
            else
                b=0;
        }
        if(n<=30)
            b=floor((double)b/(1<<n));
        else
            b=0;
        cout << b << ' ' << a << '\n';
    }
    return 0;
}
