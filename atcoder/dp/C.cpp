#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    long long a, b, c, aA=0, aB=0, aC=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a >> b >> c;
        a+=max(aB,aC);
        b+=max(aA,aC);
        c+=max(aA,aB);
        aA=a;
        aB=b;
        aC=c;
    }
    cout << max(a,max(b,c));
    return 0;
}
