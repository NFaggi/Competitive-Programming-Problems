#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int>>grafo;
vector<int>col,res;
vector<unordered_set<int>>s;
void DFS(int nodo, int padre)
{
    s[nodo].insert(col[nodo]);
    for(auto i:grafo[nodo])
    {
        if(i!=padre)
        {
            DFS(i,nodo);
            if(int(s[nodo].size())<int(s[i].size()))
            {
                swap(s[nodo],s[i]);
            }
            for(auto j:s[i])
            {
                s[nodo].insert(j);
            }
        }
    }
    res[nodo]=int(s[nodo].size());
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, i,a,b;
    cin >> n;
    res.resize(n+1);
    grafo.resize(n+1);
    s.resize(n+1);
    col.resize(n+1);
    for(i=1; i<=n; i++)
    {
        cin >> col[i];
    }
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    DFS(1,-1);
    for(i=1; i<int(res.size()); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
