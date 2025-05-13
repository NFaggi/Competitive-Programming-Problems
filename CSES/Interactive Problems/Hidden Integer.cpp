#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool query(ll x)
{
    string ans;
    cout << "? " << x << endl;
    cin >> ans;
    return (ans[0]=='Y') ? 1 : 0;
}

int main()
{
    ll x, mi=1, ma=1e9, piv;
    x=0;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(query(piv))
        {
            mi=piv+1;
            x=max(x,piv);
        }
        else
        {
            ma=piv-1;
        }
    }
    cout << "! " << x+1 << endl;
    return 0;
}
