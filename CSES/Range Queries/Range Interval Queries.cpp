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

struct nodo
{
    ll sum=0;
    nodo *l=nullptr, *r=nullptr;
};

const int MAXN=2e5+1;

ll v[MAXN], ans[MAXN];
bool vis[MAXN];
pair<ll,ll> rang[MAXN];
nodo *st=new nodo();

void update(ll l, ll r, ll x, nodo *&nod)
{
    nod->sum++;
    if(l==r)
        return;
    ll mid=(l+r)/2;
    if(x<=mid)
    {
        if((nod->l)==nullptr)
            nod->l=new nodo();
        update(l,mid,x,nod->l);
    }
    else
    {
        if((nod->r)==nullptr)
            nod->r=new nodo();
        update(mid+1,r,x,nod->r);
    }
}

ll calc(ll a, ll b, ll l, ll r, nodo *nod)
{
    if(nod==nullptr||r<a||l>b)
        return 0;
    if(l>=a&&r<=b)
        return nod->sum;
    ll mid=(l+r)/2;
    return calc(a,b,l,mid,nod->l)+calc(a,b,mid+1,r,nod->r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, a, b, c, d, j;
    cin >> n >> q;
    vector<ll>v(n);
    vector<pair<ll,ll>>sq, eq;
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=0; i<q; i++)
    {
        cin >> a >> b >> c >> d;
        sq.pb({a-1,i});
        eq.pb({b-1,i});
        rang[i]={c,d};
    }
    sort(all(sq));
    sort(all(eq));
    reverse(all(sq));
    reverse(all(eq));

    auto func =[&]()
    {
        while(sz(sq)&&sq.back().fr==i)
        {
            j=sq.back().se;
            if(vis[j])
                ans[j]=calc(rang[j].fr,rang[j].se,1,1e9,st)-ans[j];
            else
            {
                vis[j]=1;
                ans[j]=calc(rang[j].fr,rang[j].se,1,1e9,st);
            }
            sq.pop_back();
        }
    };


    for(i=0; i<n; i++)
    {
        func();
        update(1,1e9,v[i],st);
        swap(sq,eq);
        func();
        swap(sq,eq);

    }
    for(i=0; i<q; i++)
        cout << ans[i] << '\n';
    return 0;
}
