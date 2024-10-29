//Link: https://codeforces.com/contest/2005/problem/A
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, j,mi,a;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<char,int>>us(5);
        us[0]={'a',0};
        us[1]={'e',0};
        us[2]={'i',0};
        us[3]={'o',0};
        us[4]={'u',0};
        string s="";
        for(i=0; i<n; i++)
        {
            mi=INT_MAX;
            a=0;
            for(j=0; j<5; j++)
            {
                if(mi>us[j].second)
                {
                    a=j;
                    mi=us[j].second;
                }
            }
            s+=us[a].first;
            us[a].second++;
        }
        sort(s.begin(),s.end());
        cout << s << '\n';
    }
    return 0;
}