//Link: https://juez.oia.unsam.edu.ar/task/167
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define fr first
#define se second
using namespace std;

ll n;

vector<vector<ll>>mp,vert,horz,tims,proc;

void armar()
{
    ll i, j;
    for(i=0; i<sz(vert); i++)
    {
        for(j=0; j<sz(vert[i]); j++)
        {
            if(j>0)
                vert[i][j]+=vert[i][j-1];
            if(i>0)
                horz[i][j]+=horz[i-1][j];
            mp[i][j]=max(vert[i][j],horz[i][j]);
        }
    }
}

void most()
{
    ll i, j;
    for(i=0; i<sz(vert); i++)
    {
        for(j=0; j<sz(vert[i]); j++)
        {
            if(tims[i][j]==LLONG_MAX)
            {
                cout << 7;
                continue;
            }
            cout << tims[i][j];
        }
        cout << '\n';
    }
}

void dijkstra()
{
    priority_queue<pair<ll,pair<ll,ll>>>pq;
    pq.push({-0,{0,0}});
    tims[0][0]=0;
    while(pq.size())
    {
        ll x=pq.top().se.fr;
        ll y=pq.top().se.se;
        pq.pop();
        if(proc[x][y]==1)
            continue;
        proc[x][y]=1;
        if(x>0)
        {
            if(mp[x-1][y]==1)
            {
                if(tims[x-1][y]>tims[x][y]+1)
                {
                    tims[x-1][y]=tims[x][y]+1;
                    pq.push({-tims[x-1][y],{x-1,y}});
                }
            }
            else if(mp[x-1][y]==0)
            {
                if(tims[x-1][y]>tims[x][y])
                {
                    tims[x-1][y]=tims[x][y];
                    pq.push({-tims[x-1][y],{x-1,y}});
                }
            }
        }
        if(x+1<sz(tims))
        {
            if(mp[x+1][y]==1)
            {
                if(tims[x+1][y]>tims[x][y]+1)
                {
                    tims[x+1][y]=tims[x][y]+1;
                    pq.push({-tims[x+1][y],{x+1,y}});
                }
            }
            else if(mp[x+1][y]==0)
            {
                if(tims[x+1][y]>tims[x][y])
                {
                    tims[x+1][y]=tims[x][y];
                    pq.push({-tims[x+1][y],{x+1,y}});
                }
            }
        }
        if(y>0)
        {
            if(mp[x][y-1]==1)
            {
                if(tims[x][y-1]>tims[x][y]+1)
                {
                    tims[x][y-1]=tims[x][y]+1;
                    pq.push({-tims[x][y-1],{x,y-1}});
                }
            }
            else if(mp[x][y-1]==0)
            {
                if(tims[x][y-1]>tims[x][y])
                {
                    tims[x][y-1]=tims[x][y];
                    pq.push({-tims[x][y-1],{x,y-1}});
                }
            }
        }
        if(y<sz(tims[0]))
        {
            if(mp[x][y+1]==1)
            {
                if(tims[x][y+1]>tims[x][y]+1)
                {
                    tims[x][y+1]=tims[x][y]+1;
                    pq.push({-tims[x][y+1],{x,y+1}});
                }
            }
            else if(mp[x][y+1]==0)
            {
                if(tims[x][y+1]>tims[x][y])
                {
                    tims[x][y+1]=tims[x][y];
                    pq.push({-tims[x][y+1],{x,y+1}});
                }
            }
        }
    }
}

