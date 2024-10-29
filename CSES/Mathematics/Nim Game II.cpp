#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    long long t, n, i, xr, x, j, k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        xr=0;
        for(i=0; i<n; i++)
        {
            cin >> x;
            xr^=x%4;
        }
        if(xr)
            cout << "first\n";
        else
            cout << "second\n";
    }
    return 0;
}