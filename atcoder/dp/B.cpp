#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, k;
    long long a, b, c, aA=0, aB=0, aC=0;
    cin >> n >> k;
    vector<int>v(n);
    vector<long long>miV(n,LLONG_MAX);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    miV[0]=0;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<min(i+k+1,n); j++)
        {
            miV[j]=min(miV[j],miV[i]+abs(v[i]-v[j]));
        }
    }
    cout << miV[n-1];
    return 0;
}
