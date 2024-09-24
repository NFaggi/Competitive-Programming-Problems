//Link: https://codeforces.com/problemset/problem/2007/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i, t, l, r, cant;
    cin >> t;
    while(t--)
    {
        cant=0;
        cin >> l >> r;
        if(((r-l)+1)%2==0)
            cant=(((r-l)+1)/2)/2;
        else
            cant=((l%2!=0) ? ((r-l)+2)/2 : (r-l)/2)/2;
        cout << cant << '\n';
    }
    return 0;
}
