//Score: 100/100
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

const int MAXN=1e3+1;
unordered_set<ll> grafo[MAXN];
bitset<MAXN> inf[MAXN];
bitset<MAXN> act;
ll vis[MAXN], tim=1;
void DFS1(ll nod)
{
    vis[nod]=tim;
    inf[nod]|=act;
    for(auto k:grafo[nod])
    {
        if(vis[k]==tim)
            continue;
        DFS1(k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, a, b, j, cant;
    cin >> n >> m;
    for(i=1; i<=n; i++)
        inf[i][i]=1;
    while(m--)
    {
        cin >> a >> b;
        auto it=grafo[a].find(b);
        if(it==grafo[a].end())
        {
            grafo[a].insert(b);
            grafo[b].insert(a);
            act=0;
            tim++;
            act=inf[a]|inf[b];
            DFS1(a);
        }
        else
        {
            grafo[a].erase(it);
            it=grafo[b].find(a);
            grafo[b].erase(it);
        }
    }
    for(i=1; i<=n; i++)
    {
        cant=0;
        for(j=0; j<=n; j++)
        {
            if(inf[i][j]==1)
                cant++;
        }
        cout << cant << '\n';
    }
    return 0;
}
