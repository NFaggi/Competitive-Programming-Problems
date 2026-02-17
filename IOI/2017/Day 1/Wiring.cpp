//Link: https://oj.uz/problem/view/IOI17_wiring
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

long long min_total_length(std::vector<int> r, std::vector<int> b)
{
    ll INF = 1e14 + 1;
    vector<ll> dp(sz(r) + sz(b), INF);
    vector<vector<ll>> v, pref;
    ll i = 0, j = 0, sum, curr;
    vector<ll> act;
    while (i < sz(r) || j < sz(b))
    {
        act = {};
        while (i < sz(r) && (j >= sz(b) || r[i] < b[j]))
        {
            act.pb(r[i]);
            i++;
        }
        if (sz(act))
        {
            v.pb(act);
            continue;
        }
        act = {};
        while (j < sz(b) && (i >= sz(r) || r[i] > b[j]))
        {
            act.pb(b[j]);
            j++;
        }
        if (sz(act))
        {
            v.pb(act);
            continue;
        }
    }
    for (i = 0; i < sz(v); i++)
    {
        act = {};
        sum = 0;
        for (j = 0; j < sz(v[i]); j++)
        {
            sum += v[i][j];
            act.pb(sum);
        }
        pref.pb(act);
    }
    curr = sz(v[0]);
    ll k, mid, in, ac, fin, cost, cant, L = sz(v[0]), ant;
    for (i = 1; i < sz(v); i++)
    {
        mid = v[i][0] - v[i - 1].back();
        in = v[i][0];
        fin = v[i - 1].back();
        sum = 0;
        vector<ll> mi, ma;
        ac = 0;
        cant = 0;
        for (k = sz(v[i - 1]) - 1; k >= 0; k--)
        {
            cant++;
            ac += fin - v[i - 1][k];
            cost = ac;
            ant = 0;
            if (L - 1 - cant >= 0)
                ant = min(dp[L - 1 - cant], dp[L - cant]);
            if (sz(mi) == 0)
                mi.pb(ant + cost);
            else
                mi.pb(min(mi.back(), ant + cost));
            ma.pb(ant + cost + mid * cant);
        }
        for(k=sz(ma)-2; k>=0; k--)
            ma[k]=min(ma[k],ma[k+1]);
        for (j = 0; j < sz(v[i]); j++)
        {
            sum += v[i][j] - in;
            if(j<sz(v[i-1]))
                dp[L+j]=min(mi[j]+mid*(j+1),ma[j])+sum;
            else
                dp[L+j]=mi.back()+mid*(j+1)+sum;
        }
        L += sz(v[i]);
    }
    return dp.back();
}
