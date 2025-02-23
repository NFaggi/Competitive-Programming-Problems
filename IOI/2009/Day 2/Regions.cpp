//Link: https://ioi.contest.codeforces.com/group/32KGsXgiKA/contest/103755/problem/G
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=200001;
const int MAXR=25001;

vector<ll>grafo[MAXN],regiones[MAXR],times[MAXR];
ll reg[MAXN], tim=0, in[MAXN], fin[MAXN], vis[MAXN];
vector<pair<ll,ll>>lims[MAXR], limsINV[MAXR];
void dfs(ll nod)
{
    tim++;
    in[nod]=tim;
    times[reg[nod]].push_back(tim);
    for(auto k:grafo[nod])
        dfs(k);
    fin[nod]=tim;
    lims[reg[nod]].push_back({in[nod],fin[nod]});
    limsINV[reg[nod]].push_back({fin[nod],in[nod]});
}

int main()
{
    ll n, r, q, i, j, h, k, r1, r2, res, cant, l;
    cin >> n >> r >> q;
    cin >> h;
    reg[1]=h;
    regiones[h].push_back(1);
    for(i=2; i<=n; i++)
    {
        cin >> k >> h;
        reg[i]=h;
        grafo[k].push_back(i);
        regiones[h].push_back(i);
    }
    dfs(1);
    for(i=0; i<=r; i++)
    {
        sort(times[i].begin(),times[i].end());
        sort(lims[i].begin(),lims[i].end());
        sort(limsINV[i].begin(),limsINV[i].end());
    }
    for(k=1; k<=q; k++)
    {
        cin >> r1 >> r2;
        i=0;
        l=0;
        j=0;
        cant=0;
        res=0;
        while(j<int(regiones[r2].size()))
        {
            while(i<int(regiones[r1].size())&&lims[r1][i].first<=times[r2][j])
            {
                i++;
                cant++;
            }
            while(l<int(regiones[r1].size())&&limsINV[r1][l].first<times[r2][j])
            {
                l++;
                cant--;
            }
            res+=cant;
            j++;
        }
        cout << res << '\n';
    }
    return 0;
}
