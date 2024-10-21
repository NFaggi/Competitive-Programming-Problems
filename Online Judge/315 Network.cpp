//Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<int> vis, low, PA; 
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

int main() {
    int n;
    while (cin >> n, n != 0) {
        grafo.assign(n + 1, vector<int>());
        vis.assign(n + 1, 0);
        low.assign(n + 1, 0);
        PA.assign(n + 1, 0);
        act = 0;

        cin.ignore();
        string s;
        while (getline(cin, s) && s != "0") {
            istringstream iss(s);
            int ori, num;
            iss >> ori;

            while (iss >> num) {
                grafo[ori].push_back(num);
                grafo[num].push_back(ori);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 0) {
                DFS(i, 0); 
            }
        }

        int cant = count(PA.begin(), PA.end(), 1);
        cout << cant << '\n';
    }
    return 0;
}