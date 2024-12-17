//Link: https://codeforces.com/problemset/problem/1215/E
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
vector<ll>seg[20],I,D;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i,col=0,j, k, l, cost;
    cin >> n;
    vector<ll>v(n);
    vector<ll>positions[20];
    set<ll>s;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    map<ll,ll>m;
    for(auto k:s)
    {
        m[k]=col;
        col++;
    }
    for(i=0; i<n; i++)
        v[i]=m[v[i]];

    vector<pair<ll,ll>>rangeColors(col,{-1,-1});
    vector<ll>UnionCost(col,0);
    for(i=0; i<n; i++)
    {
        positions[v[i]].push_back(i);
        rangeColors[v[i]].second=i;
        if(rangeColors[v[i]].first==-1)
            rangeColors[v[i]].first=i;
    }
    for(i=0; i<col; i++)
    {
        ll newPos=positions[i][0]+1;
        UnionCost[i]=positions[i][0]*sz(positions[i]);
        for(j=1; j<sz(positions[i]); j++)
        {
            UnionCost[i]+=positions[i][j]-newPos;
            newPos++;
        }
    }
    vector<vector<ll>>cant(col,vector<ll>(col,0));
    for(i=0; i<col; i++)
    {
        for(j=0; j<col; j++)
        {
            if(j==i)
                continue;
            cant[i][j]=0;
            k=0;
            l=0;
            while(k<sz(positions[i])&&l<sz(positions[j]))
            {
                while(k<sz(positions[i])&&positions[i][k]<positions[j][l])
                    k++;
                if(k==sz(positions[i]))
                    break;
                cant[i][j]+=sz(positions[i])-k;
                l++;
                if(l==sz(positions[j]))
                    break;
            }
        }
    }
    vector<ll>dp(1<<col,LLONG_MAX);
    dp[0]=0;
    for(i=1; i<sz(dp); i++)
    {
        for(j=0; j<col; j++)
        {
            if((1<<j)&i)
            {
                cost=UnionCost[j];
                for(k=0; k<col; k++)
                {
                    if(k==j)
                        continue;
                    if((1<<k)&i)
                        cost-=cant[j][k];
                }
                dp[i]=min(dp[i],dp[i^(1<<j)]+cost);
            }
        }
    }
    cout << dp[sz(dp)-1];
    return 0;
}

