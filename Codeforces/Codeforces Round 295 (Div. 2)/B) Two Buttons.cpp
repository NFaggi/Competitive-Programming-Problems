//Link: https://codeforces.com/contest/520/problem/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, cant=0;
    cin >> a >> b;
    while(b!=a)
    {
        if(b>a&&b%2==0)
        {
            b/=2;
        }
        else
        {
            b++;
        }
        cant++;
    }
    cout << cant;
    return 0;
}
