//Link: https://juez.oia.unsam.edu.ar/tasks/bloques
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
#define fore(i, a, b) for (i = (a); i <= (b); i++)
using namespace std;

const ll INF = LLONG_MAX;
const int MAXN = 1000005;

ll a[MAXN], b[MAXN], n, k;

vector<pair<ll, ll>> v, v2;

ll cal(ll cost, ll act)
{
    ll i;
    fore(i, 0, n - 1)
    {
        if (sz(v) && v.back().fr == i)
        {
            act += v.back().se;
            v.pop_back();
        }
        act -= b[i];
        while (act < 0 && sz(v))
        {
            if (v.back().se <= -act)
            {
                act += v.back().se;
                cost += v.back().se * (v.back().fr - i);
                v.pop_back();
            }
            else
            {
                v.back().se += act;
                cost += (-act) * (v.back().fr - i);
                act = 0;
            }
        }
        if (act < 0)
        {
            cost += k * (-act);
            cost += (n - (i + 1)) * (-act);
            act = 0;
        }
        if(i<n-1)
            cost += act;
        else
            cost+=act*k;
    }
    return cost;
}

ll calc(ll x)
{
    ll cost = x * k, act = x;
    v = v2;
    return cal(cost, act);
}

ll calc2(ll x)
{
    ll cost = (-x)*k, act = x;
    v = v2;
    while (act < 0 && sz(v))
    {
        if (v.back().se <= -act)
        {
            act += v.back().se;
            cost += v.back().se * v.back().fr;
            v.pop_back();
        }
        else
        {
            v.back().se += act;
            cost += (-act) * v.back().fr;
            act = 0;
        }
    }
    if(act<0)
        return INF;
    return cal(cost, act);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, r = 0, l, piv, pos = INF, r2 = 0, po, sig;
    cin >> n >> k;

    fore(i, 0, n - 1)
    {
        cin >> a[i];
        r2 = r2 + a[i];
        if (a[i])
            v2.pb({i, a[i]});
    }

    fore(i, 0, n - 1)
    {
        cin >> b[i];
        r = r + b[i];
    }

    if(sz(v2))
        reverse(all(v2));

    l=0;
    while(l<=r)
    {
        piv=(l+r)/2;
        po=calc(piv);
        sig=calc(piv+1);
        pos=min(pos,po);
        pos=min(pos,sig);

        if(po==sig)
            break;
        if(po>sig)
            l=piv+1;
        else
            r=piv-1;
        
    }

    l=-r2;
    r=-1;

    while(l<=r)
    {
        piv=(l+r)/2;
        po=calc2(piv);
        sig=calc2(piv+1);
        pos=min(pos,po);
        pos=min(pos,sig);

        if(po==sig)
            break;
        if(po>sig)
            l=piv+1;
        else
            r=piv-1;
        
    }
    cout << pos;
    return 0;
}
