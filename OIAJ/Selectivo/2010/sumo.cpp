//Link: https://juez.oia.unsam.edu.ar/task/123
//Score: 100/100
#include <bits/stdc++.h>
using namespace std;
vector<int>segt,I,D;
void update(int pos)
{
    while(pos>0)
    {
        segt[pos]++;
        pos/=2;
    }
}
long long sum(int a, int b, int nodo)
{
    if(a>D[nodo]||b<I[nodo])
        return 0;
    if(a<=I[nodo]&&b>=D[nodo])
        return segt[nodo];
    return sum(a,b,nodo*2)+sum(a,b,nodo*2+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin ("sumo.in");
    ofstream cout ("sumo.out");
    int n, i, pot=1, ma=0;
    cin >> n;
    vector<pair<int, pair<int,int>>>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i].second.first >> v[i].first ;
        v[i].second.second=i;
        ma=max(ma,v[i].second.first);
    }
    ma++;
    while(pot<ma)
    {
        pot*=2;
    }
    sort(v.begin(),v.end());
    segt.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>=0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    vector<int> res(n);
    for(i=0; i<n; i++)
    {
        res[v[i].second.second]=sum(pot,v[i].second.first+pot, 1);
        update(v[i].second.first+pot);
    }
    for(auto k:res)
    {
        cout << k << '\n';
    }
    return 0;
}
