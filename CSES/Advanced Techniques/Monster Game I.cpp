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
struct mons
{
    ll a, b, i;
};
 
const int MAXN=2e5+1;
 
mons dp[MAXN];
ll cost[MAXN];
 
vector<mons>q;
 
bool del(mons &l1, mons &l2, mons &l3)
{
    return (l3.b-l1.b)*(l1.a-l2.a) < (l2.b-l1.b)*(l1.a-l3.a);
}
 
void inser(mons a)
{
    if(sz(q)&&q.back().a==a.a)
        return;
    while(sz(q)>1&&del(q[sz(q)-2],q.back(),a))
        q.pop_back();
    q.pb(a);
}
 
ll inRange(ll x, ll i)
{
    if(i>0&&(q[i].b-q[i-1].b)>(q[i-1].a-q[i].a)*x)
        return -1;
    
    if(i+1<sz(q)&&(q[i+1].b-q[i].b)<(q[i].a-q[i+1].a)*x)
        return 1;
    return 0;
}
 
ll query(ll x)
{
    ll l=0, r=sz(q)-1, piv, ret;
    while(l<=r)
    {
        piv=(l+r)/2;
        ret=inRange(x,piv);
        if(!ret)
            return piv;
        if(ret==-1)
            r=piv-1;
        else
            l=piv+1;
    }
    return 0;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, i, ret;
    cin >> n >> x;
 
    mons a={x,0,0};
    dp[0]=a;
    inser(a);
    for(i=0; i<n; i++)
    cin >> cost[i];
 
    for(i=0; i<n; i++)
    {
        cin >> dp[i+1].a;
        a.a=dp[i+1].a;
        ret=q[query(cost[i])].i;
        a.b=dp[ret].a*cost[i]+dp[ret].b;
        a.i=i+1;
        inser(a);
        dp[i+1]=a;
    }
    cout << dp[n].b;
    return 0;
}
