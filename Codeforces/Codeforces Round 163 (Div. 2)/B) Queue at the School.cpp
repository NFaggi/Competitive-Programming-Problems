//Link: https://codeforces.com/problemset/problem/266/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t, n, i;
    string s;
    cin >> n >> t;
    cin >> s;
    while(t--)
    {
        for(i=0; i<n-1; i++)
        {
            if(s[i]=='B'&&s[i+1]=='G')
            {
                swap(s[i],s[i+1]);
                i++;
            }
        }
    }
    cout << s;
    return 0;
}