void bfs(ll x, ll y)
{
    queue<pair<ll,ll>>q;
    q.push({x,y});
    while(q.size())
    {
        x=q.front().fr;
        y=q.front().se;
        q.pop();
        if(x>0)
        {
            if(tims[x-1][y]==LLONG_MAX&&mp[x-1][y]==0)
            {
                tims[x-1][y]=1;
                q.push({x-1,y});
            }
        }
        if(x+1<sz(tims))
        {
            if(tims[x+1][y]==LLONG_MAX&&mp[x+1][y]==0)
            {
                tims[x+1][y]=1;
                q.push({x+1,y});
            }
        }
        if(y>0)
        {
            if(tims[x][y-1]==LLONG_MAX&&mp[x][y-1]==0)
            {
                tims[x][y-1]=1;
                q.push({x,y-1});
            }
        }
        if(y+1<sz(tims[0]))
        {
            if(tims[x][y+1]==LLONG_MAX&&mp[x][y+1]==0)
            {
                tims[x][y+1]=1;
                q.push({x,y+1});
            }
        }
    }
}

vector<int> herculano(vector<int> &x, vector<int> &y, vector<int> &a, vector<int> &b, vector<int> &t)
{

    ll aum=1, i, tamX=0, tamY=0, A, B, ant, j, ti=0, cant=0;
    map<ll,ll>mx,my;
    vector<int>xord=x,yord=y;
    sort(all(xord));
    sort(all(yord));
    unique(all(xord));
    unique(all(yord));

    ant=-1;
    for(i=0; i<sz(xord); i++)
    {
        if(xord[i]<=ant)
            break;
        mx[xord[i]]=i;
        ant=xord[i];
    }
    ant=-1;
    for(i=0; i<sz(yord); i++)
    {
        if(yord[i]<=ant)
            break;
        my[yord[i]]=i;
        ant=yord[i];
    }
    for(i=0; i<sz(x); i++)
    {
        x[i]=mx[x[i]];
        y[i]=my[y[i]];
    }
    n=sz(x);

    vector<pair<ll,ll>>v;
    for(i=0; i<n; i++)
        v.pb({x[i],i});
    sort(all(v));
    ant=-1;
    for(auto k:v)
    {
        if(ant!=k.fr)
            aum++;
        x[k.se]+=aum;
        ant=k.fr;
    }

    ant=-1;
    v={};
    aum=1;
    for(i=0; i<n; i++)
        v.pb({y[i],i});
    sort(all(v));
    for(auto k:v)
    {
        if(ant!=k.fr)
            aum++;
        y[k.se]+=aum;
        ant=k.fr;
    }

    for(auto k:x)
        tamX=max(tamX,1ll*k);
    tamX+=2;

    for(auto k:y)
        tamY=max(tamY,1ll*k);
    tamY+=2;
    mp.resize(tamX,vector<ll>(tamY,0));
    horz.resize(tamX,vector<ll>(tamY,0));
    vert.resize(tamX,vector<ll>(tamY,0));
    tims.resize(tamX,vector<ll>(tamY,LLONG_MAX));
    proc.resize(tamX,vector<ll>(tamY,0));
    for(i=0; i<sz(a); i++)
    {
        A=a[i];
        B=b[i];
        if(x[A]==x[B])
        {
            if(y[A]>y[B])
                swap(A,B);
            vert[x[A]][y[A]+1]+=(t[i]+1);
            vert[x[A]][y[B]]-=(t[i]+1);
        }
        else
        {
            if(x[A]>x[B])
                swap(A,B);
            horz[x[A]+1][y[A]]+=(t[i]+1);
            horz[x[B]][y[A]]-=(t[i]+1);
        }
    }
    armar();
    for(i=0; i<n; i++)
        mp[x[i]][y[i]]=2;
    dijkstra();
    for(i=0; i<sz(tims); i++)
    {
        for(j=0; j<sz(tims[0]); j++)
        {
            if(tims[i][j]==LLONG_MAX)
                continue;
            if(mp[i][j]==0)
            {
                ti=max(ti,tims[i][j]);
            }
        }
    }
    for(i=0; i<sz(tims); i++)
    {
        for(j=0; j<sz(tims[0]); j++)
        {
            if(tims[i][j]==LLONG_MAX&&mp[i][j]==0)
            {
                cant++,
                bfs(i,j);
            }
        }
    }

    return {ti,cant};
}
