#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    long long n, a, b, mi=LLONG_MAX,i,j;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    for(i=0; i<(1<<n); i++)
    {
        a=0;
        b=0;
        for(j=0; j<n; j++)
        {
            if((1<<j)&i)
            {
                a+=v[j];
            }
            else
            {
                b+=v[j];
            }
        }
        mi=min(mi,abs(a-b));
    }
    cout << mi;
    return 0;
}