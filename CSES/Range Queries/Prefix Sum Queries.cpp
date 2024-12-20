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
vector<ll>seg,lazy,I,D;
ll pot=1;
void prop(ll nod)
{
    lazy[nod*2]+=lazy[nod];
    lazy[nod*2+1]+=lazy[nod];
    seg[nod]=max(seg[nod*2]+lazy[nod*2],seg[nod*2+1]+lazy[nod*2+1]);
    lazy[nod]=0;
}
void update(ll a, ll b, ll nod, ll x)
{
    if(I[nod]>b||D[nod]<a)
        return;
    if(I[nod]>=a&&D[nod]<=b)
    {
        lazy[nod]+=x;
        return;
    }
    prop(nod);
    update(a,b,nod*2,x);
    update(a,b,nod*2+1,x);
    seg[nod]=max(seg[nod*2]+lazy[nod*2],seg[nod*2+1]+lazy[nod*2+1]);
}
ll sum(ll a, ll nod)
{
    if(I[nod]>a||D[nod]<a)
        return -LLONG_MAX;
    if(I[nod]>=a&&D[nod]<=a)
        return seg[nod]+lazy[nod];
    prop(nod);
    return max(sum(a,nod*2),sum(a,nod*2+1));
}
ll calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return -LLONG_MAX;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod]+lazy[nod];
    prop(nod);
    return max(calc(a,b,nod*2),calc(a,b,nod*2+1));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, ma, op, a, b, act;
    cin >> n >> q;
    vector<ll>v(n);
    while(n>pot)
        pot*=2;
    seg.resize(pot*2,0);
    lazy.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        seg[i+pot]=v[i];
        if(i>0)
            seg[i+pot]+=seg[(i+pot)-1];
    }
    for(i=pot; i<sz(I); i++)
        D[i]=I[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=max(seg[i*2],seg[i*2+1]);
    }
    while(q--)
    {
        cin >> op >> a >> b;
        ma=0;
        if(op==1)
        {
            a--;
            act=b-v[a];
            v[a]=b;
            update(a+pot,sz(I)-1,1,act);
        }
        else
        {
            a--;
            b--;
            ma=calc(a+pot,b+pot,1);
            if(a>0)
            {
                ma-=sum((a-1)+pot,1);
            }
            ma=max(ma,0ll);
            cout << ma << '\n';
        }
    }
    return 0;
}
