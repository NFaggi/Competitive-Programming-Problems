//Link: https://ioi.contest.codeforces.com/group/32KGsXgiKA/contest/103769/problem/A
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

long long delivery(int N, int K, int L, int p[])
{
    vector<ll>iz(N,0), der(N,0);
    ll i, ans, act=0, cost, mi=LLONG_MAX, j;
    for(i=0; i<N; i++)
    {
        iz[i]=p[i]*2ll;
        if(i-K>=0)
        {
            iz[i]=iz[i]+iz[i-K];
        }
    }
    for(i=N-1; i>=0; i--)
    {
        der[i]=(L-p[i])*2ll;
        if(i+K<N)
        {
            der[i]=der[i]+der[i+K];
        }
    }
    for(i=0; i<=N; i++)
    {
        cost=0;
        if(i-1>=0)
            cost=iz[i-1];
        if(i<N)
            cost=cost+der[i];
        mi=min(cost,mi);
    }
    for(i=0; i<=N; i++)
    {
        cost=0;
        if(i-1>=0)
            cost=iz[i-1];
        act=0;
        cost=cost+L;
        if(i+K<N)
            cost=cost+der[i+K];
        mi=min(mi,cost);
    }
    return mi;
}
