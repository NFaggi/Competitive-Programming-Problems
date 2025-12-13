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

const ll MAXX = 2e11;
const ll add = 1e11;

ll INF = LLONG_MAX;
struct nodo
{
    ll mi = INF;
    nodo *l = nullptr, *r = nullptr;
};

nodo *seg = new nodo();
map<ll, set<ll>> insY;
ll getMi(nodo *nod)
{
    if (nod == nullptr)
        return INF;
    return nod->mi;
}
void update(nodo *nod, ll pos, ll x, ll l = 0, ll r = MAXX)
{
    if (l == r)
    {
        nod->mi = x;
        return;
    }
    ll mid = (l + r) / 2;
    if (mid < pos)
    {
        if ((nod->r) == nullptr)
            nod->r = new nodo();
        update(nod->r, pos, x, mid + 1, r);
    }
    else
    {
        if ((nod->l) == nullptr)
            nod->l = new nodo();
        update(nod->l, pos, x, l, mid);
    }
    nod->mi = min(getMi(nod->l), getMi(nod->r));
}

ll cal(ll a, ll b, nodo *nod, ll l = 0, ll r = MAXX)
{
    if (nod == nullptr || l > b || r < a)
        return INF;
    if (l >= a && r <= b)
        return nod->mi;
    ll mid = (l + r) / 2;
    return min(cal(a, b, nod->l, l, mid), cal(a, b, nod->r, mid + 1, r));
}
ll cal2(ll a, ll b, nodo *nod, ll x, ll l = 0, ll r = MAXX)
{
    if (nod == nullptr || l > b || r < a || nod->mi >= x)
        return -1;
    if (l == r)
        return nod->mi;
    ll mid = (l + r) / 2;
    ll ans = cal2(a, b, nod->l, x, l, mid);
    if (ans != -1)
        return ans;
    return cal2(a, b, nod->r, x, mid + 1, r);
}

ll cal3(ll a, ll b, nodo *nod, ll x, ll l = 0, ll r = MAXX)
{
    if (nod == nullptr || l > b || r < a || nod->mi >= x)
        return -1;
    if (l == r)
        return nod->mi;
    ll mid = (l + r) / 2;
    ll ans = cal3(a, b, nod->r, x, mid + 1, r);
    if (ans != -1)
        return ans;
    return cal3(a, b, nod->l, x, l, mid);
}

pair<ll, ll> calc(vector<pair<char, ll>> &v)
{
    ll x = 0, y = 0, yAnt = 0, time, i, n = sz(v), j;
    seg = new nodo();
    insY.clear();
    vector<ll> alt(n);
    vector<pair<ll, ll>> ins, cons;
    vector<ll> inY(n), px(n);
    set<pair<ll, ll>> del;
    for (i = 0; i < n; i++)
    {
        yAnt = y;
        alt[i] = y;
        px[i] = x;
        if (v[i].fr == 'U')
            y += v[i].se;
        else if (v[i].fr == 'R')
            x += v[i].se;
        else if (v[i].fr == 'L')
            x -= v[i].se;
        else
            y -= v[i].se;
        if (v[i].fr == 'U' || v[i].fr == 'D')
        {
            ins.pb({min(y, yAnt), i});
            inY[i] = min(y, yAnt);
        }
        else
            cons.pb({y, i});
    }
    sort(all(ins));
    reverse(all(ins));
    sort(all(cons));

    ll mi = INF, with = n;
    for (i = 0; i < sz(cons); i++)
    {
        while (sz(ins) && ins.back().fr <= cons[i].fr)
        {
            y = ins.back().fr;
            time = ins.back().se;
            ins.pop_back();
            x = px[time] + add;
            if (!sz(insY[x]) || *prev(insY[x].end()) > time)
                update(seg, x, time);
            insY[x].insert(time);
            del.insert({y + v[time].se, time});
        }
        while (sz(del) && (del.begin())->fr < cons[i].fr)
        {
            auto it2 = del.begin();
            x = px[it2->se] + add;
            auto it = insY[x].find(it2->se);
            insY[x].erase(it);
            if (sz(insY[x]) == 0)
                update(seg, x, INF);
            else
                update(seg, x, *prev(insY[x].end()));
            del.erase(del.begin());
        }
        j = cons[i].se;
        x = px[j] + add;
        ll ag = v[j].se;
        if (v[j].fr == 'L')
            x -= ag;
        ll ret = cal(x, x + ag, seg);
        if (ret < j - 1)
        {
            if (mi > j)
            {
                mi = j;
                if(v[j].fr=='R')
                    with = cal2(x, x + ag, seg, j - 1);
                else
                    with = cal3(x, x + ag, seg, j - 1);
            }
        }
    }
    return {mi, with};
}

