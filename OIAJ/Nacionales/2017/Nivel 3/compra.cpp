//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/38
#include <bits/stdc++.h>
#define ll int
using namespace std;
const int INF=INT_MAX;
struct PQ{ int precio, cantidad ; } ; 
struct FQ{ int fabricante, cantidad ; } ;
vector<pair<ll,ll>>seg,seg2;
vector<ll>I,D;

pair<ll,ll> minSeg(int a, int b, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return {INF,0};
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    pair<ll,ll> p=minSeg(a,b,nod*2), p2=minSeg(a,b,nod*2+1);    
    if(p.first>p2.first)
        return p2;
    return p;     
}

pair<ll,ll> minSeg2(int a, int b, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return {INF,0};
    if(I[nod]>=a&&D[nod]<=b)
        return seg2[nod];
    pair<ll,ll> p=minSeg2(a,b,nod*2), p2=minSeg2(a,b,nod*2+1);    
    if(p.first>p2.first)
        return p2;
    return p;   
}


int compra( int P, vector< PQ > fabricantes, vector< PQ > compradores, vector< FQ > &Fab, int & Comp )
{
    Comp=0;
    ll n=int(fabricantes.size()), pot=1, i, m=int(compradores.size()), mi, ma, piv, pos, cost,res=-1, can, gan, vend, fa=-1;
    while(pot<n)
        pot*=2;
    vector<pair<ll,pair<ll,ll>>>v(n);
    seg.resize(pot*2,{INF,0});
    seg2.resize(pot*2,{INF,0});
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot*2; i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=0; i<n; i++)
    {
        v[i].first=fabricantes[i].cantidad;
        v[i].second.first=fabricantes[i].precio;
        v[i].second.second=i;
    }
    sort(v.begin(),v.end());
    
    for(i=pot; i<pot+n; i++)
    {
        seg[i].first=v[i-pot].second.first;
        seg[i].second=v[i-pot].second.second;
        seg2[i].first=v[i-pot].second.first*v[i-pot].first;
        seg2[i].second=v[i-pot].second.second;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=seg[i*2];
        if(seg[i].first>seg[i*2+1].first)
        {
            seg[i]=seg[i*2+1];
        }
        seg2[i]=seg2[i*2];
        if(seg2[i].first>seg2[i*2+1].first)
        {
            seg2[i]=seg2[i*2+1];
        }
    }
    
    for(i=0; i<m; i++)
    {
        pos=-1;
        mi=0;
        ma=n-1;
        while(mi<=ma)
        {
            piv=(mi+ma)/2;
            if(v[piv].first>compradores[i].cantidad)
            {
                ma=piv-1;
            }
            else
            {
                mi=piv+1;
                pos=piv;
            }
        }
        cost=INF;
        pair<ll,ll>p={-1,-1},p2;
        if(pos!=-1)
        {
            p=minSeg(pot,pos+pot,1);
            p.first*=compradores[i].cantidad;
            //cout << cost << endl;
        }
        if(pos<n-1)
        {
            p2=minSeg2(pos+1+pot,(n-1)+pot,1);
            if(p2.first<p.first||p.first==-1)
                p=p2;
            //cout << minSeg2(pos+1+pot,(n-1)+pot,1) << endl;
        }
        
        cost=p.first;
        vend=p.second;
        can=compradores[i].cantidad;
        gan=compradores[i].precio;
        if(res<can*gan-cost&&cost<=P)
        {
            res=can*gan-cost;
            Comp=i+1;
            fa=vend+1;
        }
    }
    if(res<0)
        return -1;
    if(fa!=-1)
    {
        FQ f;
        f.fabricante=fa;
        f.cantidad=max(fabricantes[fa-1].cantidad,compradores[Comp-1].cantidad);
        Fab.push_back(f);
    }    
    return res;
}