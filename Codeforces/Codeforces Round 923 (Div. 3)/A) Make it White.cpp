//Link: https://codeforces.com/contest/1927/problem/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, i, n, j;
    string s;
    cin >> t;
    while(t--)
    {
        bool band=true;
        long long pi=-1, pf=-1;
        cin >> n >> s;
        for(j=0; j<s.size(); j++)
        {
            if(s[j]=='B')
            {
                if(band)
                {
                    pi=j;
                    pf=j;
                    band=false;
                }
                else
                {
                    pf=j;
                }
            }
        }
        if(pf==-1&&pi==-1)
            cout << 0 << endl;
        else
            cout << pf-pi+1 << endl;
    }
    return 0;
}