ll sum(ll mi, ll with, vector<pair<char, ll>> &v)
{
    ll x = 0, y = 0, ans = 0, n = sz(v), i, ag, ay, ax;
    vector<pair<ll, ll>> coords(n);
    bool fin=0;

    auto limite = [&]()
    {
        if (x == 0 && ag>abs(ay))
        {
            if (y < 0 && ay > 0)
            {
                ans -= ag;
                ans += abs(ay);
                fin=1;
            }
            else if (y > 0 && ay < 0)
            {
                ans -= ag;
                ans += abs(ay);
                fin=1;
            }
        }
        else if (y == 0 && ag>abs(ax))
        {
            if (x > 0 && ax < 0)
            {
                ans -= ag;
                ans += abs(ax);
                fin=1;
            }
            else if (x < 0 && ax > 0)
            {
                ans -= ag;
                ans += abs(ax);
                fin=1;
            }
        }
    };

    for (i = 0; i < n; i++)
    {
        if (mi == i)
        {
            if (mi - 1 == with)
                break;
            ax = x;
            ay = y;
            switch (v[i].fr)
            {
            case 'U':
                ag = abs(y - coords[with].se);
                ans += ag;
                y += ag;
                break;
            case 'D':
                ag = abs(y - coords[with].se);
                ans += ag;
                y -= ag;
                break;
            case 'L':
                ag = abs(x - coords[with].fr);
                ans += ag;
                x -= ag;
                break;
            default:
                ag = abs(x - coords[with].fr);
                ans += ag;
                x += ag;
                break;
            }
            limite();
            break;
        }
        else
        {
            ag = v[i].se;
            ans += ag;
            ax = x;
            ay = y;
            switch (v[i].fr)
            {
            case 'U':
                y += ag;
                break;
            case 'D':
                y -= ag;
                break;
            case 'L':
                x -= ag;
                break;
            default:
                x += ag;
                break;
            }
            limite();
            if(fin)
                break;
            coords[i] = {x, y};
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i;
    cin >> n;
    vector<pair<char, ll>> v(n), v2;
    for (i = 0; i < n; i++)
        cin >> v[i].fr >> v[i].se;
    v2 = v;
    pair<ll, ll> miP = {INF, INF};
    for (i = 0; i < n; i++)
    {
        switch(v2[i].fr)
        {
            case 'R': v2[i].fr = 'U'; break;
            case 'U': v2[i].fr = 'L'; break;
            case 'L': v2[i].fr = 'D'; break;
            default: v2[i].fr = 'R'; break;
        }
        if (i > 0 && ((v[i - 1].fr == 'U' && v[i].fr == 'D') || (v[i - 1].fr == 'R' && v[i].fr == 'L') || (v[i - 1].fr == 'D' && v[i].fr == 'U') || (v[i - 1].fr == 'L' && v[i].fr == 'R')))
            miP = min(miP, {i, i - 1});
    }
    pair<ll,ll>miP2=min(calc(v), calc(v2)), ans;
    if(miP.fr>miP2.fr)
        ans=miP2;
    else
        ans=miP;
    cout << sum(ans.fr, ans.se, v);
    return 0;
}
