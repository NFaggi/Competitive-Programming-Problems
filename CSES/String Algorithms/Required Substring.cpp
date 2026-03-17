#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN=1001, MAXM=101, MOD=1e9+7;

ll dp[MAXN][MAXM], lps[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, i, j, m, k, len=0;
    string s;
    char c;

    cin >> n >> s;

    m=sz(s);
    for(i=1; i<m; i++)
    {
        while(len>0&&s[len]!=s[i])
            len=lps[len-1];
        if(s[len]==s[i])
            len++;
        lps[i]=len;
    }

    dp[0][0]=25;
    dp[0][1]=1;
    for(i=1; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            for(k=0; k<26; k++)
            {
                len=j;
                c=char('A'+k);
                while(len>0&&s[len]!=c)
                    len=lps[len-1];
                if(s[len]==c)
                    len++;
                dp[i][len]=(dp[i][len]+dp[i-1][j])%MOD;
            }
        }
        dp[i][m]=(dp[i][m]+(dp[i-1][m]*26ll)%MOD)%MOD;
    }
    cout << dp[n-1][m];
    return 0;
}
