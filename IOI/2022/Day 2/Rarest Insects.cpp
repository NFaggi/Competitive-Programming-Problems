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

void move_inside(int i);
void move_outside(int i);
int press_button();

vector<bool> vis, en;
map<vector<bool>, ll> memo;
ll n;
void mi(ll x)
{
    en[x] = 1;
}

void mo(ll x)
{
    en[x] = 0;
}

ll pBtn()
{
    ll x=memo[en];
    if(x)
        return x;
    for(ll i=0; i<sz(en); i++)
    {
        if(vis[i]!=en[i])
        {
            if(vis[i])
                move_outside(i);
            else
                move_inside(i);
            vis[i]=en[i];
        }
    }
    x=press_button();
    memo[vis]=x;
    return x;
}
int min_cardinality(int N)
{
    ll i, act = 0;
    n = N;
    vis.resize(N, 0);
    en.resize(N, 0);
    vector<ll> in, out, ins;
    for (i = 0; i < n; i++)
        ins.pb(i);

    for (auto k : ins)
    {
        mi(k);
        if (pBtn() > 1)
        {
            mo(k);
            out.pb(k);
        }
        else
        {
            in.pb(k);
            act++;
        }
    }
    ll l = 1, r = n / act, piv, pos = 1, tot = act;
    ins = out;
    while (l <= r)
    {
        piv = (l + r + 1) / 2;

        in.resize(0);
        out.resize(0);
        for (auto k : ins)
        {
            mi(k);
            if (pBtn() > piv)
            {
                mo(k);
                out.pb(k);
            }
            else
            {
                in.pb(k);
                act++;
            }
        }

        if (act == tot * piv)
        {
            l = piv + 1;
            pos = piv;
            ins = out;
        }
        else
        {
            r = piv - 1;
            for (auto k : in)
            {
                mo(k);
                act--;
            }
            ins = in;
        }
    }

    return int(pos);
}

