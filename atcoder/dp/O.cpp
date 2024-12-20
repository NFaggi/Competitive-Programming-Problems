#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
const int MAXN=21;
const int MAXTAM=(1<<21);
ll dp[MAXTAM],mat[MAXN][MAXN];
int main()
{
    int n, i, j, tam, mask;
    cin >> n;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin >> mat[i][j];
    tam=(1<<n);
    dp[0]=1;
    for(mask=1; mask<tam; mask++)
    {
        i=__builtin_popcount(mask)-1;
        for(j=0; j<n; j++)
            if((1<<j)&mask)
            {
                if(mat[i][j])
                {
                    dp[mask]=(dp[mask]+dp[mask^(1<<j)])%MOD;
                }
            }
    }
    cout << dp[tam-1];
    return 0;
}
