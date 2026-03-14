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

ll calc(pair<ll,ll>f, ll x)
{
    return f.fr*x+f.se;
}

struct nod
{
    pair<ll,ll>f;
    nod *l=nullptr, *r=nullptr;
    ll a=1, b=1e6;
    void addLine(pair<ll,ll>g)
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
    if((act->a+act->b)/2==x)
        return calc(act->f,x);
    if((act->a+act->b)/2>x)
        return min(query(act->l,x),calc(act->f,x));
    return min(query(act->r,x),calc(act->f,x));
}

nod *raiz=new nod();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, n, inF, a, b;
    cin >> n >> inF;
    vector<ll>f(n),s(n), dp(n);
    for(i=0; i<n; i++)
        cin >> s[i];
    for(i=0; i<n; i++)
        cin >> f[i];
    raiz->f={inF,0};
    for(i=0; i<n; i++)
    {
        dp[i]=query(raiz,s[i]);
        a=f[i];
        b=dp[i];
        raiz->addLine({a,b});
    }
    cout << dp[n-1];
    return 0;
}
