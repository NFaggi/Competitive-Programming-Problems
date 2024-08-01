#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    long long a, b, c, aA=0, aB=0, aC=0;
    cin >> n;
    vector<int>v(n);
    vector<long long>miV(n,LLONG_MAX);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    miV[0]=0;
    for(i=0; i<n-1; i++)
    {
        if(i<n-1)
        {
            miV[i+1]=min(miV[i+1],miV[i]+abs(v[i]-v[i+1]));
            miV[i+2]=min(miV[i+2],miV[i]+abs(v[i]-v[i+2]));
        }
        else
        {
            miV[i+1]=min(miV[i+1],miV[i]+abs(v[i]-v[i+1]));
        }
    }
    cout << miV[n-1];
    return 0;
}