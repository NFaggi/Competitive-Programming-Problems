//link: https://juez.oia.unsam.edu.ar/task/56
//score: 100/100
#include <bits/stdc++.h>
using namespace std;
vector<long long>dias;
long long d, i, f;
bool can(long long piv)
{
    for(i=piv; i<=d; i++)
    {
        if(dias[i]-dias[i-piv]<=f)
            return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, a, mi=0, ma, piv, pos;
    cin >> n >> d >> f;
    dias.resize(d+1,1);
    ma=d;
    for(i=0; i<n; i++)
    {
        cin >> a;
        dias[a]=0;
    }
    dias[0]=0;
    for(i=1; i<=d; i++)
    {
        dias[i]+=dias[i-1];
    }
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(piv))
        {
            mi=piv+1ll;
            pos=piv;
        }
        else
        {
            ma=piv-1ll;
        }
    }
    cout << pos;
    return 0;
}
