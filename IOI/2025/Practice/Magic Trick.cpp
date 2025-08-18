//Link: https://qoj.ac/problem/13651
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define fr first
#define se second
#define sz(x) int(x.size())
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
std::vector<int> Alicia(std::vector<int> P)
{
    vector<pair<ll, ll>> lis(sz(P), {1, -1}), lds(sz(P), {1, -1});
    ll i, j, maLis=-1, maLds=-1, inLis=0, inLds=0;
    for (i = 0; i < sz(P); i++)
    {
        for (j = i+1; j < sz(P); j++)
        {
            if(P[i]<P[j]&&lis[j].fr<lis[i].fr+1)
            {
                lis[j]={lis[i].fr+1,i};
            }
            if(P[i]>P[j]&&lds[j].fr<lds[i].fr+1)
            {
                lds[j]={lds[i].fr+1,i};
            }
        }
    }
    for(i=0; i<sz(P); i++)
    {
        if(maLis<lis[i].fr)
        {
            maLis=lis[i].fr;
            inLis=i;
        }
        if(maLds<lds[i].fr)
        {
            maLds=lds[i].fr;
            inLds=i;
        }
    }
    if(maLis%2==1)
        maLis--;
    if(maLds%2==0)
        maLds--;
    if(maLis>=16)
    {
        ll nod=inLis;
        vector<ll>v;
        while(nod>=0)
        {
            v.pb(nod);
            nod=lis[nod].se;
        }
        if(sz(v)%2==1)
            v.pop_back();
        for(i=0; i<sz(v); i++)
        {
            P[v[i]]=-1;
        }
    }
    else
    {
        ll nod=inLds;
        vector<ll>v;
        while(nod>=0)
        {
            v.pb(nod);
            nod=lds[nod].se;
        }
        if(sz(v)%2==0)
            v.pop_back();
        for(i=0; i<sz(v); i++)
        {
            P[v[i]]=-1;
        }
    }
    return P;
}

std::vector<int> Beatriz(std::vector<int> Q)
{
    ll cant=0, i;
    for(i=0; i<sz(Q); i++)
        if(Q[i]==-1)
            cant++;
    if(cant%2==0)
    {
        map<ll,ll>m;
        for(i=0; i<sz(Q); i++)
        {
            m[Q[i]]=1;
        }
        vector<ll>v;
        for(i=1; i<=sz(Q); i++)
        {
            if(m[i]==0)
            {
                v.pb(i);
            }
        }
        sort(all(v));
        ll pos=0;
        for(i=0; i<sz(Q); i++)
        {
            if(Q[i]==-1)
                Q[i]=v[pos++];
        }
    }
    else
    {
        map<ll,ll>m;
        for(i=0; i<sz(Q); i++)
        {
            m[Q[i]]=1;
        }
        vector<ll>v;
        for(i=1; i<=sz(Q); i++)
        {
            if(m[i]==0)
            {
                v.pb(-i);
            }
        }
        sort(all(v));
        ll pos=0;
        for(i=0; i<sz(Q); i++)
        {
            if(Q[i]==-1)
                Q[i]=-v[pos++];
        }
    }
    return Q;
}
