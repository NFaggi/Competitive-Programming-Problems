//Link: https://cses.fi/problemset/task/1735/
#include<bits/stdc++.h>
using namespace std;
vector<long long>lazy,seg;
vector<bool>borr;
vector<int>I,D;
void update(int nod)
{
    nod/=2;
    while(nod>0)
    {
        seg[nod]=seg[nod*2]+seg[nod*2+1];
        nod/=2;
    }
}
void push(int nod)
{
    if(borr[nod]==0)
    {
        seg[nod*2]+=lazy[nod]*((D[nod*2]-I[nod*2])+1);
        lazy[nod*2]+=lazy[nod];
        seg[nod*2+1]+=lazy[nod]*((D[nod*2+1]-I[nod*2+1])+1);
        lazy[nod*2+1]+=lazy[nod];
        lazy[nod]=0;
    }
    else
    {
        seg[nod*2]=lazy[nod]*((D[nod*2]-I[nod*2])+1);
        lazy[nod*2]=lazy[nod];
        seg[nod*2+1]=lazy[nod]*((D[nod*2+1]-I[nod*2+1])+1);
        lazy[nod*2+1]=lazy[nod];
        lazy[nod]=0;
        borr[nod*2]=1;
        borr[nod*2+1]=1;
        borr[nod]=0;
    }
}
void updateSum(int a, int b, long long x, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return;
    if(I[nod]>=a&&D[nod]<=b)
    {
        seg[nod]+=((D[nod]-I[nod])+1)*x;
        lazy[nod]+=x;
        update(nod);
        return;
    }
    push(nod);
    updateSum(a,b,x,nod*2);
    updateSum(a,b,x,nod*2+1);
}
void updateSet(int a, int b, long long x, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return;
    if(I[nod]>=a&&D[nod]<=b)
    {
        seg[nod]=((D[nod]-I[nod])+1)*x;
        lazy[nod]=x;
        borr[nod]=1;
        update(nod);
        return;
    }
    push(nod);
    updateSet(a,b,x,nod*2);
    updateSet(a,b,x,nod*2+1);
}
long long cSum(int a, int b, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    push(nod);
    return cSum(a,b,nod*2)+cSum(a,b,nod*2+1);
}
int main()
{
    int n, q, i, pot=1, op, a, b;
    long long x;
    cin >> n >> q;
    while(pot<n)
        pot*=2;
    seg.resize(pot*2,0);
    lazy.resize(pot*2,0);
    borr.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=0; i<n; i++)
    {
        cin >> seg[i+pot];
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=seg[i*2]+seg[i*2+1];
    }
    while(q--)
    {
        cin >> op >> a >> b;
        a--;
        b--;
        if(op==1)
        {
            cin >> x;
            updateSum(a+pot,b+pot,x,1);
        }
        else if(op==2)
        {
            cin >> x;
            updateSet(a+pot,b+pot,x,1);
        }
        else
        {
            cout << cSum(a+pot,b+pot,1) << '\n';
        }
    }
    return 0;
}