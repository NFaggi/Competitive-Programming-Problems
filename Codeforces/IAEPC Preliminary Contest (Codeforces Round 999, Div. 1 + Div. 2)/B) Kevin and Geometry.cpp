//Link: https://codeforces.com/problemset/problem/2061/B
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
    ll n, i, x, cant=2, a, b, mi=LLONG_MAX;
    map<ll,ll>m;
    vector<ll>v, ult;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x;
        v.push_back(x);
        m[x]++;
    }
    vector<ll>iguales;
    for(auto k:m)
    {
        if(k.second>1)
            iguales.pb(k.first);
    }
    if(iguales.size()==0)
    {
        cout << -1 << '\n';
    }
    else if(iguales.size()==1)
    {
        if(m[iguales[0]]>=4)
        {
            cout << iguales[0] << ' ' << iguales[0] << ' ' << iguales[0] << ' ' << iguales[0] << '\n';
        }
        else
        {
            for(i=0; i<n; i++)
            {
                if(v[i]!=iguales[0]||cant==0)
                {
                    ult.pb(v[i]);
                }
                else
                    cant--;
            }
            sort(all(ult));
            for(i=0; i<sz(ult)-1; i++)
            {
                if(mi>abs(ult[i]-ult[i+1]))
                {
                    mi=abs(ult[i]-ult[i+1]);
                    a=ult[i];
                    b=ult[i+1];
                }
            }
            if(mi<iguales[0]*2ll)
                cout << iguales[0] << ' ' << iguales[0] << ' ' << a << ' ' << b << '\n';
            else
                cout << -1 << '\n';
        }
    }
    else
    {
        cout << iguales[0] << ' ' << iguales[0] << ' ' << iguales[1] << ' ' << iguales[1] << '\n';
    }

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
