//Link: https://codeforces.com/problemset/problem/479/E
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

const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b, k, dis, tam, in, fin, ans = 0, i, j;
    cin >> n >> a >> b >> k;
    dis = abs(a - b);
    dis--;
    if(b<a)
    {
        in=b+1;
        fin=n;
    }
    else
    {
        in=1;
        fin=b-1;
    }
    if (k == 1)
    {
        dis=abs(a-b);
        dis--;
        in=max(1ll,a-dis);
        fin=min(n,a+dis);
        cout << (fin-in) % MOD;
        return 0;
    }
    tam = (fin - in) + 1;
    vector<ll> v(tam, 0), upd1, upd2, dist(tam);
    for (i = 0; i < tam; i++)
        dist[i] = abs((i + in) - b);
    a -= in;
    for (i = 0; i < tam; i++)
    {
        if (i == a||abs(i-a)>=abs((a+in)-b))
            continue;
        v[i] = 1;
    }

    for (i = 2; i < k; i++)
    {
        upd1.assign(tam, 0);
        for (j = 0; j < tam; j++)
        {
            if (j + 1 < tam)
            {
                upd1[j + 1] = (upd1[j + 1] + v[j]) % MOD;
                if (j + dist[j] < tam)
                    upd1[j + dist[j]] = (upd1[j + dist[j]] - v[j] + MOD) % MOD;
            }
            if (j > 0)
                upd1[j] = (upd1[j] + upd1[j - 1]) % MOD;
        }

        upd2.assign(tam, 0);
        for (j = tam - 1; j >= 0; j--)
        {
            if (j - 1 >= 0)
            {
                upd2[j - 1] = (upd2[j - 1] + v[j]) % MOD;
                if (j - dist[j] >= 0)
                    upd2[j - dist[j]] = (upd2[j - dist[j]] - v[j] + MOD) % MOD;
            }
            if (j + 1 < tam)
            {
                upd2[j] = (upd2[j] + upd2[j + 1]) % MOD;
            }
        }

        for (j = 0; j < tam; j++)
        {
            v[j] = (upd1[j] + upd2[j]) % MOD;
        }
    }

    for (i = 0; i < tam; i++)
    {
        in = max(0ll, i - (dist[i] - 1));
        fin = min(tam - 1, i + (dist[i] - 1));
        ans = (ans + (v[i] * ((fin - in) % MOD)) % MOD) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
