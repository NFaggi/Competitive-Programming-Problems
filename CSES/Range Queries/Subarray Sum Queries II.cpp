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

struct nodo
{
    ll ma = 0, maI = 0, maD = 0, sum = 0;
};

vector<nodo> seg;
vector<ll> I, D;
nodo vacio;

void calcMa(nodo a, nodo b, nodo &c)
{
    c.sum = a.sum + b.sum;
    c.maI = max(a.maI, a.sum + b.maI);
    c.maD = max(a.maD + b.sum, b.maD);
    c.ma = max(a.ma, b.ma);
    c.ma = max(c.ma, a.maD + b.maI);
    c.ma = max(c.ma, max(c.sum, max(c.maI, c.maD)));
}

nodo calc(ll l, ll r, ll nod)
{
    if (I[nod] > r || D[nod] < l)
        return vacio;
    if (I[nod] >= l && D[nod] <= r)
        return seg[nod];

    nodo act;
    calcMa(calc(l,r,nod*2),calc(l,r,nod*2+1),act);
    return act;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n, q, i, pot = 1, x, a, b;
    cin >> n >> q;
    while (pot < n)
        pot *= 2;
    seg.resize(pot * 2);
    I.resize(pot * 2);
    D.resize(pot * 2);
    for (i = 0; i < n; i++)
    {
        cin >> x;
        seg[i + pot].sum = x;
        seg[i + pot].maD = seg[i + pot].maI = seg[i + pot].ma = max(0ll, x);
    }

    for (i = pot; i < pot * 2; i++)
        I[i] = D[i] = i;

    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];

        calcMa(seg[i * 2], seg[i * 2 + 1], seg[i]);
    }

    while (q--)
    {
        cin >> a >> b;
        cout << calc(a - 1 + pot, b - 1 + pot, 1).ma << '\n';
    }
    return 0;
}
