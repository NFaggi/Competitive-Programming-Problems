#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, sum=0,x,resto,cant=0;
    cin >> n;
    map<ll,ll>m;
    m[0]=1;
    for(i=0; i<n; i++)
    {
        cin >> x;
        sum=sum+x;
        resto=(sum%n);
        if(resto<0)
            resto+=n;
        cant+=m[resto];
        m[resto]++;
    }
    cout << cant;
    return 0;
}
