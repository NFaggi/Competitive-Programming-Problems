#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n,sum=0;
    cin >> n;
    vector <int> x(n);
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }
    for(int i=0;i<n-1; i++)
    {
        if(x[i]>x[i+1])
        {
            sum+=x[i]-x[i+1];
            x[i+1]=x[i];
        }
    }
    cout << sum;
}
