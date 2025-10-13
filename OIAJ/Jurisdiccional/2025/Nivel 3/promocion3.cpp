//Link: https://juez.oia.unsam.edu.ar/task/183
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define fr first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

using namespace std;

vector<vector<vector<int>>>pr;
const int MAXN=1e5+1;
ll n, m, tim=0, cli[MAXN];
void inicializar(vector<int> &P, int C, int Q) {
    n=sz(P);
    m=C;
    ll i;
    pr.resize(n);
    for(i=0; i<n; i++)
        pr[i].pb({0,P[i],0});
    for(i=0; i<C; i++)
        cli[i]=-1;
}

int comprar(int c, int p) {
    if(cli[c]==-1)
        cli[c]=tim;
    ll l=0, r=sz(pr[p])-1, piv, pos=sz(pr[p]);
    while(l<=r)
    {
        piv=(l+r)/2;
        if(pr[p][piv][2]>cli[c])
        {
            r=piv-1;
            pos=piv;
        }
        else
            l=piv+1;
    }
    if(pos==0)
        return int(pr[p][pos][1]);
    else
        return int(pr[p][pos-1][1]);
}

void cambiar(int p, int v) {
    ll mi=tim+1;
    while(sz(pr[p])&&int(pr[p].back()[1])>=v)
    {
        mi=pr[p].back()[2];
        pr[p].pop_back();
    }
    tim++;
    vector<int>vec={int(tim),v,int(mi)};
    pr[p].pb(vec);
}
