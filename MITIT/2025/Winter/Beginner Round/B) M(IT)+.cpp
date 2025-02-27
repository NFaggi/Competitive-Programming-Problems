//Link: https://codeforces.com/gym/105668/problem/B
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

void solve()
{
    ll n, i;
    char a='I', b='T', act;
    cin >> n;
    string s;
    cin >> s;
    act='I';
    if(s[0]!='M')
    {
        cout << "NO\n";
        return;
    }
    for(i=1; i<n; i++)
    {
        if(s[i]==a)
        {
            if(act==b)
            {
                cout << "NO\n";
                return;
            }
            act=b;
        }
        else if(s[i]==b)
        {
            if(act==a)
            {
                cout << "NO\n";
                return;
            }
            act=a;
        }
        else if(s[i]=='M')
        {
            if(act==b||(i>0&&s[i-1]!='T'))
            {
                cout << "NO\n";
                return;
            }
            act=a;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    if(act==b||s[n-1]!='T')
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
