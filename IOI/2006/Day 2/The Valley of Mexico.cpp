//Link: https://www.spoj.com/problems/MEXICO/
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

const int MAXN = 2001;

bool can[MAXN][MAXN], vis[MAXN][MAXN][2], dp[MAXN][MAXN][2];

ll c, sig;
void ans(ll l, ll r, ll fin)
{
    while(l <= r)
    {
        sig = dp[l][r][fin];
        if (fin == 0)
        {
            if (l <= c)
                cout << l << '\n';
            else
                cout << l - c << '\n';
            l++;
        }
        else
        {
            if (r <= c)
                cout << r << '\n';
            else
                cout << r - c << '\n';
            r--;
        }
        fin=sig;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a, b, i, j, fin, l, r, k;
    cin >> c >> n;

    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        can[b][a + c] = can[a + c][b] = can[b + c][a] = can[a][b + c] = can[b + c][a + c] = can[a + c][b + c] = can[a][b] = can[b][a] = 1;
    }
    if (c == 1)
    {
        cout << 1 << '\n';
        return 0;
    }


    for (i = 1; i <= c; i++)
        vis[i][i][0] = vis[i][i][1] = 1;

    for (i = 2; i < c; i++)
    {
        for (j=1; j<=c; j++)
        {
            for(k=0; k<2; k++)
            {
                fin=k;
                l=j;
                r=j+i-1;
                if (!fin)
                {
                    if (can[l][l + 1] && vis[l + 1][r][0])
                    {
                        vis[l][r][fin]=1;
                        dp[l][r][fin] = 0;
                        continue;
                    }
                    else if (can[l][r] && vis[l + 1][r][1])
                    {
                        vis[l][r][fin]=1;
                        dp[l][r][fin] = 1;
                        continue;
                    }
                }
                else
                {
                    if (can[r][r - 1] && vis[l][r - 1][1])
                    {
                        vis[l][r][fin]=1;
                        dp[l][r][fin] = 1;
                        continue;
                    }
                    else if (can[r][l] && vis[l][r - 1][0])
                    {
                        vis[l][r][fin]=1;
                        dp[l][r][fin] = 0;
                        continue;
                    }
                }
                vis[l][r][fin] = 0;
            }
        }
    }
    for (i = 1; i <= c; i++)
    {
        if (can[i][i + 1] && vis[i + 1][c + i - 1][0])
        {
            cout << i << '\n';
            ans(i + 1, c + i - 1, 0);
            return 0;
        }
        else if (can[i][c + i - 1] && vis[i + 1][c + i - 1][1])
        {
            cout << i << '\n';
            ans(i + 1, c + i - 1, 1);
            return 0;
        }
    }
    cout << -1;

    return 0;
}
