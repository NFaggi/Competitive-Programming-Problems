#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, i, a, b;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        if((a+b)%3==0&&min(a,b)*2>=max(a,b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
