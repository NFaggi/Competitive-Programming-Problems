//Link: https://juez.oia.unsam.edu.ar/tasks/ioi.2006.day1.pyramid
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

const int MAXN = 3001;
const ll INF = 1e18;

vector<vector<ll>> seg;
vector<ll> I, D;
ll pot = 1;
multiset<vector<ll>> s[MAXN];

void update(ll nod, ll i, ll j)
{
    vector<ll> x;
    auto it = s[nod - pot].begin();
    x = *it;
    if (x != seg[nod])
    {
        seg[nod] = x;
        nod /= 2;
        while (nod > 0)
        {
            seg[nod] = min(seg[nod * 2], seg[nod * 2 + 1]);
            nod /= 2;
        }
    }
}

void ad(ll nod, ll x, ll i, ll j)
{
    s[nod - pot].insert({x,i,j});
    update(nod, i, j);
}

void del(ll nod, ll x, ll i, ll j)
{
    ll p = nod - pot;
    auto it = s[p].find({x,i,j});
    s[p].erase(it);
    update(nod,i,j);
}

vector<ll> calc(ll a, ll b, ll nod)
{
    if (I[nod] > b || D[nod] < a)
        return {INF,0,0};
    if (I[nod] >= a && D[nod] <= b)
        return seg[nod];
    return min(calc(a, b, nod * 2), calc(a, b, nod * 2 + 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m, n, a, b, c, d, i, j, x;
    cin >> m >> n >> a >> b >> c >> d;

    vector<vector<ll>> mat(n*2 + 1, vector<ll>(m*2 + 1)), sum(n*2 + 1, vector<ll>(m*2 + 1, 0));

    fore(i, 1, n)
    {
        fore(j, 1, m)
        {
            cin >> mat[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
        }
    }

    while (pot < m)
        pot *= 2;
    seg.resize(pot * 2, {INF,0,0});
    I.resize(pot * 2);
    D.resize(pot * 2);

    for (i = pot; i < pot * 2; i++)
    {
        I[i] = D[i] = i;
        if (i - pot <= m)
            s[i - pot].insert({INF,0,0});
    }

    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
    }

    auto cal = [&](ll p1, ll p2, ll p3, ll p4)
    {
        return sum[p1 + p4 - 1][p2 + p3 - 1] - sum[p1 - 1][p2 + p3 - 1] - sum[p1 + p4 - 1][p2 - 1] + sum[p1 - 1][p2 - 1];
    };
    fore(i, 2, b - d)
    {
        fore(j, 2, m - c)
        {
            x = cal(i, j, c, d);
            ad(j + pot, x, i, j);
        }
    }
    ll in = b-d;
    vector<ll>v, ans={0,0,0,0,0};
    fore(j, in + 1, n)
    {
        if(j-in+b-1>n)
            break;
        fore(i, 1, m - a + 1)
        {
            x = cal(j-in, i, a, b);
            v=calc(i + 1 + pot, i + a - 1 - c + pot, 1);
            v[0]=x-v[0];
            v.pb(j-in);
            v.pb(i);
            ans = max(ans, v);
        }
        fore(i, 2, m - c)
        {
            x = cal(j - in+1, i, c, d);
            del(i + pot, x, j- in+1, i);
            x = cal(j, i, c, d);
            ad(i + pot, x, j, i);
        }
    }
    cout << ans[4] << ' ' << ans[3] << '\n' << ans[2] << ' ' << ans[1];
    return 0;
}
