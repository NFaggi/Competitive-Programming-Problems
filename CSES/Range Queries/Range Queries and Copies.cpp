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

const int MAXU = 2e5 + 1;

struct nodo
{
    ll l, r, val, num, k;
};
vector<ll>I, D;
vector<nodo> nods;

ll lev = 1, in[MAXU], lvU[MAXU];
vector<ll>reg;

void busc(ll a, ll b, ll nod)
{
    ll num = nods[nod].num;
    if (I[num] > b || D[num] < a)
        return;
    if (I[num] >= a && D[num] <= b)
    {
        reg.pb(nod);
        return;
    }
    reg.pb(nod);
    busc(a, b, nods[nod].l);
    busc(a, b, nods[nod].r);
}

void update(ll a, ll k, ll x)
{
    ll pos = in[k], num, p, i;
    reg.resize(0);
    nodo nw;
    busc(a, a, pos);
    pos = reg[sz(reg) - 1];
    if (nods[pos].k == k)
    {
        num = nods[pos].num;
        p = pos;
        nods[pos].val = x;
    }
    else
    {
        num = nods[pos].num;
        p = sz(nods);
        nods.pb(nods[pos]);
        nods[p].val = x;
        nods[p].k = k;
        nods[p].l = p;
        nods[p].r = p;
    }
    for (i = sz(reg) - 2; i >= 0; i--)
    {
        if (nods[reg[i]].k == k)
        {
            if (nods[nods[reg[i]].l].num == num)
                nods[reg[i]].l = p;
            else
                nods[reg[i]].r = p;
            nods[reg[i]].val = nods[nods[reg[i]].l].val + nods[nods[reg[i]].r].val;
            num = nods[reg[i]].num;
            p = reg[i];
        }
        else
        {
            nw = nods[reg[i]];
            nw.k = k;
            if (nods[nw.l].num == num)
                nw.l = p;
            else
                nw.r = p;
            nw.val = nods[nw.l].val + nods[nw.r].val;
            num = nw.num;
            p = sz(nods);
            nods.pb(nw);
        }
    }
}

ll calc(ll a, ll b, ll nod)
{
    ll num = nods[nod].num;
    if (I[num] > b || D[num] < a)
        return 0;
    if (I[num] >= a && D[num] <= b)
        return nods[nod].val;
    return calc(a, b, nods[nod].l) + calc(a, b, nods[nod].r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, pot = 1, a, b, k, x, op, act=1;
    nodo nw;
    cin >> n >> q;
    vector<ll>v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    while (pot < n)
        pot *= 2;
    vector<ll>nums(pot * 2, 0);
    I.resize(pot * 2);
    D.resize(pot * 2);
    for (i = pot; i < pot * 2; i++)
    {
        I[i] = D[i] = i;
        nw.l = sz(nods);
        nw.r = sz(nods);
        nums[i] = sz(nods);
        nw.num = i;
        nw.k = 0;
        if (i - pot < n)
            nw.val = v[i - pot];
        else
            nw.val = 0;
        nods.pb(nw);
    }
    for (i = pot - 1; i > 0; i--)
    {
        nums[i] = sz(nods);
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
        nw.l = nums[i * 2];
        nw.r = nums[i * 2 + 1];
        nw.k = 0;
        nw.num = i;
        nw.val = nods[nw.l].val + nods[nw.r].val;
        nods.pb(nw);
    }
    in[0] = sz(nods) - 1;
    lvU[0]=0;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> k >> a >> x;
            a--;
            k--;
            nods.pb(nods[in[lvU[k]]]);
            in[lev]=sz(nods)-1;
            lvU[k]=lev;
            nods[sz(nods) - 1].k = lev;
            lev++;
            update(a + pot, lvU[k], x);
        }
        else if (op == 2)
        {
            cin >> k >> a >> b;
            a--;
            b--;
            k--;
            cout << calc(a + pot, b + pot, in[lvU[k]]) << '\n';
        }
        else
        {
            cin >> k;
            k--;
            nods.pb(nods[in[lvU[k]]]);
            in[lev] = sz(nods) - 1;
            lvU[act]=lev;
            act++;
            nods[sz(nods) - 1].k = lev;
            lev++;
        }
    }
    return 0;
}
