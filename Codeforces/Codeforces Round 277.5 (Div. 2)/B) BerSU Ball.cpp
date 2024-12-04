//Link: https://codeforces.com/problemset/problem/489/B
#include<bits/stdc++.h>
using namespace std;
const int MAXN=101;
vector<int>grafo[MAXN];
int vis[MAXN],match[MAXN],par,v1[MAXN],v2[MAXN];
bool dfs(int nod)
{
    if(nod==0)
    {
        par++;
        return 1;
    }    
    if(vis[nod])
        return 0;
    vis[nod]=1;
    for(auto k:grafo[nod])
    {
        if(dfs(match[k]))
        {
            match[k]=nod;
            return 1;
        }
    }    
    return 0;
}
int main()
{
    int n, m,i,j;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> v1[i];
    }
    cin >> m;
    for(i=1; i<=m; i++)
    {
        cin >> v2[i];
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(abs(v1[i]-v2[j])<=1)
            {
                grafo[i].push_back(j);
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        memset(vis,0,sizeof(vis));
        dfs(i);
    }
    cout << par;
    return 0;
}
