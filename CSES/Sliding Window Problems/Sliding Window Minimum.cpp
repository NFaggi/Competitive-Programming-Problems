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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, a, b, c, sum=0, xr=0, i, mi;
    cin >> n >> k;
    vector<ll>v(n);
    cin >> x >> a >> b >> c;
    v[0]=x;
    for(i=1; i<n; i++)
        v[i]=(a*v[i-1]+b)%c;
    deque<pair<ll,ll>>dq;
    for(i=0; i<k; i++)
    {
        while(dq.size()&&dq.back().se>v[i])
            dq.pop_back();
        dq.push_back({i,v[i]});
    }
    mi=dq.front().se;
    xr=xr^mi;
    for(i=k; i<n; i++)
    {
        if(dq.front().fr<=i-k)
            dq.pop_front();
        while(dq.size()&&dq.back().se>v[i])
            dq.pop_back();
        dq.push_back({i,v[i]});
        mi=dq.front().se;
        xr=xr^mi;
    }
    cout << xr;
    return 0;
}
