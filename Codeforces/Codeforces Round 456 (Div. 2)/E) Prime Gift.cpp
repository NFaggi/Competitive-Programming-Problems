//Link: https://codeforces.com/contest/912/problem/E
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

ll INF=1e18;
vector<ll>A,B;
void construir(vector<ll>&a, vector<ll>&v, ll i, ll j, ll act)
{
    if(act<=INF/a[i])
    {
        v.pb(act*a[i]);
        construir(a,v,i,j,act*a[i]);
    }
    if(i<j)
        construir(a,v,i+1,j,act);
}

ll countDown(ll x)
{
    ll cant=0, i, j, mi, ma, piv, pos;
    for(i=0; i<sz(A); i++)
    {
        mi=0;
        ma=sz(B)-1;
        pos=-1;
        if(A[i]>x)
            break;
        while(mi<=ma)
        {
            piv=(mi+ma)/2;
            if(B[piv]<=x/A[i])
            {
                pos=max(piv,pos);
                mi=piv+1;
            }
            else
                ma=piv-1;
        }
        if(pos==-1)
            break;
        pos++;
        cant+=pos;
    }
    return cant;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, k, mi=1, ma=1e18, piv, pos=1e18;
    cin >> n;
    vector<ll>p(n), a, b;
    for(i=0; i<n; i++)
        cin >> p[i];
    cin >> k;
    if(n==1)
    {
        ll ans=1;
        for(i=0; i<k-1; i++)
            ans*=p[0];
        cout << ans;
        return 0;
    }
    sort(all(p));
    for(i=0; i<n; i++)
    {
        if(i%2==0)
            a.pb(p[i]);
        else
            b.pb(p[i]);
    }
    sort(all(a));
    sort(all(b));
    A.pb(1);
    B.pb(1);
    construir(a,A,0,sz(a)-1, 1);
    construir(b,B,0,sz(b)-1,1);
    sort(all(A));
    sort(all(B));
    if(sz(A)>sz(B))
        swap(A,B);
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(countDown(piv)>=k)
        {
            ma=piv-1;
            pos=min(piv,pos);
        }
        else
            mi=piv+1;
    }
    cout << pos;
    return 0;
}
