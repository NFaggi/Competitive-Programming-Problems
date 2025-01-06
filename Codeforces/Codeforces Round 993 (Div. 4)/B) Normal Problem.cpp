//Link: https://codeforces.com/contest/2044/problem/B
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll i;
    string s, res="";
    cin >> s;
    for(i=int(s.size())-1; i>=0; i--)
    {
        if(s[i]=='p')
        {
            res+='q';
        }
        else if(s[i]=='q')
        {
            res+='p';
        }
        else
        {
            res+='w';
        }
    }
    cout << res << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}