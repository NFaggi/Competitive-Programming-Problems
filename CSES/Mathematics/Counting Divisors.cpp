#include <bits/stdc++.h>
using namespace std;
const int tam=1e6+1;
int dp[tam];
int main()
{
    
    int n, x, i, j, ra;
    cin >> n;
    for(i=1; i<tam; i++)
    {
        for(j=i; j<tam; j+=i)
            dp[j]++;
    }
    for(i = 0; i < n; i++)
    {
        cin >> x;
        
        cout << dp[x] << endl;
    }
    return 0;
}