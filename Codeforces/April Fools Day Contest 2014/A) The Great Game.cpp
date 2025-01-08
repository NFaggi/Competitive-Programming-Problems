//Link: https://codeforces.com/contest/409/problem/A
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string a,b;
    ll A=0,B=0, i;
    cin >> a >> b;

    for(i=0; i<b.size(); i+=2)
    {
        if(a[i]==b[i])
            continue;
        if(a[i]=='(')
        {
            if(b[i]=='[')
                B++;
            else
                A++;
        }
        else if(a[i]=='[')
        {
            if(b[i]=='(')
                A++;
            else
                B++;    
        }
        else
        {
            if(b[i]=='[')
                A++;
            else
                B++;
                    
        }    
    }
    if(A==B)
        cout << "TIE";
    else if(A>B)
        cout << "TEAM 1 WINS";
    else
        cout << "TEAM 2 WINS";
    return 0;
}