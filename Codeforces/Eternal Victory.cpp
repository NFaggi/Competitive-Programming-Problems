//Link: https://codeforces.com/contest/61/problem/D
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,long long>>>grafo;
long long res;
void DFS(int nod, int pad, long long cost)
{
    bool proc=1;
    for(auto k:grafo[nod])
    {
        if(k.first!=pad)
        {
            proc=0;
            DFS(k.first,nod,cost+k.second);
        }
    }
    if(proc)
        res=max(res,cost);
}
int main()
{
    int n, m, a, b, i;
    long long c, sum=0;
    cin >> n;
    grafo.resize(n+1);
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b >> c;
        grafo[a].push_back({b,c});
        grafo[b].push_back({a,c});
        sum+=c;
    }
    sum*=2;
    DFS(1,0,0ll);
    sum-=res;
    cout << sum;
    return 0;
}
