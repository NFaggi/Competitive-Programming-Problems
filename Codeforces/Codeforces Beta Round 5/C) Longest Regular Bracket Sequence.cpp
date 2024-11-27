//Link: https://codeforces.com/contest/5/problem/C
#include <bits/stdc++.h>
#define sz(x) int(x.size())
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int a=0,b=1,x,i,sum=0,calc,in=0;
    vector<int>v;
    string s;
    cin >> s;
    for(i=1; i<=int(s.size()); i++)
    {
        if(s[i-1]=='(')
        {
            v.push_back(i);
        }
        else
        {
            if(sz(v)==0)
            {
                in=i;
                continue;
            }
            v.pop_back();
            if(sz(v)!=0)
                x=v[sz(v)-1];
            else
                x=0;
            x=max(x,in);
            calc=(i-x);
            if(a<calc)
            {
                a=calc;
                b=1;
            }
            else if(a==calc)
            {
                b++;
            }
        }
    }
    if(a==0)
        b=1;
    cout << a << ' ' << b;
    return 0;
}
