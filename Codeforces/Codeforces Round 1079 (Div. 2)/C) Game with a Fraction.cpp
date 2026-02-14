//Link: https://codeforces.com/contest/2197/problem/C
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
    ll x, y;
    cin >> x >> y;
    ll l=0, r=1e18, piv, pos=-1;
    if(x/2<y/3)
    {
        cout << "Alice\n";
        return;
    }
    while(l<=r)
    {
        piv=(l+r)/2;
        if(x-piv<0||y-piv<1)
            r=piv-1;
        else if((x-piv)/2>(y-piv)/3)
        {
            pos=piv;
            l=piv+1;
        }
        else if((x-piv)/2<(y-piv)/3)
            r=piv-1;
        else
            r=piv-1;
    }
    if(pos!=-1)
    {
        x-=pos;
        y-=pos;
    }
    for(ll i=0; i<10; i++)
    {
        if(x<=1||y<=2)
            break;
        if(x%2==0&&y%3==0&&x/2==y/3)
        {
            cout << "Bob\n";
            return;
        }
        x--;
        y--;
    }
    cout << "Alice\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
