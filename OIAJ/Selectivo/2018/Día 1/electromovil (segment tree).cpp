//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/49
#include <bits/stdc++.h>
#define ll int
using namespace std;
ll INF=INT_MAX;
vector<pair<ll,ll>>seg;
vector<ll>I,D;
pair<ll,ll> mi(pair<ll,ll>  a, pair<ll,ll> b)
{
    if(a.first<b.first)
        return a;
    return b;    
}
void update(ll pos, ll cant, ll est)
{
    seg[pos]=mi(seg[pos],{cant,est});
    pos/=2;
    while(pos>0)
    {
        seg[pos]=mi(seg[pos*2],seg[pos*2+1]);
        pos/=2;
    }
}
pair<ll,ll> calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return {INF,-1};
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    return mi(calc(a,b,nod*2),calc(a,b,nod*2+1));
}
vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia)
{
    vector<int>ans;
    if(E<=1)
    return ans;
    vector<ll>cam(E+1,-1);
    ll i,fin=0,pot=1,res,dist;
    for(i=0; i<E; i++)
    {
        fin=max(fin,(ll)ubicacion[i]);
    }
    fin++;
    while(pot<fin)
        pot*=2;
    fin--;    
    seg.resize(pot*2,{INF,-1});
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    seg[min((ll)autonomia[0],fin)+pot]={0,0};
    for(i=pot-1; i>0; i--)
    {
        seg[i]=mi(seg[i*2],seg[i*2+1]);
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    for(i=1; i<E; i++)
    {
        dist=min((ll)ubicacion[i]+autonomia[i],fin);
        pair<ll,ll>res=calc((ll)ubicacion[i]+pot,int(I.size()),1);
        if(res.first==INF)
            continue;
        update(dist+pot,res.first+1,i);
        cam[i]=res.second;
    }
    pair<ll,ll>cons=seg[fin+pot];
    if(cons.second==-1)
        return ans;
    while(cons.second>0)
    {
        ans.push_back(ubicacion[cons.second]);
        cons={0,cam[cons.second]};
    }
    reverse(ans.begin(),ans.end());
    if(int(ans.size())==0||ans[int(ans.size())-1]!=ubicacion[int(ubicacion.size())-1])
    {
        ans.push_back(ubicacion[int(ubicacion.size())-1]);
    }
    return ans;
}
