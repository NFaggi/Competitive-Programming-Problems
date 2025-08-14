//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
 
const int MOD = 998244353;
const int ma = 62;
ll dis[8][ma][ma]; // tam, in, fin
ll memo[8][ma][ma][ma];
ll cant2[ma][ma][ma];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, tam, j, k, l, cant, act = 0, ant, tot = 0, u, an, bn, cn, dn;
    cin >> n;
    string s, a;
    map<string, bool> m;
    vector<ll> pos(max('z', max('Z','9')) + 1, 0);
    for (i = 'a'; i <= 'z'; i++)
        pos[i] = act++;
    for (i = 'A'; i <= 'Z'; i++)
        pos[i] = act++;
    for(i='0'; i<='9'; i++)
        pos[i]=act++;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        tam = sz(s);
        a = s;
        reverse(all(a));
        if (m[s] == 0)
        {
            dis[tam-3][pos[s[0]]][pos[s.back()]]++;
            m[s] = 1;
        }
        if (a != s && m[a] == 0)
        {
            dis[tam-3][pos[a[0]]][pos[a.back()]]++;
            m[a] = 1;
        }
    }
 
    for (tam = 3; tam <= 10; tam++)
    {
        for (i = 0; i < ma; i++)
        {
            for (j = i; j < ma; j++)
            {
                for (k = j; k < ma; k++)
                {
                    for (u = 0; u < ma; u++)
                    {
                        act = 1;
                        act = (1ll*act * dis[tam-3][i][u]) % MOD;
                        act = (1ll*act * dis[tam-3][j][u]) % MOD;
                        act = (1ll*act * dis[tam-3][k][u]) % MOD;
                        memo[tam-3][i][j][k] = (act + memo[tam-3][i][j][k]) % MOD;
                    }
                }
            }
        }
    }
 
    for (tam = 3; tam <= 10; tam++)
    {
        for (i = 0; i < ma; i++) // 1
        {
            for (j = i; j < ma; j++) // 2
            {
                for (k = j; k < ma; k++) // 3
                {
                    for (l = k; l < ma; l++) // 4
                    {
 
                        // 5
                        cant = 1;
                        cant2[i][k][l]++;
                        an = memo[tam-3][i][k][l];
 
                        // 6
                        bn = memo[tam-3][i][j][k];
                        cant2[i][j][k]++;
 
                        // 7
                        cn = memo[tam-3][j][k][l];
                        cant2[j][k][l]++;
 
                        // 8
                        dn = memo[tam-3][i][j][l];
                        cant2[i][j][l]++;
                        cant = (1ll*cant * an) % MOD;
                        cant = (1ll*cant * bn) % MOD;
                        cant = (1ll*cant * cn) % MOD;
                        cant = (1ll*cant * dn) % MOD;
                        ll count=(i==j)+(j==k)+(k==l);
                        if(count==0)
                            cant=(24ll*cant)%MOD;
                        else if(count==1)
                            cant=(12ll*cant)%MOD;
                        else if(count==2)
                        {
                            if(i==j&&k==l)
                                cant=(6ll*cant)%MOD;
                            else
                                cant=(4ll*cant)%MOD;
                        }
                        tot = (tot + cant) % MOD;
                    }
                }
            }
        }
    }
 
    cout << tot;
    return 0;
}
