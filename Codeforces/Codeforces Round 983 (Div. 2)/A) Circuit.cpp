//Link: https://codeforces.com/contest/2032/problem/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, x, i, mi, ma;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>p(2,0);
        for(i=0; i<n*2; i++)
        {
            cin >> x;
            p[x]++;
        }
        mi=p[1]%2;
        if(p[1]<=n)
        {
            ma=p[1];
        }
        else
        {
            ma=n;
            p[1]-=n;
            ma-=p[1];
        }
        cout << mi << ' ' << ma << '\n';
    }
    return 0;
}
