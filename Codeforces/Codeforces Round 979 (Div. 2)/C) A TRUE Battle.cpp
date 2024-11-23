//Link: https://codeforces.com/contest/2030/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, i;
    cin >> t;
    while(t--)
    {
        int num=0, n, ant=1,res=0;
        string s;
        cin >> n;
        cin >> s;
        for(i=0; i<n; i++)
        {
            num=s[i]-'0';
            if(num==1&&ant==1)
            {
                s[n-1]='1';
                break;
            }
            ant=num;
        }
        if(s[n-1]=='1')
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
