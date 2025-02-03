//Link: https://juez.oia.unsam.edu.ar/task/140
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int consulta(int i, int W, int H);
ll dist(ll a, ll b)
{
    return a*a+b*b;
}
int rectangulos(vector<int> x, vector<int> y)
{
    ll mi=LLONG_MAX,dis,pos=1, i, j,cant,dif,W,H,punt=1,aW=1,aH=1,n=int(x.size()),l,r,comp;
    vector<ll>v;
    for(i=0; i<n; i++)
    {
        dis=dist(x[i],y[i]);
        if(dis<mi)
        {
            mi=dis;
            pos=i+1;
        }
        v.push_back(i+1);
    }
    map<pair<ll,ll>,ll>pre;
    dif=(int(v.size())+1)/2;
    while(int(v.size())>1)
    {
        dif=(int(v.size())+1)/2;
        mi=LLONG_MAX;
        for(i=0; i<n; i++)
        {
            dis=dist(x[v[i]-1],y[v[i]-1]);
            if(dis<mi)
            {
                mi=dis;
                pos=v[i];
            }
        }
        mi=LLONG_MAX;
        for(i=0; i<n; i++)
        {
            W=abs(x[pos-1]-x[v[i]-1])*2;
            W=max(W,1ll);
            H=abs(y[pos-1]-y[v[i]-1])*2;
            H=max(H,1ll);
            cant=0;
            for(j=0; j<n; j++)
            {
                l=abs(x[pos-1]-x[v[j]-1])*2;
                l=max(l,1ll);
                r=abs(y[pos-1]-y[v[j]-1])*2;
                r=max(r,1ll);
                if(l <= W && r <= H)
                {
                    cant++;
                }
            }
            if(abs(dif-cant)<mi||abs(dif-cant)==mi&&cant<dif)
            {
                mi=abs(dif-cant);
                punt=j;
                aW=W;
                aH=H;
            }
        }
        vector<ll>v2;
        if(pre[make_pair(aW,aH)]==0)
        {
            comp=consulta(pos,aW,aH);
            pre[make_pair(aW,aH)]=comp+1;
        }
        else
            comp=pre[make_pair(aW,aH)]-1;
        if(comp)
        {
            for(i=0; i<n; i++)
            {
                l=abs(x[pos-1]-x[v[i]-1])*2;
                l=max(l,1ll);
                r=abs(y[pos-1]-y[v[i]-1])*2;
                r=max(r,1ll);
                if(l <= aW && r <= aH)
                {
                    v2.push_back(v[i]);
                }
            }
        }
        else
        {
            for(i=0; i<n; i++)
            {
                l=abs(x[pos-1]-x[v[i]-1])*2;
                l=max(l,1ll);
                r=abs(y[pos-1]-y[v[i]-1])*2;
                r=max(r,1ll);

                if(( l > aW || r > aH))
                {
                    v2.push_back(v[i]);
                }
            }
        }
        v=v2;
        n=int(v2.size());
    }
    return v[0];
}
