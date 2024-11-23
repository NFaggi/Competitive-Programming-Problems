//Link: https://codeforces.com/contest/2033/problem/A
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, op, aum, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        x=0;
        op=0;
        i=1;
        while(x>=-n&&x<=n)
        {
            if(op==0)
            {
                aum=i*2-1;
                x-=aum;
                op=1;
            }
            else
            {
                aum=i*2-1;
                x+=aum;
                op=0;
            }
            i++;
        }
        if(op)
        {
            cout << "Sakurako\n";
        }
        else
        {
            cout << "Kosuke\n";
        }
    }

    return 0;
}
