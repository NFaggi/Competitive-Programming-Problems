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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, j;
    cin >> n;
    vector<vector<ll>>v(n,vector<ll>(n,-1));
    queue<pair<ll,ll>>q;
    q.push({0,0});
    v[0][0]=0;
    while(q.size())
    {
        ll x=q.front().fr;
        ll y=q.front().se;
        q.pop();
        if(x+2<n)
        {
            if(y+1<n&&v[x+2][y+1]==-1)
            {
                v[x+2][y+1]=v[x][y]+1;
                q.push({x+2,y+1});
            }
            if(y-1>=0&&v[x+2][y-1]==-1)
            {
                v[x+2][y-1]=v[x][y]+1;
                q.push({x+2,y-1});
            }
        }
        if(x+1<n)
        {
            if(y+2<n&&v[x+1][y+2]==-1)
            {
                v[x+1][y+2]=v[x][y]+1;
                q.push({x+1,y+2});
            }
            if(y-2>=0&&v[x+1][y-2]==-1)
            {
                v[x+1][y-2]=v[x][y]+1;
                q.push({x+1,y-2});
            }
        }
        if(x-2>=0)
        {
            if(y+1<n&&v[x-2][y+1]==-1)
            {
                v[x-2][y+1]=v[x][y]+1;
                q.push({x-2,y+1});
            }
            if(y-1>=0&&v[x-2][y-1]==-1)
            {
                v[x-2][y-1]=v[x][y]+1;
                q.push({x-2,y-1});
            }
        }
        if(x-1>=0)
        {
            if(y+2<n&&v[x-1][y+2]==-1)
            {
                v[x-1][y+2]=v[x][y]+1;
                q.push({x-1,y+2});
            }
            if(y-2>=0&&v[x-1][y-2]==-1)
            {
                v[x-1][y-2]=v[x][y]+1;
                q.push({x-1,y-2});
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout << v[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

