//Link: https://ioi.contest.codeforces.com/group/32KGsXgiKA/contest/103761/problem/F
//Score: 100/100
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

int pot=1;
vector<int>seg,I,D;

void update(int nod)
{
    while(nod>0)
    {
        seg[nod]--;
        nod/=2;
    }
}

int calc(int bus, int nod)
{
    if(nod>=pot)
        return nod;
    int iz=seg[nod*2], der=seg[nod*2+1];
    if(iz<bus)
        return calc(bus-iz, nod*2+1);
    return calc(bus, nod*2);
}

bool intersectan(pair<int,int> a, pair<int,int> b)
{
    return a.fr<=b.fr&&b.se<=a.se;
}

bool comp(const pair<int,int> & a, const pair<int,int> & b)
{
    if(a.fr!=b.fr)return a.fr<b.fr;
    return a.se>b.se;
}
int GetBestPosition(int N, int C, int R, int *K, int *S, int *E)
{
    int i, l, r, j, ma=0, pos=0;
    vector<int>sum(N);
    vector<pair<int,int>>inters(C);
    sum[0]=0;
    for(i=1; i<N; i++) sum[i]=sum[i-1]+(K[i-1]>R);

    while(pot<(N+1))
        pot*=2;
    seg.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=0; i<=N; i++)
        seg[i+pot]=1;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=seg[i*2]+seg[i*2+1];
    }
    for(i=0; i<C; i++)
    {
        l=S[i]+1;
        r=E[i]+1;
        inters[i].fr=calc(l,1)-pot;
        inters[i].se=(calc(r+1,1)-1)-pot;
        for(j=r; j>=l+1; j--)
            update(calc(j,1));
    }
    sort(inters.begin(),inters.end(),comp);

    vector<pair<int,int>>pila;

    for(i=0; i<C; i++)
    {
        while(pila.size()&&!intersectan(pila[sz(pila)-1],inters[i]))
        {
            pila.pop_back();
        }
        if(sum[inters[i].fr]==sum[inters[i].se])
        {
            pila.push_back(inters[i]);
            if(sz(pila)>ma)
            {
                ma=sz(pila);
                pos=inters[i].fr;
            }
        }
    }

    return pos;
}
