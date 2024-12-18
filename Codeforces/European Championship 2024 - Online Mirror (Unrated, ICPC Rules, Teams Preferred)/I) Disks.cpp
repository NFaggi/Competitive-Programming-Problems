//Link: https://codeforces.com/problemset/problem/1949/I
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e3+1;
vector<int>grafo[MAXN];
int vis[MAXN];
bool sonTan(int x1, int y1, int r1, int x2, int y2, int r2) {
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    long double dist = sqrt(dx * dx + dy * dy);

    return dist == r1 + r2;
}
int aum,dis;
bool dfs(int nod, int action)
{
    vis[nod]=action;
    int sigAct;
    if(action==1)
    {
        dis++;
        sigAct=2;
    }
    else
    {
        aum++;
        sigAct=1;
    }
    for(auto k:grafo[nod])
    {
        if(!vis[k])
        {
            if(!dfs(k,sigAct))
                return 0;
        }
        else if(vis[k]!=sigAct)
            return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i,j;
    cin >> n;
    vector<pair<ll,ll>>v(n+1);
    vector<ll>radios(n+1);
    for(i=1; i<=n; i++)
        cin >> v[i].first >> v[i].second >> radios[i];
    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(sonTan(v[i].first,v[i].second,radios[i],v[j].first,v[j].second,radios[j]))
            {
                grafo[i].push_back(j);
                grafo[j].push_back(i);
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        aum=0;
        dis=0;
        memset(vis,0,sizeof(vis));
        if(dfs(i,1)&&dis>aum)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

