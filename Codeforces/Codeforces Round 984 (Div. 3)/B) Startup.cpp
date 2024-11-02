//Link: https://codeforces.com/contest/2036/problem/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t, n, k, i, c, b, res;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<ll>v(k+1,0);
        res=0;
        for(i=0; i<k; i++)
        {
            cin >> b >> c;
            v[b]+=-c;
        }
        sort(v.begin(),v.end());
        for(i=0; i<n&&i<k+1; i++)
        {
            res+=-v[i];
        }
        cout << res << '\n';

    }
    return 0;
}
