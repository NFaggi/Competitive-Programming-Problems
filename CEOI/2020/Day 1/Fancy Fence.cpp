//Score: 100/100
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
const int MOD=1e9+7;
const int MAXN=1e5+1;
ll INF=LLONG_MAX;
ll inv2=500000004, ans=0;
ll pot=1, pref[MAXN], n, segH[MAXN*2];
vector<ll>h,w;
map<ll,set<ll>>H;

ll gauss(ll x)
{
    return (((x*(x+1)%MOD)%MOD)*inv2)%MOD;
}

ll calcH(ll l, ll r)
{
    ll L=INF, R=INF;
    for(;l<=r;)
    {
        if(l==r)
        {
            L=min(L,segH[l]);
            break;
        }
        if(l%2)
            L=min(L,segH[l++]);
        if(r%2==0)
            R=min(R,segH[r--]);
        l/=2;
        r/=2;
    }
    return min(L,R);
}

void solve(ll l, ll r, ll aH)
{
    ll miH=calcH(l+n,r+n), a, b, c, c2, tam=pref[r];
    if(l>0)
        tam=(tam-pref[l-1]+MOD)%MOD;
    a=gauss(tam);
    b=gauss(miH);
    c=(a*b)%MOD;
    if(aH)
    {
        b=gauss(aH);
        c2=(a*b)%MOD;
        c=(c-c2+MOD)%MOD;
    }
    ans=(ans+c)%MOD;
    auto &s=H[miH];
    ll pos;
    for(ll i=l; i<=r; i++)
    {
        if(h[i]==miH)
            continue;
        auto it=s.lower_bound(i);
        if(it==s.end()||(*it>r))
            pos=r+1;
        else
            pos=*it;
        solve(i,pos-1,miH);
        i=pos;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i;
    cin >> n;
    h.resize(n);
    w.resize(n);
    for(i=0; i<n; i++)
    {
        cin >> h[i];
        segH[i+n]=h[i];
        H[h[i]].insert(i);
    }
    for(i=0; i<n; i++)
    {
        cin >> w[i];
        pref[i]=w[i];
        if(i>0)
            pref[i]=(w[i]+pref[i-1])%MOD;
    }
    for(i=n-1; i>0; i--)
        segH[i]=min(segH[i*2],segH[i*2+1]);
    solve(0,n-1,0);
    cout << ans;
    return 0;
}
