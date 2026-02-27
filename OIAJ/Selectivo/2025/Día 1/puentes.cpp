//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second

using namespace std;

const int sq = 450;
const int MAXN = 2e5 + 1;
const ll INF = INT_MAX;
#define pad fr
#define tam se
pair<ll, ll> uf[sq][MAXN];

vector<ll>grafo[MAXN];

bool ordH(vector<ll> &a, vector<ll> &b)
{
    return a[2] < b[2];
}

bool ordQ(vector<ll> &a, vector<ll> &b)
{
    if (a[3] != b[3])
        return a[3] < b[3];
    return a[4] < b[4];
}
ll un;
ll root(ll a)
{
    if (!uf[un][a].pad)
        return a;

    uf[un][a].pad = root(uf[un][a].pad);
    return uf[un][a].pad;
}
ll x, y;
void rooter(ll &a, ll &b)
{
    x = root(a);
    y = root(b);
    if (a != x)
        uf[un][a].pad = x;
    a = x;
    if (b != y)
        uf[un][b].pad = y;
    b = y;
}
void unir(ll a, ll b)
{
    rooter(a, b);
    if (a == b)
        return;
    if (uf[un][a].tam < uf[un][b].tam)
        swap(a, b);
    uf[un][b].pad = a;
    uf[un][a].tam += uf[un][b].tam + 1;
}

bool unionfind(ll a, ll b)
{
    rooter(a, b);
    return a == b;
}

ll vis[MAXN];

string puentes(int N, vector<int> &A, vector<int> &B, vector<int> &H, vector<int> &TP,
               vector<int> &X, vector<int> &Y, vector<int> &Z, vector<int> &TQ)
{

    string ans(sz(TQ), 'N');
    ll i, j, k, a, b;
    vector<vector<ll>> cons;
    vector<ll> block(sq, INF);
    for (i = 0; i < sz(A); i++)
        cons.pb({A[i], B[i], H[i], TP[i], -1});
    sort(all(cons), ordH);

    for (i = sz(cons) - 1; i >= 0; i--)
        block[i / sq] = cons[i][2];

    vector<vector<ll>> todo = cons;
    for (i = 0; i < sz(X); i++)
        todo.pb({X[i], Y[i], Z[i], TQ[i], i});
    sort(all(todo), ordQ);

    vector<ll> used;
    for (i = 0; i < sz(todo); i++)
    {
        if (todo[i][4] == -1)
        {
            for (j = 0; j < sq; j++)
            {
                if (block[j] > todo[i][2])
                    break;
                un = j;
                unir(todo[i][0], todo[i][1]);
            }
        }
        else
        {
            for (j = 0; j < sq; j++)
            {
                if (block[j] >= todo[i][2])
                {
                    j--;
                    break;
                }
            }
            if (j == -1)
            {
                un = 0;
                if (unionfind(todo[i][0], todo[i][1]))
                    ans[todo[i][4]] = 'S';
            }
            else
            {
                un=j+1;
                for(k=min(sz(cons),sq*(j+1))-1; k>=sq*j; k--)
                {
                    if(cons[k][2]<todo[i][2])
                        break;
                    if(cons[k][3]>todo[i][3])
                        continue;
                    a=cons[k][0];
                    b=cons[k][1];
                    rooter(a,b);
                    if(a!=b)
                    {
                        grafo[a].pb(b);
                        grafo[b].pb(a);
                        if(!vis[a])
                            used.pb(a);
                        if(!vis[b])
                            used.pb(b);
                        vis[a]=1;
                        vis[b]=1;
                    }
                }

                a=todo[i][0];
                b=todo[i][1];
                rooter(a,b);
                queue<ll>q;
                q.push(a);
                while(sz(q))
                {
                    a=q.front();
                    q.pop();
                    vis[a]=2;
                    for(auto k:grafo[a])
                    {
                        if(vis[k]==2)
                            continue;
                        q.push(k);
                        vis[k]=2;
                    }
                }
                if(vis[b]==2)
                    ans[todo[i][4]]='S';
                while(sz(used))
                {
                    k=used.back();
                    used.pop_back();
                    grafo[k].resize(0);
                    vis[k]=0;
                }
                vis[a]=0;
            }
        }
    }
    return ans;
}
