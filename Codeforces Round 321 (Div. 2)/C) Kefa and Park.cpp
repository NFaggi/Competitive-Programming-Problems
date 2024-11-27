//Link: https://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e5+1;
bool v[MAXN];
int cant=0;
vector<int> grafo[MAXN];
int m;
void DFS(int nod, int pas, int pad)
{
    if(pas>m)
        return;
    bool us=0;
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        if(v[k]==1)
            DFS(k,pas+v[k],nod);
        else
            DFS(k,0,nod);
        us=1;
    }
    if(us==0)
        cant++;
}
int main()
{
    int n, i, a, b;
    cin >> n >> m;
    for(i=1; i<=n; i++)
    {
        cin >> v[i];
    }
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    DFS(1,v[1],-1);
    cout << cant;
    return 0;
}
