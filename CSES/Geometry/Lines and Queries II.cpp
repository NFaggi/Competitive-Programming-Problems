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
 
ll calc(pair<ll,ll>f, ll x)
{
    return f.fr*x+f.se;
}
 
struct nod
{
    nod *l=nullptr, *r=nullptr;
    ll a=0, b=1e5;
    pair<ll,ll>f={0,LLONG_MIN};
    void addLine(pair<ll,ll>g)
    {
        if(calc(g,(a+b)/2)>calc(f,(a+b)/2))
            swap(g,f);
        if(calc(g,a)>calc(f,a))
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
        if(calc(g,b)>calc(f,b))
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

    void addSeg(pair<ll,ll>g, ll x1, ll x2)
    {
        if(x1<=a&&b<=x2)
        {
            addLine(g);
            return;
        }
        if(x1<=(a+b)/2)
        {
            if(l==nullptr)
            {
                l=new nod();
                l->a=a;
                l->b=(a+b)/2;
            }
            l->addSeg(g,x1,x2);
        }
        if(x2>(a+b)/2)
        {
            if(r==nullptr)
            {
                r=new nod();
                r->a=(a+b)/2+1;
                r->b=b;
            }
            r->addSeg(g,x1,x2);
        }
    }
};
 
ll query(nod *act, ll x)
{
    if(act==nullptr)
        return LLONG_MIN;
    if((act->a+act->b)/2==x&&act->a==act->b)
        return calc(act->f,x);
    if((act->a+act->b)/2>=x)
        return max(query(act->l,x),calc(act->f,x));
    return max(query(act->r,x),calc(act->f,x));
}
 
nod *raiz=new nod();
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, t, a, b, ret, x1, x2;
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t==1)
        {
            cin >> a >> b >> x1 >> x2;
            raiz->addSeg({a,b},x1,x2);
        }
        else
        {
            cin >> a;
            ret=query(raiz,a);
            if(ret==LLONG_MIN)
                cout << "NO\n";
            else
                cout << ret << '\n';
        }
    }
    return 0;
}
