//Score: 100/100
#include <bits/stdc++.h>

using namespace std;
vector<int> I, D, sel;
vector<long long> lazy, seg, seg2;
void prop(int nod)
{
    if (lazy[nod] != 0)
    {
        lazy[nod*2] += lazy[nod];
        lazy[nod*2+1] += lazy[nod];

        seg[nod*2] += lazy[nod];
        seg[nod*2+1] += lazy[nod];

        lazy[nod] = 0;
    }
}
void act(int nod)
{
    seg[nod]=seg[nod*2];
    sel[nod]=sel[nod*2];
    if(seg[nod*2+1]>=seg[nod])
    {
        seg[nod]=seg[nod*2+1];
        sel[nod]=sel[nod*2+1];
    }
}
void update2(int nod, long long x)
{
    seg[nod]=x+lazy[nod];
    nod/=2;
    while(nod>0)
    {
        act(nod);
        nod/=2;
    }
}
void update(int a, int b, long long x, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return;
    if(I[nod]>=a&&D[nod]<=b)
    {
        lazy[nod]+=x;
        seg[nod]+=x;
        return;
    }
    prop(nod);
    update(a,b,x,nod*2);
    update(a,b,x,nod*2+1);
    act(nod);
}
pair<long long, int> calc2(int a, int b, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return {-1,0};
    if(I[nod]>=a&&D[nod]<=b)
        return {seg[nod],sel[nod]};
    prop(nod);
    pair<long long, int> c1, c2;
    c1=calc2(a,b,nod*2);
    c2=calc2(a,b,nod*2+1);
    act(nod);
    if(c1.first>c2.first)
        return c1;
    return c2;
}
void upSum(int pos, long long x)
{
    while(pos>0)
    {
        seg2[pos]+=x;
        pos/=2;
    }
}
long long sum(int a, int b, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0ll;
    if(I[nod]>=a&&D[nod]<=b)
        return seg2[nod];
    return sum(a,b,nod*2)+sum(a,b,nod*2+1);
}
vector<long long> pomelos(int N, vector<string> &e, vector<int> &p1, vector<int> &p2)
{
    vector<long long>ans, ant(N,0), ant2(N,0);
    int i, q=int(e.size()), j, pot=1, l, r;
    long long x, dif, res;
    while(pot<N)
        pot*=2;
    lazy.resize(pot*2,0);
    seg.resize(pot*2,0);
    seg2.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    sel.resize(pot*2);
    for(i=pot; i<pot*2; i++)
    {
        I[i]=i;
        D[i]=i;
        sel[i]=i-pot;
        if(i-pot>=N)
            sel[i]=N-1;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        sel[i]=sel[i*2+1];
    }
    for(j=0; j<q; j++)
    {
        if(e[j]=="A")
        {
            i=p1[j]-1;
            x=p2[j];
            dif=x-ant[i];
            ant[i]=x;
            update(i+pot, pot*2, dif, 1);
            upSum(i+pot,dif);
        }
        else if(e[j]=="B")
        {
            i=p1[j]-1;
            x=p2[j];
            ant2[i]=x;
            update(i+pot, i+pot, 0, 1);
            update2(i+pot, x);
        }
        else
        {
            l=p1[j]-1;
            r=p2[j]-1;
            pair<long long, int>c=calc2(l+pot,r+pot,1);
            res=ant2[c.second];
            //cout << c.second << endl;
            res+=sum(l+pot,c.second+pot,1);
            ans.push_back(res);
            //ans.push_back(sum(l+pot,r+pot,1));
        }
        /*for(i=1; i<pot*2; i++)
        {
            cout << '{' << seg2[i] << ',' << sel[i]<< '}' << ' ';
        }
        cout << endl;*/
    }
    return ans;
}
