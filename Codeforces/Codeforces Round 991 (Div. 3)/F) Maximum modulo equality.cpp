//Link: https://codeforces.com/problemset/problem/2050/F
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
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
vector<ll>seg,I,D;
ll calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    return gcd(calc(a,b,nod*2),calc(a,b,nod*2+1));
}

void solve()
{
    ll n, i, q, l, r,pot=1;

    cin >> n >> q;
    vector<ll> v(n), difs;

    for(i=0; i<n; i++)
    {
        cin >> v[i];
        if(i>0)
            difs.push_back(abs(v[i]-v[i-1]));
    }

    while(pot<sz(difs))
        pot*=2;
    seg.resize(0);
    I.resize(0);
    D.resize(0);
    seg.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);

    for(i=pot; i<pot*2; i++)
        D[i]=I[i]=i;

    for(i=0; i<sz(difs); i++)
        seg[i+pot]=difs[i];

    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=gcd(seg[i*2],seg[i*2+1]);
    }

    while(q--)
    {
        cin >> l >> r;
        if(l==r)
        {
            cout << 0 << ' ';
            continue;
        }
        l--;
        r-=2ll;
        cout << calc(l+pot,r+pot,1) << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}
