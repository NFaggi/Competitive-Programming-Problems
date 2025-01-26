//Link: https://ioi.contest.codeforces.com/group/32KGsXgiKA/contest/103755/problem/F
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

const int MAXN=800;
const int INF=1e9;

char mapa[MAXN][MAXN];
ll tim[MAXN][MAXN], osoI, osoJ, s, n;

bool can(ll in)
{
    queue<vector<ll>>pq;
    vector<ll>v(4), nV(4); /// 0-timpo actual 1-pasos dados 2-posicion i 3-posicion j
    vector<vector<bool>>vis(n,vector<bool>(n,0));
    vector<vector<pair<ll,ll>>>cost(n,vector<pair<ll,ll>>(n,{INF,INF}));
    v[0]=in;
    v[1]=0;
    v[2]=osoI;
    v[3]=osoJ;
    pq.push(v);
    while(pq.size())
    {
        v=pq.front();
        pq.pop();
        if(vis[v[2]][v[3]])
            continue;
        vis[v[2]][v[3]]=1;
        if(mapa[v[2]][v[3]]=='D')
            return 1;
        if(v[0]>=tim[v[2]][v[3]]||mapa[v[2]][v[3]]=='T'||mapa[v[2]][v[3]]=='H')
            continue;
        if(v[2]>0&&!vis[v[2]-1][v[3]])
        {
            nV=v;
            nV[2]--;
            if(nV[1]+1==s)
            {
                nV[1]=0;
                nV[0]++;
            }
            else
                nV[1]++;
            if(cost[v[2]-1][v[3]].fr>nV[0]||(cost[v[2]-1][v[3]].fr==nV[0]&&cost[v[2]-1][v[3]].se>nV[1]))
            {
                cost[v[2]-1][v[3]]={nV[0],nV[1]};
                pq.push(nV);
            }
        }

        if(v[2]+1<n&&!vis[v[2]+1][v[3]])
        {
            nV=v;
            nV[2]++;
            if(nV[1]+1==s)
            {
                nV[1]=0;
                nV[0]++;
            }
            else
                nV[1]++;
            if(cost[v[2]+1][v[3]].fr>nV[0]||(cost[v[2]+1][v[3]].fr==nV[0]&&cost[v[2]+1][v[3]].se>nV[1]))
            {
                cost[v[2]+1][v[3]]={nV[0],nV[1]};
                pq.push(nV);
            }
        }

        if(v[3]>0&&!vis[v[2]][v[3]-1])
        {
            nV=v;
            nV[3]--;
            if(nV[1]+1==s)
            {
                nV[1]=0;
                nV[0]++;
            }
            else
                nV[1]++;
            if(cost[v[2]][v[3]-1].fr>nV[0]||(cost[v[2]][v[3]-1].fr==nV[0]&&cost[v[2]][v[3]-1].se>nV[1]))
            {
                cost[v[2]][v[3]-1]={nV[0],nV[1]};
                pq.push(nV);
            }
        }

        if(v[3]+1<n&&!vis[v[2]][v[3]+1])
        {
            nV=v;
            nV[3]++;
            if(nV[1]+1==s)
            {
                nV[1]=0;
                nV[0]++;
            }
            else
                nV[1]++;
            if(cost[v[2]][v[3]+1].fr>nV[0]||(cost[v[2]][v[3]+1].fr==nV[0]&&cost[v[2]][v[3]+1].se>nV[1]))
            {
                cost[v[2]][v[3]+1]={nV[0],nV[1]};
                pq.push(nV);
            }
        }
    }
    return 0;
}

void update(pair<ll,ll>p)
{
    queue<pair<ll,ll>>q;
    q.push(p);
    while(q.size())
    {
        p=q.front();
        q.pop();
        if(p.fr>0)
        {
            if(tim[p.fr][p.se]+1<tim[p.fr-1][p.se]&&mapa[p.fr-1][p.se]!='T'&&mapa[p.fr-1][p.se]!='D')
            {
                tim[p.fr-1][p.se]=tim[p.fr][p.se]+1;
                q.push({p.fr-1,p.se});
            }
        }
        if(p.fr+1<n)
        {
            if(tim[p.fr][p.se]+1<tim[p.fr+1][p.se]&&mapa[p.fr+1][p.se]!='T'&&mapa[p.fr+1][p.se]!='D')
            {
                tim[p.fr+1][p.se]=tim[p.fr][p.se]+1;
                q.push({p.fr+1,p.se});
            }
        }

        if(p.se>0)
        {
            if(tim[p.fr][p.se]+1<tim[p.fr][p.se-1]&&mapa[p.fr][p.se-1]!='T'&&mapa[p.fr][p.se-1]!='D')
            {
                tim[p.fr][p.se-1]=tim[p.fr][p.se]+1;
                q.push({p.fr,p.se-1});
            }
        }
        if(p.se+1<n)
        {
            if(tim[p.fr][p.se]+1<tim[p.fr][p.se+1]&&mapa[p.fr][p.se+1]!='T'&&mapa[p.fr][p.se+1]!='D')
            {
                tim[p.fr][p.se+1]=tim[p.fr][p.se]+1;
                q.push({p.fr,p.se+1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, j, mi=0, ma=INF, piv, pos=-1;
    cin >> n >> s;
    string S;
    queue<pair<ll,ll>>q;
    forn(i,n)
    {
        cin >> S;
        forn(j,n)
        {
            mapa[i][j]=S[j];
            tim[i][j]=INF;
            if(mapa[i][j]=='D'||mapa[i][j]=='T')
                continue;
            if(mapa[i][j]=='H')
            {
                tim[i][j]=0;
                q.push({i,j});
            }
            if(mapa[i][j]=='M')
            {
                osoI=i;
                osoJ=j;
            }
        }
    }

    while(q.size())
    {
        update(q.front());
        q.pop();
    }
    /*forn(i,n)
    {
        forn(j,n)
        {
            if(tim[i][j]!=INF)
                cout << tim[i][j] << ' ';
            else
                cout << "I ";
        }
        cout << '\n';
    }*/
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(piv))
        {
            mi=piv+1;
            pos=max(pos,piv);
        }
        else
            ma=piv-1;
    }
    cout << pos;
    return 0;
}
