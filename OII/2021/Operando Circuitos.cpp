//Score: 100/100
#include <bits/stdc++.h>
using namespace std;

vector<set<int>>v;
vector<vector<int>> grafo;
vector<bool>vis;
string s;
void DFS(int nodo)//1 izq 2 der
{
    int hij, hij2;
    if(vis[nodo])
        return;
    vis[nodo]=1;
    if(s[nodo]=='L')
    {
        hij=grafo[nodo][0];
        DFS(grafo[nodo][0]);
        for(auto k:v[hij])
        {
            cout << k << ' ';
        }
        cout << endl;
    }
    else if(s[nodo]=='O')
    {
        hij=grafo[nodo][0];
        DFS(grafo[nodo][0]);
        hij2=grafo[nodo][1];
        DFS(grafo[nodo][1]);
        if(v[hij].size()<v[hij2].size())
            swap(hij,hij2);
        swap(v[nodo],v[hij]);
        for(auto k:v[hij2])
        {
            v[nodo].insert(k);
        }
    }
    else if(s[nodo]=='A')
    {
        hij=grafo[nodo][0];
        DFS(grafo[nodo][0]);
        hij2=grafo[nodo][1];
        DFS(grafo[nodo][1]);
        if(v[hij].size()<v[hij2].size())
            swap(hij,hij2);
        for(auto k:v[hij])
        {
            auto it = v[hij2].find(k);
            if(it!=v[hij2].end())
                v[nodo].insert(k);
        }
        v[hij2].clear();
        v[hij].clear();
    }
    else if(s[nodo]=='X')
    {
        hij=grafo[nodo][0];
        DFS(grafo[nodo][0]);
        hij2=grafo[nodo][1];
        DFS(grafo[nodo][1]);
        if(v[hij].size()<v[hij2].size())
            swap(hij,hij2);
        swap(v[nodo],v[hij]);
        for(auto k:v[hij2])
        {
            auto it = v[nodo].find(k);
            if(it==v[nodo].end())
                v[nodo].insert(k);
            else
                v[nodo].erase(k);
        }
    }
}
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,i,m,j,a,b, c;
    cin >> n >> s;
    v.resize(n);
    grafo.resize(n);
    vis.resize(n,0);
    for(i=0; i<n; i++)
    {
        cin >> m;
        if(s[i]=='E')
        {
            for(j=0; j<m; j++)
            {
                cin >> c;
                v[i].insert(c);
            }
        }
        else if(s[i]=='O')
        {
            cin >> a >> b;
            grafo[i].push_back(a);
            grafo[i].push_back(b);
        }
        else if(s[i]=='A')
        {
            cin >> a >> b;
            grafo[i].push_back(a);
            grafo[i].push_back(b);
        }
        else if(s[i]=='X')
        {
            cin >> a >> b;
            grafo[i].push_back(a);
            grafo[i].push_back(b);
        }
        else if(s[i]=='L')
        {
            cin >> a;
            grafo[i].push_back(a);
        }
    }
    for(i=0; i<n; i++)
    {
        if(s[i]=='L')
        {
            DFS(i);
        }
        else
        {
            cout << endl;
        }
    }
    return 0;
}
