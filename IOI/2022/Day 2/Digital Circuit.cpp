//Link: https://oj.uz/problem/view/IOI22_circuit
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
const int MAXN = 2e5 + 1;
const ll MOD = 1000002022;
struct nodo
{
  ll uno = 0, cero = 0, lazy = 0;
};

vector<ll> grafo[MAXN], I, D, pref[MAXN], suf[MAXN];
vector<nodo> seg;
ll val[MAXN], n, m, pot = 1, tam[MAXN], aum[MAXN], cant[MAXN];


void act(ll nod)
{
  seg[nod].uno = (seg[nod * 2].uno + seg[nod * 2 + 1].uno)%MOD;
  seg[nod].cero = (seg[nod * 2].cero + seg[nod * 2 + 1].cero)%MOD;
}

void dfsTam(ll nod)
{
  if(nod<n)
    tam[nod] = 1;
  cant[nod]=max(1,sz(grafo[nod]));
  for (auto k : grafo[nod])
  {
    dfsTam(k);
    tam[nod] += tam[k];
    cant[nod]=(cant[nod]*cant[k])%MOD;
  }
  pref[nod].resize(sz(grafo[nod]));
  suf[nod].resize(sz(grafo[nod]));
  ll i;
  for(i=0; i<sz(grafo[nod]); i++)
  {
    pref[nod][i]=cant[grafo[nod][i]];
    if(i>0)
      pref[nod][i]=(pref[nod][i]*pref[nod][i-1])%MOD;
  }
  for(i=sz(grafo[nod])-1; i>=0; i--)
  {
    suf[nod][i]=cant[grafo[nod][i]];
    if(i+1<sz(grafo[nod]))
      suf[nod][i]=(suf[nod][i]*suf[nod][i+1])%MOD;
  }

}

void dfsInit(ll nod, ll x)
{
  if (nod>=n)
  {
    ll i = nod - n;
    if (val[i])
      seg[i + pot].uno = x;
    else
      seg[i + pot].cero = x;
  }
  for (ll i=0; i<sz(grafo[nod]); i++)
  {
    ll tot=1;
    if(i>0)
      tot=pref[nod][i-1];
    if(i+1<sz(grafo[nod]))
      tot=(tot*suf[nod][i+1])%MOD;
    dfsInit(grafo[nod][i], (x * tot)%MOD);
  }
}

void init(int N, int M, std::vector<int> P, std::vector<int> A)
{
  ll i;
  n = N;
  m = M;
  for (i = 1; i < sz(P); i++)
    grafo[P[i]].pb(i);
  for (i = 0; i < sz(A); i++)
    val[i] = A[i];
  while (pot < m)
    pot *= 2;
  seg.resize(pot * 2);
  I.resize(pot * 2);
  D.resize(pot * 2);
  for (i = pot; i < pot * 2; i++)
    I[i] = D[i] = i;
  dfsTam(0);
  dfsInit(0, 1);
  for (i = pot - 1; i > 0; i--)
  {
    I[i] = I[i * 2];
    D[i] = D[i * 2 + 1];
    act(i);
  }
}

void rev(ll nod)
{
  swap(seg[nod].uno, seg[nod].cero);
  seg[nod].lazy = (seg[nod].lazy + 1) % 2;
}
void prop(ll nod)
{
  if (seg[nod].lazy)
  {
    seg[nod].lazy = 0;
    rev(nod*2);
    rev(nod*2+1);
  }
}

void update(ll a, ll b, ll nod)
{
  if (I[nod] > b || D[nod] < a)
    return;
  if (I[nod] >= a && D[nod] <= b)
  {
    rev(nod);
    return;
  }
  prop(nod);
  update(a, b, nod * 2);
  update(a, b, nod * 2 + 1);
  act(nod);
}

int count_ways(int L, int R)
{
  update(L + pot-n, R + pot-n, 1);
  return seg[1].uno%MOD;
}
