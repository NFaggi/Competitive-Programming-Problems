//Link: https://codeforces.com/contest/988/problem/D
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
    ll n, i, ma=1, a, b, c, j, INF=1e9;
    cin >> n;
    vector<ll>v(n);
    set<ll>s;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    a=v[0];
    sort(v.begin(),v.end());
    for(i=0; i<n; i++)
    {
        for(j=1; j<=LLONG_MAX/2; j*=2ll)
        {
            auto it=s.find(v[i]+j);
            if(it!=s.end()&&ma<2)
            {
                ma=2;
                a=v[i];
                b=v[i]+j;
            }
            auto it2=s.find(v[i]+j+j);
            if(it!=s.end()&&it2!=s.end())
            {
                ma=3;
                a=v[i];
                b=v[i]+j;
                c=v[i]+j+j;
                break;
            }
        }
        if(ma==3)
            break;
    }
    cout << ma << '\n';
    cout << a << ' ';
    if(ma>=2)
        cout << b << ' ';
    if(ma==3)
        cout << c;
    return 0;
}
