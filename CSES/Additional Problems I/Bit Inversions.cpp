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

const int MAXN=2e5+1;

struct nodo
{
    ll l[2], r[2], sum[2], cant, ma;
    void iniciar()
    {
        l[0]=r[0]=sum[0]=l[1]=r[1]=sum[1]=cant=0;
        ma=1;
    }
};

nodo seg[MAXN*2];

nodo act(nodo &a, nodo &b)
{
    nodo x=a;
    ll ma=x.ma, i;
    for(i=0; i<2; i++)
    {
        x.sum[i]+=b.sum[i];
        ma=max(ma,x.r[i]+b.l[i]);
        if(x.cant==x.l[i])
            x.l[i]=x.l[i]+b.l[i];
        if(b.cant==b.r[i])
            x.r[i]=x.r[i]+b.r[i];
        else
            x.r[i]=b.r[i];
        ma=max(ma,max(x.l[i],x.r[i]));
    }
    x.ma=max(b.ma,ma);
    x.cant+=b.cant;
    return x;
}

void update(ll nod)
{
    swap(seg[nod].l[0],seg[nod].l[1]);
    swap(seg[nod].r[0],seg[nod].r[1]);
    swap(seg[nod].sum[0],seg[nod].sum[1]);
    nod/=2;
    while(nod>0)
    {
        seg[nod]=act(seg[nod*2],seg[nod*2+1]);
        nod/=2;
    }
}


ll calc(ll l, ll r)
{
    nodo L, R;
    L.iniciar();
    R.iniciar();
    while(l<=r)
    {
        if(l==r)
        {
            L=act(L,seg[l]);
            break;
        }
        if(l%2!=0)
            L=act(L,seg[l++]);
        if(r%2==0)
            R=act(R,seg[r--]);
        r/=2;
        l/=2;
    }
    return act(L,R).ma;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m, i, x, n, bit;
    string s;
    cin >> s >> m;
    n=sz(s);
    for(i=0; i<MAXN*2; i++)
        seg[i].iniciar();
    for(i=0; i<n; i++)
    {
        bit=!(s[i]=='1');
        seg[n+i].sum[bit]=seg[n+i].l[bit]=seg[n+i].r[bit]=seg[n+i].cant=1;
        update(n+i);
    }

    for(i=0; i<m; i++)
    {
        cin >> x;
        update(n+x-1);
        cout << calc(n,n*2-1)<< ' ';
    }

    return 0;
}
