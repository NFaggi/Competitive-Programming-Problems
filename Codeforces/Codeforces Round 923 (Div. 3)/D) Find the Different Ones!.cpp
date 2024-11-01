//Link: https://codeforces.com/contest/1927/problem/D
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,ll>> segMi, segMa;
vector<ll> I, D;
pair<ll,ll> calcMi(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return {LLONG_MAX,0};
    if(I[nod]>=a&&D[nod]<=b)
        return segMi[nod];
    pair<ll,ll>p1=calcMi(a,b,nod*2),p2=calcMi(a,b,nod*2+1);
    if(p1.first<p2.first)
        return p1;
    return p2;
}
pair<ll,ll> calcMa(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return {0ll,0ll};
    if(I[nod]>=a&&D[nod]<=b)
        return segMa[nod];
    pair<ll,ll>p1=calcMa(a,b,nod*2),p2=calcMa(a,b,nod*2+1);
    if(p1.first>p2.first)
        return p1;
    return p2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t, n, i, l, r, q, pot;
    cin >> t;
    while(t--)
    {
        pot=1;
        cin >> n;
        vector<ll>v(n);
        while(pot<n)
            pot*=2ll;
        segMa.resize(0);
        segMa.resize(pot*2,{0ll,0ll});
        segMi.resize(0);
        segMi.resize(pot*2,{LLONG_MAX,0ll});
        I.resize(0);
        I.resize(pot*2);
        D.resize(0);
        D.resize(pot*2);
        for(i=0; i<n; i++)
        {
            cin >> v[i];
        }
        for(i=pot; i<int(I.size()); i++)
        {
            I[i]=i;
            D[i]=i;
        }
        for(i=0; i<n; i++)
        {
            segMa[i+pot]={v[i],i};
            segMi[i+pot]={v[i],i};
        }
        for(i=pot-1; i>0; i--)
        {
            I[i]=I[i*2];
            D[i]=D[i*2+1];
            pair<ll,int>p1=segMa[i*2],p2=segMa[i*2+1];
            if(p1.first>p2.first)
                segMa[i]=p1;
            else
                segMa[i]=p2;
            p1=segMi[i*2];
            p2=segMi[i*2+1];
            if(p1.first<p2.first)
                segMi[i]=p1;
            else
                segMi[i]=p2;
        }
        cin >> q;
        while(q--)
        {
            cin >> l >> r;
            l--;
            r--;
            pair<ll,int>a,b;
            a=calcMa(l+pot,r+pot,1);
            b=calcMi(l+pot,r+pot,1);
            if(a.first!=b.first)
                cout << a.second+1ll << ' ' << b.second+1ll << '\n';
            else
                cout << -1ll << ' ' << -1ll << '\n';
        }
        cout << '\n';

    }
    return 0;
}
