//Link: https://codeforces.com/contest/1883/problem/A
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i,pos,x,res;
    string s;
    cin >> t;
    vector<int>v={10,1,2,3,4,5,6,7,8,9};
    while(t--)
    {
        cin >>s;
        pos=1;
        res=int(s.size());
        for(i=0; i<int(s.size()); i++)
        {
            x=s[i]-'0';
            res+=abs(v[x]-pos);
            pos=v[x];
        }
        cout << res <<'\n';
    }
    return 0;
}