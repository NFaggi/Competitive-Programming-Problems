//Link: https://oj.uz/problem/view/IOI14_wall
//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define pb push_back
#define fr first
#define se second
#define mp make_pair
using namespace std;

struct nodo
{
    ll sum=0;
    ll mi[2]={0,0}, cmi[2]={0,0}, ma[2]={0,0}, cma[2]={0,0};
};

vector<ll>I, D;

vector<nodo>seg;

ll pot=1;

void updMa(ll nod, ll x)
{
    if(seg[nod].mi[0]==seg[nod].mi[1])
        seg[nod].mi[1]=x;
    seg[nod].sum-=seg[nod].cmi[0]*seg[nod].mi[0];
    seg[nod].mi[0]=x;
    seg[nod].sum+=seg[nod].cmi[0]*x;
    for(ll i=0; i<2; i++)
        if(seg[nod].ma[i]<x)
            seg[nod].ma[i]=x;
}

void updMi(ll nod, ll x)
{
    if(seg[nod].ma[0]==seg[nod].ma[1])
        seg[nod].ma[1]=x;
    seg[nod].sum-=seg[nod].cma[0]*seg[nod].ma[0];
    seg[nod].ma[0]=x;
    seg[nod].sum+=seg[nod].cma[0]*x;
    for(ll i=0; i<2; i++)
        if(seg[nod].mi[i]>x)
            seg[nod].mi[i]=x;
}

void prop(ll nod)
{
    for(ll i=0; i<2; i++)
        if(seg[nod*2+i].mi[0]<seg[nod].mi[0])
            updMa(nod*2+i,seg[nod].mi[0]);
    for(ll i=0; i<2; i++)
        if(seg[nod*2+i].ma[0]>seg[nod].ma[0])
            updMi(nod*2+i,seg[nod].ma[0]);
}
ll INF=INT_MAX;
void act(ll nod)
{
    ll i, j;
    seg[nod].mi[0]=seg[nod].mi[1]=INF;
    seg[nod].ma[0]=seg[nod].ma[1]=0;
    for(i=0; i<2; i++)
        for(j=0; j<2; j++)
        {
            if(seg[nod*2+i].mi[j]<seg[nod].mi[0])
            {
                seg[nod].mi[1]=seg[nod].mi[0];
                seg[nod].mi[0]=seg[nod*2+i].mi[j];
            }
            else if(seg[nod*2+i].mi[j]<seg[nod].mi[1])
                seg[nod].mi[1]=seg[nod*2+i].mi[j];
            if(seg[nod*2+i].ma[j]>seg[nod].ma[0])
            {
                seg[nod].ma[1]=seg[nod].ma[0];
                seg[nod].ma[0]=seg[nod*2+i].ma[j];
            }
            else if(seg[nod*2+i].ma[j]>seg[nod].ma[1])
                seg[nod].ma[1]=seg[nod*2+i].ma[j];
        }

    seg[nod].cmi[0]=seg[nod].cmi[1]=seg[nod].cma[0]=seg[nod].cma[1]=0;

    seg[nod].sum=seg[nod*2].sum+seg[nod*2+1].sum;
    
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            if(seg[nod].mi[0]==seg[nod*2+i].mi[j])
                seg[nod].cmi[0]+=seg[nod*2+i].cmi[j];
            if(seg[nod].mi[0]!=seg[nod].mi[1]&&seg[nod].mi[1]==seg[nod*2+i].mi[j])
                seg[nod].cmi[1]+=seg[nod*2+i].cmi[j];
            
            if(seg[nod].ma[0]==seg[nod*2+i].ma[j])
                seg[nod].cma[0]+=seg[nod*2+i].cma[j];
            if(seg[nod].ma[0]!=seg[nod].ma[1]&&seg[nod].ma[1]==seg[nod*2+i].ma[j])
                seg[nod].cma[0]+=seg[nod*2+i].cma[j];
        }
    }
}



void chmax(ll a, ll b, ll x, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return;
    if(I[nod]>=a&&D[nod]<=b)
    {
        if(seg[nod].mi[0]>=x)
            return;
        if(seg[nod].mi[1]>x||seg[nod].mi[1]==seg[nod].mi[0])
        {
            updMa(nod,x);
            return;
        }
    }
    prop(nod);
    chmax(a,b,x,nod*2);
    chmax(a,b,x,nod*2+1);
    act(nod);
}

void chmin(ll a, ll b, ll x, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return;
    if(I[nod]>=a&&D[nod]<=b)
    {
        if(seg[nod].ma[0]<=x)
            return;
        if(seg[nod].ma[1]<x||seg[nod].ma[0]==seg[nod].ma[1])
        {
            updMi(nod,x);
            return;
        }
    }
    prop(nod);
    chmin(a,b,x,nod*2);
    chmin(a,b,x,nod*2+1);
    act(nod);
}

ll calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod].sum;
    prop(nod);
    ll res=calc(a,b,nod*2)+calc(a,b,nod*2+1);
    act(nod);
    return res;
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[])
{
    ll i=0;
    while(pot<n)
        pot*=2;
    seg.resize(pot*2);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=0; i<n; i++)
        seg[i+pot].cmi[0]=seg[i+pot].cma[0]=1;
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i].cmi[0]=seg[i*2].cmi[0]+seg[i*2+1].cmi[0];
        seg[i].cma[0]=seg[i*2].cma[0]+seg[i*2+1].cma[0];
    }
    for(i=0; i<k; i++)
    {
        if(op[i]==1)
            chmax(left[i]+pot,right[i]+pot,height[i],1);
        else
            chmin(left[i]+pot,right[i]+pot,height[i],1);
    }

    for(i=0; i<n; i++)
        finalHeight[i]=int(calc(i+pot,i+pot,1));
    return;
}
