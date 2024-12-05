//Link: https://codeforces.com/contest/1553/problem/C
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n,cant,res,wins,mi,lose,i;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        cant=0;
        res=int(s.size());
        wins=0;
        lose=0;
        for(i=0; i<int(s.size()); i++)
        {
            res--;
            if(s[i]=='?')
            {
                wins++;
            }
            else if(s[i]=='1'&&i%2==0)
            {
                wins++;
            }
            else if(s[i]=='0'&&i%2!=0)
            {
                wins++;
            }
            else
            {
                lose++;
            }
            cant++;
            if(abs(wins-lose)>res)
            {
                break;
            }
        }
        mi=cant;
        cant=0;
        res=int(s.size());
        wins=0;
        lose=0;
        for(i=0; i<int(s.size()); i++)
        {
            res--;
            if(s[i]=='?')
            {
                wins++;
            }
            else if(s[i]=='1'&&i%2!=0)
            {
                wins++;
            }
            else if(s[i]=='0'&&i%2==0)
            {
                wins++;
            }
            else
            {
                lose++;
            }
            cant++;
            if(abs(wins-lose)>res)
            {
                break;
            }
        }
        mi=min(mi,cant);
        cout << mi << '\n';
    }
    return 0;
}