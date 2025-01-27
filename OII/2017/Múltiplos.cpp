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


const int MAXN=5e4+1;
const int MAXM=101;

ll cants[MAXN][MAXM];

ll gauss(ll n)
{
    return (n*(n+1ll))/2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, l, r, m, ans, ant, j, cant;
    cin >> n >> m >> q;
    vector<ll>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        v[i]=v[i]%m;
        if(i>0)
        {
            v[i]=(v[i]+v[i-1])%m;
            for(j=0; j<m; j++)
                cants[i][j]=cants[i-1][j];
        }
        cants[i][v[i]]++;
    }
    while(q--)
    {
        ans=0;
        cin >> l >> r;
        l--;
        r--;
        for(j=0; j<m; j++)
        {
            cant=cants[r][j];
            if(l>1)
                cant-=cants[l-2][j];
            if(l==0&&j==0)
                cant++;
            cant--;
            if(cant>0)
                ans+=gauss(cant);
        }

        cout << ans << '\n';
    }
    return 0;
}
