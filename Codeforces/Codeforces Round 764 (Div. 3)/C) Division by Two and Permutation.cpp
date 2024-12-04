//Link: https://codeforces.com/problemset/problem/1624/C
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>grafo;
int match[51],vis[51];
bool matching(int nod)
{
    if(!nod)
        return 1;
    if(vis[nod])
        return 0;
    vis[nod]=1;
    for(auto k:grafo[nod])
    {
        if(matching(match[k]))
        {
            match[k]=nod;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int t, n, i,cant;
    long long x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cant=0;
        grafo.resize(0);
        grafo.resize(n+1);
        memset(vis,0,sizeof(vis));
        memset(match,0,sizeof(match));
        for(i=1; i<=n; i++)
        {
            cin >> x;
            while(x>0)
            {
                if(x<=n)
                {
                    grafo[i].push_back(x);
                }
                x=x/2;
            }
        }
        for(i=1; i<=n; i++)
        {
            matching(i);
            memset(vis,0,sizeof(vis));
        }
        for(i=1; i<=n; i++)
        {
            if(match[i]!=0)
                cant++;
        }
        if(cant==n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
