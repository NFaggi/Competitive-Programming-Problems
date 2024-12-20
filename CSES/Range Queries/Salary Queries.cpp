#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
struct query
{
    char c;
    ll a, b;
};
vector<ll>seg,I,D;
void update(ll nod, ll x)
{
    while(nod>0)
    {
        seg[nod]+=x;
        nod=nod/2;
    }
}
ll calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    return calc(a,b,nod*2)+calc(a,b,nod*2+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, q, a, b, pot=1;
    char c;
    cin >> n >> q;
    vector<ll>v(n);
    set<ll>s;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    vector<query>qs(q);
    unordered_map<ll,ll>m,m2,m3;
    for(i=0; i<q; i++)
    {
        cin >> c >> a >> b;
        query nod;
        nod.a=a;
        nod.b=b;
        nod.c=c;
        qs[i]=nod;
        if(c=='!')
            s.insert(b);
    }
    ll pos=0;
    for(auto k:s)
    {
        m[k]=pos;
        pos++;
    }
    for(i=0; i<q; i++)
    {
        query nod;
        nod=qs[i];
        a=nod.a;
        b=nod.b;
        c=nod.c;
        if(c=='?')
        {
            auto it=s.lower_bound(a);
            if(it==s.end())
            {
                m2[a]=-1;
                continue;
            }
            else
            {
                m2[a]=m[*it];
            }
            it=s.upper_bound(b);
            if(it==s.begin())
            {
                m3[b]=-1;
            }
            else
            {
                it=prev(it);
                m3[b]=m[*it];
            }
        }
    }
    while(pot<pos)
        pot*=2;
    seg.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=0; i<n; i++)
        seg[m[v[i]]+pot]++;
 
    for(i=pot; i<sz(I); i++)
        D[i]=I[i]=i;
 
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=seg[i*2]+seg[i*2+1];
    }
    for(i=0; i<q; i++)
    {
        a=qs[i].a;
        b=qs[i].b;
        c=qs[i].c;
        if(c=='!')
        {
            a--;
            update(m[v[a]]+pot,-1);
            v[a]=b;
            update(m[v[a]]+pot,1);
        }
        else
        {
            a=m2[a];
            b=m3[b];
            if(a==-1||b==-1)
            {
                cout << 0 <<'\n';
            }
            else
            {
                cout << calc(a+pot,b+pot,1) << '\n';
            }
        }
    }
    return 0;
}
