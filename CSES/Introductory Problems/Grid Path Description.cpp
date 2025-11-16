#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
 
bool vis[7][7];
 
ll X[4]={0,0,-1,1};
ll Y[4]={-1,1,0,0};
 
ll cant, up, down, lef, righ;
string s;
vector<ll>v;
bool valid(ll x, ll y)
{
    return !(x<0||y<0||x>=7||y>=7||vis[x][y]);
}
void calc(ll id, ll x, ll y)
{
    if(x==6&&y==0)
    {
        if(id==sz(s))
            cant++;
        return;
    }
    up=1;
    down=1;
    lef=1;
    righ=1;
    if(x>0)
        up=vis[x-1][y];
    if(x+1<7)
        down=vis[x+1][y];
    if(y>0)
        lef=vis[x][y-1];
    if(y+1<7)
        righ=vis[x][y+1];
    if(up==down&&lef==righ&&up!=lef)
        return;
    vis[x][y]=1;
    if(v[id]!=4)
    {
        if(valid(x+X[v[id]],y+Y[v[id]]))
            calc(id+1,x+X[v[id]],y+Y[v[id]]);
    }
    else
        for(ll i=0; i<4; i++)
            if(valid(x+X[i],y+Y[i]))
                calc(id+1,x+X[i],y+Y[i]);
    
    vis[x][y]=0;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s;
    for(auto k:s)
    {
        switch (k)
        {
            case 'L': v.pb(0); break;
            case 'R': v.pb(1); break;
            case 'U': v.pb(2); break;
            case 'D': v.pb(3); break;
            default: v.pb(4); break; 
        }
    }
    calc(0,0,0);
    cout << cant;
    return 0;
}
