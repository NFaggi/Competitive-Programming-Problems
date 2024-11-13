//Link: https://codeforces.com/contest/1360/problem/B
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t, n,res,i;
    cin >> t;
    while(t--)
    {
        cin >>n;
        vector<long long>v(n);
        for(i=0; i<n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        res=LLONG_MAX;
        for(i=0; i<n-1; i++)
        {
            res=min(abs(v[i+1]-v[i]),res);
        }
        cout << res << '\n';
    }
    return 0;
}