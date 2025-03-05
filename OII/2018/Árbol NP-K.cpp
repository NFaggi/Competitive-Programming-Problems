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

const int MAXN=5e5+1;

vector<ll>grafo[MAXN];
ll v[MAXN], ans, p, K, aum[MAXN];

unordered_map<ll,ll> DFS(ll nod, ll pad)
{
    unordered_map<ll,ll>a,b;
    ll x;
    if(v[nod]<p&&K==2)
        ans++;
    else if(v[nod]>p&&K==1)
        ans++;
    if(v[nod]<p)
        a[1]++;
    else
        a[0]++;
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        b=DFS(k,nod);
        if(sz(a)<sz(b))
        {
            swap(a,b);
            swap(aum[nod],aum[k]);
            for(auto c:b)
            {
                if(c.fr+aum[k]>=K)
                continue;
                ans+=a[((K-1)-(c.fr+aum[k]))-aum[nod]]*c.se;
            }
            if(v[nod]<p)
                aum[nod]++;
            for(auto c:b)
            {
                if(c.fr+aum[k]>=K)
                    continue;
                a[(c.fr+aum[k])-aum[nod]]+=c.se;
            }
        }
        else
        {
            for(auto c:b)
            {
                if(c.fr+aum[k]>=K)
                    continue;
                ans+=a[((K-1)-(c.fr+aum[k]))-aum[nod]]*c.se;
            }
            if(v[nod]<p)
                aum[k]++;
            for(auto c:b)
            {
                if(c.fr+aum[k]>=K)
                    continue;
                a[(c.fr+aum[k])-aum[nod]]+=c.se;
            }
        }
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, tot=0, a, b;
    cin >> n >> p >> K;
    for(i=0; i<n; i++)
        cin >> v[i+1];
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    DFS(1,0);
    cout << ans;
    return 0;
}
