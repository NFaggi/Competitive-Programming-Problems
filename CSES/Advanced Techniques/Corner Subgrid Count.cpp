#include <bits/stdc++.h>
#define ll long long
#pragma GCC target("popcnt")
using namespace std;
bitset<3001>v[3001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, j;
    string s;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> s;
        for(j=0; j<n; j++)
            v[i][j]=(s[j]=='1');
    }
    ll cant = 0, act;
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            act=(v[i]&v[j]).count();
            act=(act*(act-1))/2;
            cant+=act;
        }
    }
    cout << cant;
    return 0;
}
