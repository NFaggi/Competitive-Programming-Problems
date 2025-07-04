#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, i, a, b, cv = 0, cv2 = 0, j = 1;
    cin >> n >> a >> b;
    if (a + b > n)
    {
        cout << "NO\n";
        return;
    }
    vector<ll> v(n), v2(n);
    for (i = 0; i < a; i++)
        v[i] = i + 1 + b;
    for (i = 0; i < n; i++)
        v2[i] = i + 1;
    for (i = a; i < a + b; i++)
        v[i] = j++;
    for (i = a + b; i < n; i++)
        v[i] = i + 1;
    for(i=0; i<n; i++)
    {
        if(v[i]>v2[i])
            cv++;
        if(v2[i]>v[i])
            cv2++;
    }
    if(cv==a&&cv2==b)
    {
        cout << "YES\n";
        for(i=0; i<n; i++)
            cout << v[i] << ' ';
        cout << '\n';
        for(i=0; i<n; i++)
            cout << v2[i] << ' ';
        cout << '\n';
    }
    else
        cout << "NO\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
