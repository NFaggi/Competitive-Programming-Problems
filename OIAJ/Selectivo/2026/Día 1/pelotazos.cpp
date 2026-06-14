//Link: https://juez.oia.unsam.edu.ar/tasks/pelotazos
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

string patear(int x);

map<ll,ll>memo;

ll pat(ll x)
{
    if(memo[x])
        return memo[x];
    string ret=patear(x);

    if(ret=="BARRERA")
        memo[x]=1;
    else if(ret=="GOL")
        memo[x]=2;
    else
        memo[x]=3;
    return memo[x];
}
const int MAXN=1e9;
map<ll,ll>cost;

ll calc(ll l, ll r, ll p=0)
{
    ll pot=1, mi=LLONG_MAX, pos=1, act, pot2;
    while(pot<(r-l+1))
    {
        act=cost[pot];
        pot2=1;
        while(pot2<(r-l+1)-pot)
            pot2=pot2*2;
        act=max(act,cost[pot2]);
        if(mi>act)
        {
            mi=act;
            pos=pot;
        }
        if(p&&mi==act)
        {
            pos=pot;
        }
        pot=pot*2;
    }
    return l+pos-1;
}

vector<int> pelotazos(int x)
{
    if(x==1)
        return {x,x};
    ll l=1, r=x-1, piv, pos=x, lb=0, rb=x, ret, posb, pot=1, ant=1;

    cost[pot]=1;
    while(pot<=MAXN)
    {
        pot=pot*2;
        ant++;
        cost[pot]=ant;
    }
    while(l<=r)
    {
        piv=calc(l,r,1);
        ret=pat(piv);
        if(ret>1)
        {
             pos=piv;
            if(ret<=2)
                lb=max(lb,piv);
            if(ret==3)
                rb=piv-1;
            r=piv-1;
        }
        else
            l=piv+1;
    }
    if(lb==rb)
        return {int(lb),int(lb)};
    posb=lb;
    lb++;
    while(lb<=rb)
    {
        piv=calc(lb,rb,1);
        if(pat(piv)<=2)
        {
            posb=piv;
            lb=piv+1;
        }
        else
            rb=piv-1;
    }
    return {int(pos),int(posb)};
}
