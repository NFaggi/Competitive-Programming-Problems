//Link: https://codeforces.com/problemset/problem/540/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, x, y, mi,sum=0, i;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(i=0; i<n; i++)
    {
        x=a[i]-'0';
        y=b[i]-'0';
        mi=abs(x-y);
        if(x>y)
        {
            mi=min(mi,(10-x)+y);
        }
        else if(x<y)
        {
            mi=min(mi,(10-y)+x);
        }
        sum+=mi;
    }
    cout << sum;
    return 0;
}
