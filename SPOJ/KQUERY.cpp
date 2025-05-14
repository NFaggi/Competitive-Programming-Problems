//Link: https://www.spoj.com/problems/KQUERY/
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

vector<vector<ll>>seg;
vector<ll>I,D;

ll calc(ll l, ll r, ll k, ll nod)
{
    if(I[nod]>r||D[nod]<l)
        return 0;
    if(I[nod]>=l&&D[nod]<=r)
    {
        auto it=lower_bound(all(seg[nod]),k+1);
        if(it==seg[nod].end())
            return 0;
        ll in=it-seg[nod].begin();
        return ((D[nod]-I[nod])+1)-in;
    }
    return calc(l,r,k,nod*2)+calc(l,r,k,nod*2+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, ans=0, q, l, r, k, pot=1;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    while(pot<n)
        pot*=2;
    seg.resize(pot*2);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=0; i<n; i++)
    seg[i+pot]={v[i]};
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=seg[i*2];
        for(auto k:seg[i*2+1])
            seg[i].pb(k);
        sort(all(seg[i]));
    }
    cin >> q;
    while(q--)
    {
        cin >> l >> r >> k;
        l--;
        r--;
        l+=pot;
        r+=pot;
        cout << calc(l,r,k,1) << '\n';
    }
    return 0;
}
