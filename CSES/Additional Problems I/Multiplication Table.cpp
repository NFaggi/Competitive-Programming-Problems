#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll calc(ll x)
{
    ll cant=0, i;
    for(i=1; i<=n; i++)
    {
        cant+=min(x/i,n);
    }
    return cant;
}

int main()
{
    ll mi=1, ma, piv, pos=LLONG_MAX, ans, cant;
    cin >> n;
    ans=(n*n)/2+1;
    ma=n*n;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        cant=calc(piv);
        if(cant==ans)
        {
            pos=piv;
            break;
        }
        else if(cant>ans)
        {
            ma=piv-1;
            pos=min(piv,pos);
        }
        else
            mi=piv+1;
    }
    cout << pos;
    return 0;
}
