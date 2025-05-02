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

vector<ll>seg,I,D, segI, segD, segM;

void update(ll nod, ll x)
{
    seg[nod]=x;
    segM[nod]=max(0ll,x);
    segD[nod]=max(x,0ll);
    segI[nod]=max(0ll,x);
    nod/=2;
    while(nod>0)
    {
        seg[nod]=seg[nod*2]+seg[nod*2+1];
        segI[nod]=segI[nod*2];
        segD[nod]=segD[nod*2+1];
        segM[nod]=max(segD[nod*2]+segI[nod*2+1],max(segM[nod*2],segM[nod*2+1]));
        segI[nod]=max(segI[nod],segI[nod*2+1]+seg[nod*2]);
        segD[nod]=max(segD[nod],segD[nod*2]+seg[nod*2+1]);
        segM[nod]=max(segM[nod],max(segD[nod],segI[nod]));
        segM[nod]=max(segM[nod],seg[nod]);
        nod/=2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, pot=1, q, a, b, ans;
    cin >> n >> q;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    while(pot<n)
        pot*=2;
    seg.resize(pot*2,0);
    segI.resize(pot*2,0);
    segD.resize(pot*2,0);
    segM.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot+n; i++)
        update(i,v[i-pot]);
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    while(q--)
    {
        cin >> a >> b;
        a--;
        update(a+pot,b);
        cout << segM[1] << '\n';
    }
    return 0;
}
