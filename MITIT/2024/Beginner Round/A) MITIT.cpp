//Link: https://codeforces.com/gym/104936/problem/A
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, i, tam, j;
    bool iguales;
    string s;
    cin >> s;
    n=int(s.size());
    tam=n-1;
    if(tam%2!=0)
        tam--;
    tam=tam/2;
    if(tam==0)
    {
        cout << "NO\n";
        return;
    }
    for(i=1; i<=tam; i++)
    {
        iguales=1;
        for(j=n-1; j>=n-i; j--)
        {
            if(s[j]!=s[j-i])
            {
                iguales=0;
                break;
            }
        }
        if(iguales)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
