//Link: https://usaco.org/index.php?page=viewproblem2&cpid=1542
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

ll calc(ll p, ll at, ll t)
{
    if (p == at && p != 1)
    {
        if (at + p - 1 >= t)
        {
            return p;
        }
        else
        {
            at += p - 1;
            return calc(p, at, t);
        }
    }
    if (at + p >= t)
    {
        p = p - (t - at);
        return p;
    }
    at += p + 1;
    p = at / 2;
    return calc(p, at, t);
}

ll queryt1(ll c, ll t)
{
    if (c == 0 && t <= 1)
        return 0;
    else if (c == 0)
        return calc(1, 2, t);
    return calc(c, c, t);
}

ll calc2(ll t)
{
    if(t<=1||t==3)
        return 0;
    if(t==2)
        return 1;
    ll x, fin, a, b, ad=0, c;
    a=(t/2);
    x=(a*2)/3;
    fin=t-x;
    if(t%2)
    {
        if((fin-1)/2==x+1)
        {
            x++;
            fin--;
        }
    }
    else
    {
        if((fin-1)/2==x+1)
        {
            x++;
            fin--;
        }
    }
    
    if(x==fin/2)
        return calc2(fin-1);
    if(x>fin/2)
    {
        if((fin+1)/2==x-1)
        {
            x--;
            fin++;
            return calc2(fin-1);
        }
        return x;
    }
    return x+1;
}

void solve()
{
    ll tip, c, t, x, i;
    cin >> tip;
    if (tip == 1)
    {
        cin >> c >> t;
        cout << queryt1(c, t) << '\n';
    }
    else
    {
        cin >> x >> t;
        if (x > t / 2)
            cout << x << '\n';
        else
        {
            t=t+x;
            t=t+1;
            cout << calc2(t-1) << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
