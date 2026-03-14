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

ll INF=LLONG_MAX;

ll calc(pair<ll,ll> f, ll x)
{
    return f.fr*x+f.se;
}

struct nod
{
    nod *l=nullptr, *r=nullptr;
    ll a=1, b=1e6;
    pair<ll,ll>f;

    void addLine(pair<ll,ll> g)
    {
        if(calc(g,(a+b)/2)<calc(f,(a+b)/2))
            swap(f,g);
        if(calc(g,a)<calc(f,a))
        {
            if(l!=nullptr)
                l->addLine(g);
            else
            {
                l=new nod();
                l->a=a;
                l->b=(a+b)/2;
                l->f=g;
            }
        }
        if(calc(g,b)<calc(f,b))
        {
            if(r!=nullptr)
            r->addLine(g);
            else
            {
                r=new nod();
                r->a=(a+b)/2+1;
                r->b=b;
                r->f=g;
            }
        }
    }

};

ll query(nod *act, ll x)
{
    if(act==nullptr)
        return INF;
    ll mid=(act->a+act->b)/2;
    if(mid==x)
        return calc(act->f,x);
    if(mid>x)
        return min(query(act->l,x),calc(act->f,x));
    if(mid<x)
        return min(query(act->r,x),calc(act->f,x));
}
nod *raiz=new nod();
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, c, a, b;
    cin >> n >> c;
    vector<ll>h(n),dp(n);
    for(i=0; i<n; i++)
        cin >> h[i];
    raiz->f={-2ll*h[0],h[0]*h[0]};

    for(i=1; i<n; i++)
    {
        dp[i]=c+h[i]*h[i]+query(raiz,h[i]);
        a=-2*h[i];
        b=dp[i]+h[i]*h[i];
        raiz->addLine({a,b});
    }
    cout << dp[n-1];
    return 0;
}
