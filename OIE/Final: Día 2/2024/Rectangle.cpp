//Link:
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int mi=1, ma=100, piv, pos=1, pos2=1;
    string s;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        cout << "? " << piv << ' ' << piv<< endl;
        cin >> s;
        if(s=="-1")
        {
            return 0;
        }
        if(s=="1")
        {
            mi=piv+1;
            pos=max(pos,piv);
        }
        else
        {
            ma=piv-1;
        }
    }
    mi=pos+1;
    pos2=pos;
    ma=100;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        cout << "? " << piv << ' ' << pos<< endl;
        cin >> s;
        if(s=="-1")
        {
            return 0;
        }
        if(s=="1")
        {
            mi=piv+1;
            pos2=max(pos2,piv);
        }
        else
        {
            ma=piv-1;
        }
    }
    cout << "! " << pos << ' ' << pos2 << endl;
    return 0;
}