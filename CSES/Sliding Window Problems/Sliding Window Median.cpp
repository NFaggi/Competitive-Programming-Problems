#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>I,D,Seg;
ll pot=1;
void Update(ll pos, ll val)
{
    Seg[pos]=val;
    pos/=2;
    while(pos>0)
    {
        Seg[pos]=Seg[pos*2]+Seg[pos*2+1];
        pos/=2;
    }
}
ll med;
map<ll,ll>m;
ll calc(ll pos, ll nod)
{
    if(nod>=pot)
    {
        return m[nod-pot];
    }
    ll iz=pos+Seg[nod*2];
    if(iz<med)
    {
        return calc(iz,nod*2+1);
    }
    return calc(pos,nod*2);
 
}
int main()
{
    ll n, i, k;
    cin >> n >> k;
    med=(k+1)/2;
    vector<pair<ll,ll>>v(n),vORD(n);
 
    while(pot<n)
        pot*=2;
    I.resize(pot*2);
    D.resize(pot*2);
    Seg.resize(pot*2,0);
    for(i=0; i<n; i++)
    {
        cin >> v[i].first;
        vORD[i].second=i;
        vORD[i].first=v[i].first;
    }
    sort(vORD.begin(),vORD.end());
    for(i=0; i<n; i++)
    {
        v[vORD[i].second].second=i;
        m[i]=vORD[i].second;
    }
    for(i=0; i<k; i++)
    {
        Update(v[i].second+pot,1);
    }
    cout << v[calc(0,1)].first << ' ';
    for(i=k; i<n; i++)
    {
        Update(v[i].second+pot,1);
        Update(v[i-k].second+pot,0);
        cout << v[calc(0,1)].first << ' ';
    }
    return 0;
}
