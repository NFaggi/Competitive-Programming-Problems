#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN = 2e5+1;

vector<ll> arbol[MAXN];
ll tam[MAXN], m;

ll preCalcDFS(ll nod, ll pad)
{
    tam[nod]=1;
    for(auto k:arbol[nod])
    {
        if(k==pad)
            continue;
        tam[nod]+=preCalcDFS(k,nod);
    }
    return tam[nod];
}

ll DFS(ll nod, ll pad)
{
    for(auto k:arbol[nod])
    {
        if(k==pad)
            continue;
        if(tam[k]>m)
            return DFS(k, nod);
    }
    return nod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, a, b;
    cin >> n;
    m=n/2;
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        arbol[a].pb(b);
        arbol[b].pb(a);
    }
    preCalcDFS(1,0);
    cout << DFS(1, 0) << '\n';
    return 0;
}
