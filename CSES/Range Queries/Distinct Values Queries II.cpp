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
 
vector<ll>st,I,D;
 
void update(ll nod, ll x)
{
    st[nod]=x;
    nod/=2;
    while(nod>0)
    {
        st[nod]=min(st[nod*2],st[nod*2+1]);
        nod/=2;
    }
}
 
ll calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return LLONG_MAX;
    if(I[nod]>=a&&D[nod]<=b)
        return st[nod];
    return min(calc(a,b,nod*2),calc(a,b,nod*2+1));
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, pot=1, i, q, a, b, c, k;
    cin >> n >> q;
    vector<ll>v(n);
    map<ll,set<ll>>m;
    forn(i,n)
        cin >> v[i];
    while(pot<n)
        pot*=2;
    st.resize(pot*2,LLONG_MAX);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    for(i=n-1; i>=0; i--)
    {
        if(sz(m[v[i]])!=0)
            update(i+pot,*m[v[i]].begin());
        m[v[i]].insert(i);
    }
    while(q--)
    {
        cin >> a >> b >> c;
        b--;
        if(a==1)
        {
            auto it=m[v[b]].find(b);
            auto it2=it;
            auto it3=it;
            if(it2!=m[v[b]].begin())
            {
                it2=prev(it2);
                it3++;
                if(it3!=m[v[b]].end())
                    update(*it2+pot,*it3);
                else
                    update(*it2+pot,LLONG_MAX);
            }
            m[v[b]].erase(it);
            v[b]=c;
            m[v[b]].insert(b);
            it=m[v[b]].find(b);
            it2=it;
            if(it!=m[v[b]].begin())
            {
                it=prev(it);
                update(*it+pot,b);
            }
            it2++;
            if(it2!=m[v[b]].end())
                update(b+pot,*it2);
            else
                update(b+pot,LLONG_MAX);
        }
        else
        {
            c--;
            k=calc(b+pot,c+pot,1);
            if(k>c)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
