https://codeforces.com/contest/2036/problem/A
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t, n, op, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll>v(n);
        op=1;

        for(i=0; i<n; i++)
        {
            cin >> v[i];
        }
        for(i=0; i<n-1; i++)
        {
            if(abs(v[i]-v[i+1])!=5&&abs(v[i]-v[i+1])!=7)
            {
                op=0;
            }
        }
        if(op)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}