#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
vector<int> grafo[MAXN];
int vis[MAXN], low[MAXN], PA[MAXN], vi[MAXN], sig[MAXN];
int act;
 
void DFS(int nod, int pad) {
    int hijos = 0;
    vis[nod] = low[nod] = ++act;
 
    for (int k : grafo[nod]) {
        if (vis[k] == 0) {
            hijos++;
            DFS(k, nod);
            low[nod] = min(low[nod], low[k]);
 
            if ((pad == 0 && hijos > 1) || (pad != 0 && low[k] >= vis[nod])) {
                PA[nod] = 1;
            }
        } else if (k != pad) {
            low[nod] = min(low[nod], vis[k]);
        }
    }
}
set<pair<int,int>>s;
void DFSA(int nod, int pad)
{
    int a,b;
    for(int i=sig[nod]; i<int(grafo[nod].size()); i++)
    {
        sig[nod]++;
        a=nod;
        b=grafo[nod][i];
        if(a>b)
            swap(a,b);
        auto it=s.find({a,b});
        if(it==s.end())
        {
            s.insert({a,b});
            cout << nod << ' ' << grafo[nod][i] << '\n';
            if(vi[grafo[nod][i]]==0&&grafo[nod][i]!=pad)
            {
                DFSA(grafo[nod][i],nod);
            }
        }
    }
    vi[nod]=1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b, div=0;
    cin >> n >> m;
    act = 0;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            if(div==1)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
            div=1;
            DFS(i, 0);
        }
    }
 
    for(int i=1; i<=n; i++)
    {
        if(PA[i])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    DFSA(1,0);
    return 0;
}
