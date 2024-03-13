#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, ant, a;
    long long sum=0;
    cin >> n;
    cin >> ant;
    for(i=1; i<n; i++)
    {
        cin >> a;
        if(ant>a)
        {
            sum+=ant-a;
        }
        else
            ant=a;
    }
    cout << sum;
    return 0;
}
