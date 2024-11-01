//Link: https://codeforces.com/contest/1927/problem/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, i, j, num;
    cin >> t;
    while(t--)
    {
        string s="";
        vector<long long>v(26);
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> num;
            for(j=0; j<26; j++)
            {
                if(v[j]==num)
                {
                    v[j]++;
                    char c = j+97;
                    s+=c;
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
