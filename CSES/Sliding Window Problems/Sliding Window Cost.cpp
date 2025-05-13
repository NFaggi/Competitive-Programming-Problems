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

const int MAXN=2e5+1;

ll v[MAXN], pot=1, med;
vector<ll>st,I,D;
map<ll,ll>m;

void update(ll nod, ll x)
{
    st[nod]+=x;
    nod/=2;
    while(nod>0)
    {
        st[nod]=st[nod*2]+st[nod*2+1];
        nod/=2;
    }
}

ll calc(ll nod, ll aum)
{
    if(nod>=pot)
    return nod-pot;
    if(st[nod*2]+aum>=med)
        return calc(nod*2,aum);
    return calc(nod*2+1,aum+st[nod*2]);
}

ll calc2(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return st[nod];
    return calc2(a,b,nod*2)+calc2(a,b,nod*2+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, i, ant=0, ans, ret=0, iz, der, l, r;
    cin >> n >> k;
    med=(k+1)/2;
    vector<ll>ord, comp;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        ord.pb(v[i]);
    }
    sort(all(ord));
    for(i=0; i<n; i++)
    {
        if(ant==ord[i])
            continue;
        comp.pb(ord[i]);
        ant=ord[i];
    }

    for(i=0; i<sz(comp); i++)
        m[comp[i]]=i;
    while(pot<sz(comp))
        pot*=2;
    st.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    for(i=0; i<k; i++)
        update(m[v[i]]+pot,1);
    ans=comp[calc(1,0)];
    for(i=0; i<k; i++)
        ret+=abs(v[i]-ans);
    cout << ret << ' ';
    ant=ans;
    for(i=k; i<n; i++)
    {
        update(m[v[i-k]]+pot,-1);
        update(m[v[i]]+pot,1);
        ret-=abs(v[i-k]-ans);
        ans=comp[calc(1,0)];
        if(ans==ant)
            ret+=abs(v[i]-ans);
        else if(ans>ant)
        {
            ret+=abs(v[i]-ant);
            l=pot;
            r=pot+m[ans]-1;
            if(l>r)
                iz=0;
            else
                iz=calc2(l,r,1);
            ret+=abs(ant-ans)*iz;
            l=pot+m[ans];
            r=pot*2-1;
            der=calc2(l,r,1);
            ret-=abs(ant-ans)*der;
        }
        else
        {
            ret+=abs(v[i]-ant);
            l=pot+m[ans]+1;
            r=pot*2-1;
            if(l>r)
                der=0;
            else
                der=calc2(l,r,1);
            ret+=abs(ant-ans)*der;
            l=pot;
            r=m[ans]+pot;
            iz=calc2(l,r,1);
            ret-=abs(ant-ans)*iz;
        }
        ant=ans;
        cout << ret << ' ';
    }
    return 0;
}
