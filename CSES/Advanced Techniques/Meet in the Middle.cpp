#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")
#pragma GCC optimize("Ofast,O3,unroll-all-loops,fast-math")
#pragma GCC target("avx,avx2,sse,sse2")
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define ll long long


using namespace std;

int main()
{
    ll n, x, i, j, tam, mask, sum,tot=0,mit1,mit2;
    scanf("%lld",&n);
    scanf("%lld",&x);
    vector<ll>v(n);
    for(i=0; i<n; i++)
        scanf("%lld",&v[i]);
    sort(v.begin(),v.end());
    unordered_map<ll,ll>m;
    mit1=n/2;
    mit2=n-mit1;
    tam=(1<<mit1);
    for(mask=0; mask<tam; mask++)
    {
        sum=0;
        for(j=0; j<mit1; j++)
        {
            if((1<<j)&mask)
            {
                sum+=v[j];
            }
        }
        m[sum]++;
    }
    tam=(1<<mit2);
    for(mask=0; mask<tam; mask++)
    {
        sum=0;
        for(j=0; j<mit2; j++)
        {
            if((1<<j)&mask)
            {
                sum+=v[j+mit1];
            }
        }
        tot+=m[x-sum];
    }
    printf("%lld",tot);
    return 0;
}
