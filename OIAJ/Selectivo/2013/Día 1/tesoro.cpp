//Link: https://juez.oia.unsam.edu.ar/task/127
//Score: 100/100
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

const int INF=1e9+7;
const int MAXN=121;
ll dist[MAXN][MAXN][MAXN];
pair<ll,pair<ll,ll>>ant[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
ll X[4]={-1,0,0,1};
ll Y[4]={0,-1,1,0};
int main()
{
    ifstream cin ("tesoro.in");
    ofstream cout ("tesoro.out");
    ll n, m, f, ti=-1, tj, mi=INF, i, j, used, nx, ny, l;
    cin >> n >> m >> f;
    vector<string>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        if(ti==-1)
            for(j=0; j<m; j++)
                if(v[i][j]=='T')
                {
                    ti=i;
                    tj=j;
                    break;
                }
    }
    if(v[0][0]=='P'||ti==-1)
    {
        cout << "imposible\n";
        return 0;
    }
    else if(v[0][0]=='W')
    {
        f--;
        if(f<0)
        {
            cout << "imposible\n";
            return 0;
        }
    }
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            for(l=0; l<=f; l++)
                dist[i][j][l]=INF;
    dist[0][0][0]=1;
    priority_queue<pair<ll,pair<ll,pair<ll,ll>>>>pq;
    pq.push({-1,{0,{0,0}}});
    while(pq.size())
    {
        ll us=pq.top().se.fr;
        ll x=pq.top().se.se.fr;
        ll y=pq.top().se.se.se;
        pq.pop();
        if(x==ti&&y==tj)
            break;
        if(vis[x][y][us])
            continue;
        vis[x][y][us]=1;
        for(i=0; i<4; i++)
        {
            nx=x+X[i];
            ny=y+Y[i];
            if(nx<0||nx>=n||ny<0||ny>m)
                continue;
            if(v[nx][ny]=='T'||v[nx][ny]=='V')
                if(dist[nx][ny][us]>dist[x][y][us]+1)
                {
                    dist[nx][ny][us]=dist[x][y][us]+1;
                    ant[nx][ny][us]={us,{x,y}};
                    pq.push({-dist[nx][ny][us],{us,{nx,ny}}});
                }
            else if(v[nx][ny]=='W'&&us+1<=f)
                if(dist[nx][ny][us+1]>dist[x][y][us]+1)
                {
                    dist[nx][ny][us+1]=dist[x][y][us]+1;
                    ant[nx][ny][us+1]={us,{x,y}};
                    pq.push({-dist[nx][ny][us+1],{us+1,{nx,ny}}});
                }
        }
    }
    for(i=0; i<=f; i++)
        if(dist[ti][tj][i]<mi)
        {
            mi=dist[ti][tj][i];
            used=i;
        }
    if(mi==INF)
    {
        cout << "imposible\n";
        return 0;
    }
    cout << mi << '\n';
    vector<pair<ll,ll>>rec;
    rec.pb({ti,tj});
    pair<ll,pair<ll,ll>>act={used,{ti,tj}};
    while(act.se.fr!=0||act.se.se!=0)
    {
        act=ant[act.se.fr][act.se.se][act.fr];
        rec.pb({act.se.fr,act.se.se});
    }
    for(i=sz(rec)-1; i>=0; i--)
        cout << '(' << rec[i].fr << "," << rec[i].se << ")\n";
    return 0;
}
