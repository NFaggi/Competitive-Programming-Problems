//Link: https://codeforces.com/gym/103806/problem/C
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
    ll n, i, j, f,fi, c;
    bool pos=1;
    cin >> n;
    vector<ll>p,im;
    cin >> f >> c;
    if(c%2==0)
        p.pb(c);
    else
        im.pb(c);
    fi=f;
    for(i=1; i<n; i++)
    {
        cin >> f >> c;
        if(c%2==0)
            p.pb(c);
        else
            im.pb(c);
        if(f!=fi)
            pos=0;
    }
    if(pos==0)
    {
        cout << "NO\n";
        return;
    }
    sort(all(p));
    sort(all(im));
    for(i=1; i<sz(p); i++)
    {
        if(p[i]!=p[i-1]+2)
        {
            cout << "NO\n";
            return;
        }
    }
    for(i=1; i<sz(im); i++)
    {
        if(im[i]!=im[i-1]+2)
        {
            cout << "NO\n";
            return;
        }
    }
    if(sz(p)==0||sz(im)==0)
    {
        cout << "SI\n";
        return;
    }
    if(p[0]==2&&im[0]==1)
        cout << "SI\n";
    else
        cout << "NO\n";
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
