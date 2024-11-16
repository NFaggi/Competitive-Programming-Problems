#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
vector<int> grafo[MAXN];
int comps[MAXN];
int vis[MAXN], low[MAXN], apilados[MAXN], act = 0, comp = 1;
stack<int> p;

void DFS(int nod) {
    vis[nod] = low[nod] = ++act;
    p.push(nod);
    apilados[nod] = 1;

    for (auto k : grafo[nod]) {
        if (!vis[k]) {
            DFS(k);
            low[nod] = min(low[nod], low[k]);
        } else if (apilados[k]) {
            low[nod] = min(low[nod], vis[k]);
        }
    }

    if (low[nod] == vis[nod]) {
        while (true) {
            int top = p.top();
            p.pop();
            apilados[top] = 0;
            comps[top]=comp;
            if (top == nod) break;
        }
        comp++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b, i;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        grafo[a].push_back(b);
    }

    for (i = 1; i <= n; i++) {
        if (!vis[i]) {
            DFS(i);
        }
    }

    cout << comp-1 << '\n';
    for(i=1; i<=n; i++)
    {
        cout << comps[i] << ' ';
    }

    return 0;
}
