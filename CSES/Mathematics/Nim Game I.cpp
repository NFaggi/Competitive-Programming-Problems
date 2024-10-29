#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, n, i, cant;
    long long x;
    cin >> a;
    while (a--)
    {
        cin >> n;
        cant=0;
        long long xo=0;
        
        for(i=0; i<n; i++)
        {
            cin >> x;
            xo^=x;
        }
        if(xo!=0)
            cout << "first\n";
        else
            cout << "second\n";
    }
    return 0;
}
