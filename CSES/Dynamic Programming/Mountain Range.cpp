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
 
vector<ll>seg,I,D;
 
ll calc(ll l, ll r, ll nod)
{
    if(I[nod]>r||D[nod]<l)
        return 0;
    if(I[nod]>=l&&D[nod]<=r)
        return seg[nod];
    return max(calc(l,r,nod*2),calc(l,r,nod*2+1));
}

void update(ll nod, ll x)
{
    seg[nod]=x;
    nod/=2;
    while(nod>0)
    {
        seg[nod]=max(seg[nod*2],seg[nod*2+1]);
        nod/=2;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, pot=1, ans=1, act;
    cin >> n;
    while(pot<n)
        pot*=2;
    seg.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    priority_queue<pair<ll,ll>>pq;
    vector<ll>v(n),L(n),R(n);
    vector<pair<ll,ll>>q;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        pq.push({-v[i],i});
    }
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    for(i=0; i<n; i++)
    {
        while(q.size()&&q.back().fr<v[i])
            q.pop_back();
        if(sz(q))
            L[i]=q.back().se+1;
        else
            L[i]=0;
        q.pb({v[i],i});
    }
    q.resize(0);
    for(i=n-1; i>=0; i--)
    {
        while(q.size()&&q.back().fr<v[i])
            q.pop_back();
        if(sz(q))
            R[i]=q.back().se-1;
        else
            R[i]=n-1;
        q.pb({v[i],i});
    }

    while(pq.size())
    {
        i=pq.top().se;
        pq.pop();
        act=calc(L[i]+pot,R[i]+pot,1)+1;
        ans=max(ans,act);
        update(i+pot,act);
    }
    cout << ans;
    return 0;
}
