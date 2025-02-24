//Link: https://juez.oia.unsam.edu.ar/task/35
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

const int pot = 512;
ll cant[500][500];
ll st[pot * 2], I[pot * 2], D[pot * 2];

void update(ll nod, ll x)
{
    st[nod] += x;
    nod /= 2;
    while (nod > 0)
    {
        st[nod] = st[nod * 2] + st[nod * 2 + 1];
        nod /= 2;
    }
}

ll calc(ll a, ll b, ll nod)
{
    if (I[nod] > b || D[nod] < a)
        return 0;
    if (I[nod] >= a && D[nod] <= b)
        return st[nod];
    return calc(a, b, nod * 2) + calc(a, b, nod * 2 + 1);
}

bool cmp(const pair<ll,pair<ll,ll>> & a, const pair<ll,pair<ll,ll>> & b)
{
    if(a.fr!=b.fr)
        return a.fr>b.fr;
    return a.se.fr<b.se.fr;
}

int main()
{
    ifstream cin ("clima.in");
    ofstream cout ("clima.out");
    ll p, i, n, a, b, mi, ma, j;
    for (i = pot; i < pot * 2; i++)
        D[i] = I[i] = i;
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
    }
    cin >> p;
    vector<pair<ll, pair<ll, ll>>> v(p);
    for (i = 0; i < p; i++)
    {
        cin >> n;
        mi = LLONG_MAX;
        ma = LLONG_MIN;
        for (j = 0; j < n; j++)
        {
            cin >> a >> b;
            mi = min(a, mi);
            ma = max(b, ma);
        }
        v[i] = {mi + 60, {ma + 60, i + 1}};
    }
    sort(all(v),cmp);
    ma=0;
    vector<ll> hosts(p+1, 0), ans, notComp(p+1,0);
    for (i = 0; i < sz(v); i++)
    {
        j=v[i].se.se;
        hosts[j]=calc(pot,v[i].se.fr+pot-1,1);
        notComp[j]=i-calc(pot,v[i].se.fr+pot,1);
        if(ma<hosts[j])
        {
            ma=hosts[j];
            ans.resize(0);
            ans.pb(j);
        }
        else if(ma==hosts[j])
            ans.pb(j);
        update(v[i].se.fr+pot,1);
    }
    for(i=0; i<sz(v); i++)
    {
        update(v[i].se.fr+pot,-1);
    }
    for(i=sz(v)-1; i>=0; i--)
    {
        notComp[v[i].se.se]+=calc(pot,v[i].se.fr+pot-1,1);
        update(v[i].se.fr+pot,1);
    }
    sort(all(ans));
    for(auto k:ans)
    {
        cout << k << ' ' << notComp[k] << '\n';
    }
    return 0;
}
