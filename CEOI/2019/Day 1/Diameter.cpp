#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
 
const int MAXN = 1e5 + 1;
const int LOG = 17;
 
vector<pair<ll, long long>> grafo[MAXN];
vector<ll> centTree[MAXN];
ll subTam[MAXN], delv[MAXN], centFather[MAXN], profCent[MAXN], nodId[MAXN][LOG], centId[MAXN][LOG], up[MAXN], nods[MAXN];
vector<long long> seg[MAXN], lazy[MAXN];
vector<ll> I[MAXN], D[MAXN];
ll pot[MAXN], tim;
unordered_map<ll, pair<ll, ll>> rangs[MAXN];
vector<ll> prof[MAXN];
vector<ll> antCent2[MAXN];
multiset<long long> s[MAXN];
multiset<long long> global;
vector<vector<ll>> ars;
ll raiz = -1;
 
void dfsTams(ll nod, ll pad) {
    subTam[nod] = 1;
    for (auto &k : grafo[nod]) {
        if (k.fr == pad || delv[k.fr])
            continue;
        dfsTams(k.fr, nod);
        subTam[nod] += subTam[k.fr];
    }
}
 
ll searchCentroid(ll nod, ll pad, ll &n) {
    for (auto &k : grafo[nod]) {
        if (k.fr == pad || delv[k.fr])
            continue;
        if (subTam[k.fr] > n / 2)
            return searchCentroid(k.fr, nod, n);
    }
    return nod;
}
 
void dfsMarc(ll nod, ll pad, ll &ant, ll &act, ll pro) {
    antCent2[act].pb(ant);
    nodId[nod][up[nod]] = nods[act]++;
    centId[nod][up[nod]++] = act;
    prof[act].pb(pro);
    for (auto &k : grafo[nod]) {
        if (delv[k.fr] || pad == k.fr)
            continue;
        dfsMarc(k.fr, nod, ant, act, pro + 1);
    }
}
 
void prog(ll nod, ll &act) {
    if (nod * 2 < (ll)seg[act].size()) {
        seg[act][nod * 2] += lazy[act][nod];
        lazy[act][nod * 2] += lazy[act][nod];
    }
    if (nod * 2 + 1 < (ll)seg[act].size()) {
        seg[act][nod * 2 + 1] += lazy[act][nod];
        lazy[act][nod * 2 + 1] += lazy[act][nod];
    }
    lazy[act][nod] = 0;
}
 
void update(ll &a, ll &b, ll nod, long long x, ll &act) {
    if (I[act][nod] > b || D[act][nod] < a)
        return;
    if (I[act][nod] >= a && D[act][nod] <= b) {
        lazy[act][nod] += x;
        seg[act][nod] += x;
        return;
    }
    prog(nod, act);
    update(a, b, nod * 2, x, act);
    update(a, b, nod * 2 + 1, x, act);
    seg[act][nod] = max(seg[act][nod * 2], seg[act][nod * 2 + 1]);
}
 
void dfsRangs(ll nod, ll pad, ll &act) {
    rangs[act][nod].fr = tim++;
    for (auto &k : grafo[nod]) {
        if (delv[k.fr] || pad == k.fr)
            continue;
        dfsRangs(k.fr, nod, act);
        seg[act][rangs[act][k.fr].fr + pot[act]] += k.se;
        ll r = rangs[act][k.fr].se + pot[act];
        if (r + 1 < sz(seg[act]))
            seg[act][r + 1] -= k.se;
    }
    rangs[act][nod].se = tim++;
}
 
long long calc(ll &a, ll &b, ll nod, ll &act) {
    if (I[act][nod] > b || D[act][nod] < a)
        return 0;
    if (I[act][nod] >= a && D[act][nod] <= b)
        return seg[act][nod];
    prog(nod, act);
    return max(calc(a, b, nod * 2, act), calc(a, b, nod * 2 + 1, act));
}
 
