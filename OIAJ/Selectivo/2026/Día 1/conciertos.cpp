//Link: https://juez.oia.unsam.edu.ar/tasks/conciertos
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define fr first
#define all(x) x.begin(), x.end()
#define se second
#define pb push_back
using namespace std;

const int MAXN = 4e4 + 5, MAXTOT = 8e4 + 5;
bitset<MAXN> dp[MAXTOT], vis, sig, pos[17], ac, opt[17][17];

string conciertos(string &figuras)
{
    vector<ll> notas;
    ll i, tot = 0, act = 0;
    string s;
    for (i = 0; i < sz(figuras); i++)
    {
        s = "";
        s = s + char(figuras[i]);
        if (i + 1 < sz(figuras) && figuras[i + 1] == '*')
        {
            i++;
            s = s + char(figuras[i]);
        }
        if (s == "r")
            notas.pb(16);
        else if (s == "b*")
            notas.pb(12);
        else if (s == "b")
            notas.pb(8);
        else if (s == "n*")
            notas.pb(6);
        else if (s == "n")
            notas.pb(4);
        else if (s == "c*")
            notas.pb(3);
        else if (s == "c")
            notas.pb(2);
        else
            notas.pb(1);
        tot = tot + notas.back();
    }
    tot = tot / 2;

    vis[0] = 1;
    vis[notas[0]] = 1;
    dp[0][notas[0]] = 1;
    act = notas[0];

    ll j, a, b, ma, mod = 16;
    for (ll k = 1; k <= 16; k++)
    {
        for (j = 0; j <= tot; j++)
        {
            b = j;

            ma = b % mod;
            ma = 16 - ma;
            if (ma >= k && j + k <= tot)
                pos[k][j + k] = 1;
        }
        for (ll o = 1; o <= 16; o++)
        {
            for (j = 0; j <= tot; j++)
            {
                a = ((k % mod) - (j % mod) + mod) % mod;
                ma = a % mod;
                ma = 16 - ma;
                if (ma >= o)
                    opt[k%mod][o][j] = 1;
            }
        }
    }
    for (i = 1; i < sz(notas); i++)
    {
        ac.reset();
        ac |= (pos[notas[i]] & (vis << notas[i]));
        sig |= ac;
        dp[i] |= ac;

        a=act%mod;
        b=notas[i];

        ac.reset();
        ac|=(opt[a][b]&vis);

        sig|=ac;

        swap(sig, vis);
        sig.reset();
        act = act + notas[i];
    }

    i = sz(notas) - 1;
    j = tot;

    string ans = "";
    for (auto k : notas)
        ans = ans + '1';
    while (i >= 0)
    {
        if (dp[i][j])
        {
            j -= notas[i];
            ans[i] = '2';
        }
        i--;
    }
    return ans;
}
