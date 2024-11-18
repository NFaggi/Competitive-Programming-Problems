//Link: https://codeforces.com/contest/61/problem/E
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
using namespace std;
vector<ll>seg,seg2,I,D;
void update(ll nod)
{
    seg[nod]=1;
    nod/=2;
    while(nod>0)
    {
        seg[nod]=seg[nod*2]+seg[nod*2+1];
        nod/=2;
    }
}
ll calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0ll;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    return calc(a,b,nod*2)+calc(a,b,nod*2+1);
}
void update2(ll nod, ll x)
{
    seg2[nod]=x;
    nod/=2;
    while(nod>0)
    {
        seg2[nod]=seg2[nod*2]+seg2[nod*2+1];
        nod/=2;
    }
}
ll calc2(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0ll;
    if(I[nod]>=a&&D[nod]<=b)
        return seg2[nod];
    return calc2(a,b,nod*2)+calc2(a,b,nod*2+1);
}
int main()
{
    ll n, i, pot=1;
    cin >> n;
    while(pot<n)
        pot*=2;
    seg.resize(pot*2,0);
    seg2.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    vector<pair<ll,ll>>v(n),ord(n);
    for(i=pot; i<sz(I);i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    forn(i,n)
    {
        cin >> v[i].first;
        ord[i].first=-v[i].first;
        ord[i].second=i;
    }
    sort(all(ord));
    forn(i,n)
    {
        v[ord[i].second].second=i;
    }
    ll cant=0;
    for(i=n-1; i>=0; i--)
    {
        ord[v[i].second].first=calc(v[i].second+pot,sz(I),1);
        update(v[i].second+pot);
        cant+=calc2(v[i].second+pot,sz(I),1);
        update2(v[i].second+pot,ord[v[i].second].first);
    }
    cout << cant;
    return 0;
}
