#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200001;
const int LOG = 18;
 
vector<pair<int, int>> G[MAXN];
int bin[MAXN][LOG], prof[MAXN];
int maxEdge[MAXN][LOG];
int vis[MAXN];
 
void dfs(int nod, int pad, int weight) {
    vis[nod]=1;
    bin[nod][0] = pad;
    maxEdge[nod][0] = weight;
    for (int i = 1; i < LOG; i++) {
        if (bin[nod][i-1] != -1) {
            bin[nod][i] = bin[bin[nod][i-1]][i-1];
            maxEdge[nod][i] = max(maxEdge[nod][i-1], maxEdge[bin[nod][i-1]][i-1]);
        } else {
            bin[nod][i] = -1;
            maxEdge[nod][i] = -1;
        }
    }
    for (auto &k : G[nod]) {
        if (k.first != pad) {
            prof[k.first] = prof[nod] + 1;
            dfs(k.first, nod, k.second);
        }
    }
}
 
int lca(int a, int b) {
    if (prof[a] < prof[b])
        swap(a, b);
    int dis = prof[a] - prof[b];
    for (int i = LOG - 1; i >= 0; i--) {
        if (dis & (1 << i))
            a = bin[a][i];
    }
    if (a == b)
        return a;
 
    for (int i = LOG - 1; i >= 0; i--) {
        if (bin[a][i] != bin[b][i]) {
            a = bin[a][i];
            b = bin[b][i];
        }
    }
    return bin[a][0];
}
 
int maxCost(int a, int lca) {
    int max_cost = 0;
    int dis = prof[a] - prof[lca];
    for (int i = LOG - 1; i >= 0; i--) {
        if (dis & (1 << i)) {
            max_cost = max(max_cost, maxEdge[a][i]);
            a = bin[a][i];
        }
    }
    return max_cost;
}
vector <vector <int> > comp;
vector <int> id;
 
bool unionfind(int a, int b)
{
    if(id[a] == id[b])
        return false;
    int x = id[a], y = id[b];
    if(comp[x].size() < comp[y].size())
    {
        swap(a, b);
        swap(x, y);
    }
    for(int i:comp[y])
    {
        comp[x].push_back(i);
        id[i] = x;
    }
    return true;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q, m, a, b;
    cin >> n >> m >> q;
    id.resize(n+1);
    for(int i=0; i<=n; i++)
    {
        comp.push_back({i});
        id[i] = i;
    }
    vector <vector<int> > v(m, vector <int> (3));
 
    for(int i=0; i<m; i++){
        cin >> v[i][1] >> v[i][2];
        v[i][0]=i+1;
      }
 
    sort(v.begin(), v.end());
    long long res = 0;
    int aristas = 0;
    for(int i=0; i<m; i++)
    {
        if(unionfind(v[i][1], v[i][2]))
        {
            aristas++;
            res += v[i][0];
            G[v[i][2]].push_back({v[i][1], v[i][0]});
            G[v[i][1]].push_back({v[i][2], v[i][0]});
        }
    }
 
    memset(bin, -1, sizeof(bin));
    memset(maxEdge, -1, sizeof(maxEdge));
    prof[1] = 0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
            dfs(i, -1, 0);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        if(id[a]!=id[b])
        {
            cout << -1 << '\n';
            continue;
        }
        int lca_ab = lca(a, b);
        int max_cost = max(maxCost(a, lca_ab), maxCost(b, lca_ab));
        cout << max_cost << '\n';
    }
 
    return 0;
}