void constructCentroidTree(ll nod, ll pad) {
    dfsTams(nod, 0);
    ll centroid = searchCentroid(nod, 0, subTam[nod]), i;
    if (raiz == -1)
        raiz = centroid;
    nodId[centroid][up[centroid]] = nods[centroid]++;
    centId[centroid][up[centroid]++] = centroid;
    prof[centroid].pb(0);
    antCent2[centroid].pb(centroid);
 
    if (pad != 0) {
        centTree[pad].pb(centroid);
        centFather[centroid] = pad;
    } else {
        centFather[centroid] = 0;
    }
 
    delv[centroid] = 1;
 
    for (auto &k : grafo[centroid]) {
        if (delv[k.fr])
            continue;
        dfsMarc(k.fr, centroid, k.fr, centroid, 1);
    }
 
    pot[centroid] = 1;
    while (pot[centroid] < subTam[nod] * 2 + 5)
        pot[centroid] <<= 1;
 
    seg[centroid].resize(pot[centroid] * 2, 0);
    lazy[centroid].resize(pot[centroid] * 2, 0);
    I[centroid].resize(pot[centroid] * 2, 0);
    D[centroid].resize(pot[centroid] * 2, 0);
 
    tim = 1;
    dfsRangs(centroid, 0, centroid);
    for (i = pot[centroid]; i < pot[centroid] * 2; ++i) {
        I[centroid][i] = D[centroid][i] = i;
        if (i > 0)
            seg[centroid][i] += seg[centroid][i - 1];
    }
    for (i = pot[centroid] - 1; i > 0; --i) {
        I[centroid][i] = I[centroid][i * 2];
        D[centroid][i] = D[centroid][i * 2 + 1];
        seg[centroid][i] = max(seg[centroid][i * 2], seg[centroid][i * 2 + 1]);
    }
    ll p1, p2;
    for (auto &k : grafo[centroid]) {
        if (delv[k.fr])
            continue;
        p1 = rangs[centroid][k.fr].fr + pot[centroid], p2 = rangs[centroid][k.fr].se + pot[centroid];
        s[centroid].insert(calc(p1, p2, 1, centroid));
    }
 
    for (auto &k : grafo[centroid]) {
        if (delv[k.fr])
            continue;
        constructCentroidTree(k.fr, centroid);
    }
 
    long long ma = 0;
    if (sz(s[centroid])) {
        auto it = prev(s[centroid].end());
        ma += *it;
        if (it != s[centroid].begin()) {
            it = prev(it);
            ma += *it;
        }
    }
    global.insert(ma);
}
 
void profDFS(ll nod, ll pad) {
    for (auto &k : centTree[nod]) {
        profCent[k] = profCent[nod] + 1;
        profDFS(k, nod);
    }
}
 
ll LCA(ll a, ll b) {
    if (profCent[b] > profCent[a])
        swap(a, b);
    while (profCent[a] > profCent[b])
        a = centFather[a];
    while (a != b) {
        a = centFather[a];
        b = centFather[b];
    }
    return a;
}
 
long long d, e;
void actu(ll nod, ll ia, ll ib) {
    if (nod == 0)
        return;
    ll a = ars[d][0], b = ars[d][1], i, inv = 0;
 
    if (prof[nod][nodId[a][ia]] < prof[nod][nodId[b][ib]]) {
        swap(a, b);
        swap(ia, ib);
        inv = 1;
    }
    b = nodId[a][ia];
    b = antCent2[nod][b];
 
    long long ma = 0;
    if (sz(s[nod])) {
        auto itmax = prev(s[nod].end());
        ma = *itmax;
        if (itmax != s[nod].begin()) {
            itmax = prev(itmax);
            ma += *itmax;
        }
    }
 
    ll p1, p2, p3, p4;
    p1 = rangs[nod][b].fr + pot[nod];
    p2 = rangs[nod][b].se + pot[nod];
    auto itfind = s[nod].find(calc(p1, p2, 1, nod));
    if (itfind != s[nod].end())
        s[nod].erase(itfind);
 
    itfind = global.find(ma);
    if (itfind != global.end())
        global.erase(itfind);
    p3 = rangs[nod][a].fr + pot[nod];
    p4 = rangs[nod][a].se + pot[nod];
    update(p3, p4, 1, e, nod);
 
    s[nod].insert(calc(p1, p2, 1, nod));
 
    ma = 0;
    auto it = prev(s[nod].end());
    ma += *it;
    if (it != s[nod].begin()) {
        it = prev(it);
        ma += *it;
    }
    global.insert(ma);
    if (inv)
        swap(ia, ib);
    actu(centFather[nod], ia - 1, ib - 1);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, a, b, ia, ib, i;
    long long c, w;
    if (!(cin >> n >> q >> w))
        return 0;
    for (i = 0; i < n - 1; ++i) {
        cin >> a >> b >> c;
        grafo[a].pb({b, c});
        grafo[b].pb({a, c});
        ars.pb({a, b, c});
    }
 
    constructCentroidTree(1, 0);
 
    profCent[raiz] = 0;
    profDFS(raiz, 0);
 
    long long res = 0;
    while (q--) {
        cin >> d >> e;
        d = (d + res) % (n - 1);
        e = (e + res) % w;
        e = e - ars[d][2];
        a = ars[d][0];
        b = ars[d][1];
        c = LCA(a, b);
 
        for (i = 0; i < LOG; i++) {
            if (centId[a][i] == c) {
                ia = i;
                break;
            }
        }
 
        for (i = 0; i < LOG; i++) {
            if (centId[b][i] == c) {
                ib = i;
                break;
            }
        }
        actu(c, ia, ib);
        ars[d][2] += e;
        auto it = prev(global.end());
        res = *it;
        cout << res << '\n';
    }
 
    return 0;
}
