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


struct st
{
    ll mi=0, cant=0, c0=0, lazy=0, alt;
    st *l=nullptr, *r=nullptr;
};

st *seg=new st();
ll pot=1;

void add(st *&nod, ll x)
{
    if(nod==nullptr)
        return;
    nod->mi+=x;
    nod->lazy+=x;
    if(nod->mi==0)
    {
        nod->c0+=nod->cant;
        nod->cant=0;
    }
    if(nod->c0!=0&&x>0)
    {
        nod->cant=nod->c0;
        nod->c0=0;
        nod->mi=x;
    }
}

void prop(st *&nod)
{
    if(nod->l==nullptr)
    {
        nod->l=new st();
        (nod->l)->c0=(nod->l)->alt=nod->alt/2;
    }
    if(nod->r==nullptr)
    {
        nod->r=new st();
        (nod->r)->c0=(nod->r)->alt=nod->alt/2;
    }
    add(nod->l,nod->lazy);
    add(nod->r,nod->lazy);
    nod->lazy=0;
}

void up(st *&nod)
{
    nod->c0=0;
    nod->cant=0;
    nod->mi=0;
    if(nod->l!=nullptr)
    {
        nod->c0=(nod->l)->c0;
        nod->mi=(nod->l)->mi;
        nod->cant=(nod->l)->cant;
    }
    if(nod->r!=nullptr)
    {
        nod->c0+=(nod->r)->c0;
        if((nod->mi)==0||(nod->mi)>((nod->r)->mi))
        {
            nod->mi=(nod->r)->mi;
            nod->cant=(nod->r)->cant;
        }
        else if((nod->mi)==((nod->r)->mi))
            nod->cant+=(nod->r)->cant;
    }
}

void update(st *&nod, ll a, ll b, ll x, ll l=0, ll r=pot-1)
{
    if(b<l||r<a)
        return;
    if(a<=l&&r<=b)
    {
        add(nod,x);
        return;
    }
    prop(nod);
    ll mid=(l+r)/2;
    update(nod->l,a,b,x,l,mid);
    update(nod->r,a,b,x,mid+1,r);
    up(nod);
}

ll calc(st *&nod, ll a, ll b, ll l=0, ll r=pot-1)
{   
    if(nod==nullptr||r<a||b<l)
        return 0;
    if(a<=l&&r<=b)
        return nod->c0;
    prop(nod);
    ll mid=(l+r)/2;
    return calc(nod->l,a,b,l,mid)+calc(nod->r,a,b,mid+1,r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, x, y, x2, y2, aum=1e6, ant=0, ans=0,j=0, k=0;
    while(pot<aum*2)
        pot*=2;
    seg->alt=seg->c0=pot;
    cin >> n;
    vector<pair<ll,pair<ll,ll>>>ins,res;
    for(i=0; i<n; i++)
    {
        cin >> x >> y >> x2 >> y2;
        x+=aum;
        y+=aum;
        x2+=aum;
        y2+=aum;
        if(y>y2)
            swap(y,y2);
        if(x>x2)
            swap(x,x2);
        ins.pb({y,{x,x2}});
        res.pb({y2,{x,x2}});
    }
    sort(all(ins));
    sort(all(res));
    for(i=0; i<=aum*2; i++)
    {
        bool band=0;

        while(j<sz(ins)&&ins[j].fr<=i)
        {
            update(seg,ins[j].se.fr,ins[j].se.se-1,1);
            band=1;
            j++;
        }

        while(k<sz(res)&&res[k].fr<=i)
        {
            update(seg,res[k].se.fr,res[k].se.se-1,-1);
            band=1;
            k++;
        }

        if(band)
            ant=pot-calc(seg,0,pot-1);
        ans+=ant;
    }
    cout << ans;
    return 0;
}
