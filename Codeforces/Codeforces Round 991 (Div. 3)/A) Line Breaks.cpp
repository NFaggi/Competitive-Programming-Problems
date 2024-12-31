//Link: https://codeforces.com/problemset/problem/2050/A
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n, m, i, x, res=0,cant=0;
    cin >> n >> m;
    string s;
    vector<ll>v;
    for(i=0; i<n; i++)
    {
        cin >> s;
        x=int(s.size());
        v.push_back(x);
    }
    for(i=0; i<n; i++)
    {
        cant+=v[i];
        if(cant>m)
            break;
        res++;
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
