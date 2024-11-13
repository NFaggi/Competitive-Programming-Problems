//Link: https://codeforces.com/contest/1360/problem/A
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, res;
    cin >> t;
    while(t--)
    {
        cin >>a >> b;
        res=max(min(a,min(b,a+b))*2,max(a,b));
        res=res*res;
        cout << res <<'\n';
    }
    return 0;
}