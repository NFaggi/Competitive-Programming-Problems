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

ll MIN=-1e15, MAX=1e15;

struct nodo
{
    ll lazy = 0, mi = MAX, ma = MIN;
};

vector<nodo> seg;
vector<ll> I, D;
ll pot = 1;

void upd(ll nod, ll x)
{
    seg[nod].lazy += x;
    seg[nod].mi+=x;
    seg[nod].ma+=x;
}

void prop(ll nod)
{
    ll x = seg[nod].lazy;
    if (nod < pot)
    {
        upd(nod*2,x);
        upd(nod*2+1,x);
    }
    seg[nod].lazy=0;
}

void up(ll nod)
{
    seg[nod].mi=min(seg[nod*2+1].mi,seg[nod*2].mi);
    seg[nod].ma=max(seg[nod*2+1].ma,seg[nod*2].ma);
}

void update(ll a, ll b, ll nod, ll x)
{
    if(I[nod]>b||D[nod]<a)
        return;
    if(I[nod]>=a&&D[nod]<=b)
    {
        upd(nod,x);
        return;
    }

    prop(nod);
    update(a,b,nod*2,x);
    update(a,b,nod*2+1,x);
    up(nod);
}
nodo calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return {0,MAX,MIN};
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    prop(nod);
    nodo A=calc(a,b,nod*2), B=calc(a,b,nod*2+1), res;
    res.lazy=A.lazy+B.lazy;
    res.ma=max(A.ma,B.ma);
    res.mi=min(A.mi,B.mi);
    up(nod);
    return res;
}

vector<int> distribute_candies(vector<int> C, vector<int> L, vector<int> R, vector<int> V)
{
    ll n = sz(C), q = sz(V), i;
    while (pot < q+1)
        pot *= 2;
    seg.resize(pot * 2);
    I.resize(pot * 2);
    D.resize(pot * 2);

    for (i = pot; i < pot * 2; i++)
    {
        I[i] = D[i] = i;
        seg[i].mi=seg[i].ma=0;
    }
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
        seg[i].mi=seg[i].ma=0;
    }

    vector<pair<ll, pair<ll, pair<ll,ll>>>> qs;
    for (i = 0; i < q; i++)
        qs.pb({L[i], {R[i], {V[i],i+1}}});
    sort(all(qs));
    reverse(all(qs));

    priority_queue<pair<ll,pair<ll,ll>>>fins;
    vector<int> ans(n);

    for (i = 0; i < n; i++)
    {
        while(fins.size()&&-fins.top().fr<i)
        {
            update(fins.top().se.se+pot,pot*2-1,1,-fins.top().se.fr);
            fins.pop();
        }
        while(qs.size()&&qs.back().fr<=i)
        {
            fins.push({-qs.back().se.fr,{qs.back().se.se.fr,qs.back().se.se.se}});
            update(qs.back().se.se.se+pot,pot*2-1,1,qs.back().se.se.fr);
            qs.pop_back();
        }
        ll l=0, r=q, piv, pos=0;
        nodo a=seg[1];
        if(a.ma-a.mi<C[i])
        {
            ll ami=a.mi;
            a=calc(pot+q,pot+q,1);
            ans[i]=a.lazy-ami;
            continue;
        }
        while(l<=r)
        {
            piv=(l+r)/2;
            a=calc(pot+piv,pot*2-1,1);
            if(a.ma-a.mi>=C[i])
            {
                l=piv+1;
                pos=piv;
            }
            else
                r=piv-1;
        }

        a=calc(pot+pos,pot*2-1,1);
        nodo b=calc(pot+q,pot+q,1), c=calc(pot+pos,pot+pos,1);
        if(c.lazy==a.mi)
            ans[i]=C[i]-(a.ma-b.lazy);
        else
            ans[i]=b.lazy-a.mi;

    }

    return ans;
}
