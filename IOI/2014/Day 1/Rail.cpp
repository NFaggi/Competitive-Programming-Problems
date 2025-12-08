//Link: https://oj.uz/problem/view/IOI14_rail
//Score: 100/100
#include "rail.h"
#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define pb push_back
#define fr first
#define se second
#define mp make_pair
using namespace std;

int getDistance(int x, int y);

const int MAXN=5001;

ll memo[MAXN][MAXN];

int getD(int x, int y)
{
    if(memo[x][y])
        return memo[x][y]-1;
    memo[y][x]=memo[x][y]=getDistance(x, y)+1;
    return memo[x][y]-1;
}

const int MAXM=1e6+1;

ll tip[MAXM];

void findLocation(int N, int first, int location[], int stype[])
{
    ll i, l = 0, r, a, b, r1, nod, mid;

    auto reg = [&](ll v1, ll v2, ll v3)
    {
        stype[v1]=v2;
        tip[v3]=v2;
        location[v1]=v3;
    };
    reg(0,1,first);
    if (N == 1)
        return;
    vector<ll> dist(N, 0);
    vector<pair<ll, ll>> v;
    for (i = 1; i < N; i++)
    {
        dist[i] = getD(0, i);
        v.pb({dist[i], i});
    }
    sort(all(v));
    reverse(all(v));
    r = v.back().se;
    r1 = r;
    v.pop_back();
    reg(r,2,location[0] + dist[r]);

    pair<ll,ll>ans1,ans2;
    while (sz(v))
    {
        nod = v.back().se;
        v.pop_back();
        a=location[0]+dist[nod];
        b=location[r]-getD(nod,r);
        mid=(a+b);
        if(tip[mid/2]==2)
            ans1={b,1};
        else
            ans1={a,2};
        a=location[0]-dist[nod]+dist[r1]*2;
        b=location[l]+getD(nod,l);
        mid=(a+b);
        if(tip[mid/2]==1)
            ans2={b,2};
        else
            ans2={a,1};

        if(getD(nod,r)==location[r]-a)
            reg(nod,ans2.se,ans2.fr);
        else
            reg(nod,ans1.se,ans1.fr);
        if(location[nod]<location[l])
            l=nod;
        if(location[nod]>location[r])
            r=nod;
    }
}
