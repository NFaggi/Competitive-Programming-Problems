#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
using namespace std;
const int MAXN=2e5+1;
ll memo[MAXN];
vector<ll>seg,I,D,lazy,seg2,res;
ll pot=1, pos;
void pro(int nod)
{
    if(lazy[nod]>0)
    {
        ll tam=seg2[nod];
        ll prop=(lazy[nod]-memo[tam]*res[nod])/tam;
        lazy[nod*2]+=prop*seg2[nod*2]+memo[seg2[nod*2]]*res[nod];
        lazy[nod*2+1]+=prop*seg2[nod*2+1]+(memo[seg2[nod]]-memo[seg2[nod*2]])*res[nod];
        seg[nod]+=lazy[nod];
        res[nod*2]+=res[nod];
        res[nod*2+1]+=res[nod];
        res[nod]=0;
        lazy[nod]=0;
    }
}
void update(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return;
    if(I[nod]>=a&&D[nod]<=b)
    {
        ll tam=seg2[nod];
        lazy[nod]+=memo[pos+tam];
        lazy[nod]-=memo[pos];
        res[nod]++;
        pos+=tam;
        return;
    }
    pro(nod);
    update(a,b,nod*2);
    update(a,b,nod*2+1);

    seg[nod]=seg[nod*2]+lazy[nod*2]+seg[nod*2+1]+lazy[nod*2+1];
}
ll calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod]+lazy[nod];

    pro(nod);
    return calc(a,b,nod*2)+calc(a,b,nod*2+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memo[0]=0;
    ll n, q, i, a, b, op;
    cin >> n >> q;
    for(i=1; i<=n; i++)
        memo[i]=memo[i-1]+i;
    while(pot<n)
        pot*=2;
    seg.resize(pot*2,0);
    seg2.resize(pot*2,0);
    lazy.resize(pot*2,0);
    res.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<sz(I); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=0; i<n; i++)
    {
        cin >> seg[i+pot];
        seg2[i+pot]=1;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=seg[i*2]+seg[i*2+1];
        seg2[i]=seg2[i*2]+seg2[i*2+1];
    }
    while(q--)
    {
        cin >> op >> a >> b;
        a--;
        b--;
        if(op==1)
        {
            pos=0;
            update(a+pot,b+pot,1);
        }
        else
        {
            cout << calc(a+pot,b+pot,1) << '\n';
        }
    }
    return 0;
}
