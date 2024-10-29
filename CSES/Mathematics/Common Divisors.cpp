#include <bits/stdc++.h>
 
using namespace std;
int dp[int(1e6)+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, i,j,seg, cont;
    bool ap;
    cin >> n;
    int ma=1;
    for(i=0; i<n; i++)
    {
        cin >> a;
        dp[a]++;
    }
    for(i=int(1e6); i>=1; i--)
    {
        cont =0;
        for(j=i; j<=int(1e6)+1; j+=i)
        {
            cont+=dp[j];
            if(cont>=2)
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << ma;
    return 0;
}