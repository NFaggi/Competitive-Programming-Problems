//Link: https://juez.oia.unsam.edu.ar/tasks/rastreando
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

vector<int> rastrear(vector<int> S);

vector<int> rastreando(int N)
{
    vector<int>pad(N,0);
    vector<int>cons, ret;
    ll emir, i, j;
    for(i=0; i<N; i++)
        cons.pb(i);

    ret=rastrear(cons);

    emir=ret[0];
    pad[ret[0]]=-1;

    for(i=0; i<10; i++)
    {
        vector<int>act,des,ap(N,0);
        for(j=0; j<N; j++)
        {
            if((1<<i)&j)
                act.pb(j);
            else
                des.pb(j);
        }
        ret=rastrear(act);
        for(auto k:ret)
            ap[k]=1;
        for(auto k:act)
        {
            if(k==emir)
                continue;
            if(!ap[k])
                pad[k]|=(1<<i);
        }
        for(auto k:ret)
            ap[k]=0;
        ret=rastrear(des);
        for(auto k:ret)
            ap[k]=1;
        for(auto k:des)
        {
            if(k==emir)
                continue;
            if(ap[k])
                pad[k]|=(1<<i);
        }
    }
    return pad;
}
