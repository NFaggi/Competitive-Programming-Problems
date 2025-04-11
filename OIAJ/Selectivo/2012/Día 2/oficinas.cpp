//Link: https://juez.oia.unsam.edu.ar/task/92
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

const int MAXN=251;

ll INF=1e9+7;
ll dp[MAXN][MAXN], sum[MAXN][MAXN], ant[MAXN][MAXN];
vector<pair<ll,ll>>v;
void dfs(ll nod, ll l, ll r)
{
    if(nod==-1)
        return;
    cout << '(';
    dfs(ant[l][nod],l,nod);
    cout << v[nod].fr;
    dfs(ant[nod+1][r],nod+1,r);
    cout << ')';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("oficinas.in","r",stdin);
    freopen("oficinas.out","w",stdout);
    ll n, i, mi, act, l, r, mid, ind, j;
    cin >> n;
    v.resize(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i].fr >> v[i].se;
    }
    sort(all(v));
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            ant[i][j]=-1;
            if(j==i)
                continue;
            dp[i][j]=INF;   
        }
    }
    for(i=0; i<n; i++)
    {
        dp[i][i+1]=v[i].se;
        sum[i][i+1]=v[i].se;
        ant[i][i+1]=i;
    }    
    for(i=2; i<=n; i++)
    {
        for(j=0; j<=n-i; j++)
        {
            l=j;
            r=j+i;
            mi=INF;
            ind=0;
            for(mid=l; mid<r; mid++)
            {
                if(dp[l][mid]+dp[mid+1][r]<mi)
                {
                    mi=dp[l][mid]+dp[mid+1][r];
                    ind=mid;
                }
            }
            act=v[ind].se+sum[l][ind]+sum[ind+1][r];
            dp[l][r]=act+dp[l][ind]+dp[ind+1][r];
            sum[l][r]=act;
            ant[l][r]=ind;
        }
    }
    cout << dp[0][n] << '\n';
    dfs(ant[0][n],0,n);
    return 0;
}