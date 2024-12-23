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
vector<ll>seg,I,D;
void update(ll nod, ll x)
{
    seg[nod]+=x;
    nod=nod/2;
    while(nod>0)
    {
        seg[nod]=seg[nod*2]+seg[nod*2+1];
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
    ll n,q, i, j=0,pot=1;
    cin >> n >> q;
    vector<ll>v(n);
    vector<pair<ll,pair<ll,ll>>>qs(q);
    vector<ll>ans(q);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    for(i=0; i<q; i++)
    {
        cin >> qs[i].se.fr >> qs[i].fr;
        qs[i].fr--;
        qs[i].se.fr--;
        qs[i].se.se=i;

    }
    while(pot<n)
        pot*=2;
    I.resize(pot*2);
    D.resize(pot*2);
    seg.resize(pot*2,0);
    for(i=pot; i<pot*2; i++)
    {
        D[i]=i;
        I[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    sort(all(qs));
    set<ll>s;
    map<ll,ll>m;
    for(i=0; i<q; i++)
    {
        while(j<n&&j<=qs[i].fr)
        {
            auto it=s.find(v[j]);
            if(it==s.end())
            {
                s.insert(v[j]);
                m[v[j]]=j;
                update(j+pot,1);
            }
            else
            {
                ll ant=m[v[j]];
                m[v[j]]=j;
                update(ant+pot,-1);
                update(j+pot,1);
            }
            j++;
        }
        ans[qs[i].se.se]=calc(qs[i].se.fr+pot,qs[i].fr+pot,1);
    }
    for(i=0; i<q; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
