#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN = 1e5 + 1;
const int LOG = 17;

ll up[MAXN][LOG], sum[MAXN][LOG];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, j, a, b, cost;
    cin >> n >> q;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];

    stack<pair<ll, ll>> Q;
    Q.push({LLONG_MAX, n});
    for (i = 0; i < LOG; i++)
        up[n][i] = n;
    
    for(i=n-1; i>=0; i--)
    {
        while(Q.top().fr<=v[i])
            Q.pop();
        up[i][0]=Q.top().se;
        sum[i][0]=1;
        for(j=1; j<LOG; j++)
        {
            up[i][j]=up[up[i][j-1]][j-1];
            sum[i][j]=sum[i][j-1]+sum[up[i][j-1]][j-1];
        }
        Q.push({v[i],i});
    }
    while(q--)
    {
        cin >> a >> b;
        a--;
        b--;
        cost=0;
        for(i=LOG-1; i>=0; i--)
        {
            if(up[a][i]<=b)
            {
                cost+=sum[a][i];
                a=up[a][i];
            }
        }
        cout << cost+1 << '\n';
    }
    return 0;
}
