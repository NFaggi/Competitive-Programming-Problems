//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/106
#include <bits/stdc++.h>

using namespace std;
int cal(string & s)
{
    int n=int(s.size()), i, l, r, pos;
    for(i=0; i<n-1; i++)
    {
        l=i;
        r=n-1;
        pos=1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                pos=0;
                break;
            }
            r--;
            l++;
        }
        if(pos)
            return i;
    }
    return n-1;
}
int  prueba( string palabra )
{
    string s=palabra;
    reverse(s.begin(),s.end());
    return min(cal(palabra),cal(s));
}
