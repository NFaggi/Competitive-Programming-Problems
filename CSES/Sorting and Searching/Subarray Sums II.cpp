#include<bits/stdc++.h>
using namespace std;
map<long long,int>sums;
int main()
{
    int n, i;
    long long x, a,sum=0, cant=0;
    cin >> n >> x;
    sums[sum]++;
    for(i=0; i<n; i++)
    {
        cin >> a;
        sum+=a;
        cant+=sums[sum-x];
        sums[sum]++;
    }
    cout << cant;
    return 0;
}