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
 
double calc(pair<double,double>f, ll x)
{
    return f.fr*x+f.se;
}
 
struct nod
{
    nod *l=nullptr, *r=nullptr;
    ll a=0, b;
    pair<double, double>f={0,-1};
 
    void addLine(pair<double, double>g)
    {
        if(calc(g,(a+b)/2)>calc(f,(a+b)/2))
            swap(f,g);
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

    void addSeg(pair<double, double>g, ll x1, ll x2)
    {
        if(x1<=a&&b<=x2)
        {
            addLine(g);
            return;
        }
        if(a == b) return;
        if((a+b)/2>=x1)
        {
            if(l==nullptr)
            {
                l=new nod();
                l->a=a;
                l->b=(a+b)/2;
            }
            l->addSeg(g,x1,x2);
        }
        if((a+b)/2<x2)
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
        return -1;
    if((act->a+act->b)/2>=x)
    {
        ll a=query(act->l,x), b=calc(act->f,x);
        return max(a,b);
    }
    ll a=query(act->r,x), b=calc(act->f,x);
    return max(a,b);
}
 
nod *raiz= new nod();
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, m, y, y2, x, x2;
    double a, b;
    cin >> n >> m;
    raiz->b=m;
    raiz->f={0,-1};
    for(i=0; i<n; i++)
    {
        cin >> x >> y >> x2 >> y2;
        a=double(y2-y)/double(x2-x);
        b=double(y)-double(a*x);
        raiz->addSeg({a,b},x,x2);
    }
    for(i=0; i<=m; i++)
        cout << query(raiz,i) << ' ';
    return 0;
}
