//Link: https://codeforces.com/problemset/problem/1730/B
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

const int MAXN=1e5+1;

ll x[MAXN], t[MAXN], n;

ll cal(ll piv)
{
    ll i, ma=0;
    for(i=0; i<n; i++)
    {
        ma=max(ma,t[i]+abs(piv-x[i]));
    }
    return ma;
}

void solve()
{
    ll pos, mi=0, ma=1e14+1, piv, iz, der, i;
    long double div=1e6;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x[i];
        x[i]=x[i]*1000000ll;
    }
    for(i=0; i<n; i++)
    {
        cin >> t[i];
        t[i]=t[i]*1000000ll;
    }
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        iz=cal(piv-1);
        der=cal(piv+1);
        if(iz<der)
        {
            ma=piv-1;
        }
        else
        {
            mi=piv+1;
            pos=piv;
        }
    }
    long double ans=pos;
    ans=ans/div;
    printf("%.6Lf\n",ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
