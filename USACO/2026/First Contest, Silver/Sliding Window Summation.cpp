//Link: https://usaco.org/index.php?page=viewproblem2&cpid=1544
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

const int MAXN=1e6+1;

ll cant[MAXN][2], ult[MAXN], INF=LLONG_MAX;
void solve()
{
    ll n, k, i, ax, x, ix, unos=0, mod=0, mi=INF;
    string s;
    cin >> n >> k >> s;
    ix=s[0]-'0';
    ax=ix;
    for(i=0; i<k; i++)
    {
        cant[i][0]=1;
        cant[i][1]=0;
        ult[i]=0;
    }
    for(i=1; i<n-k+1; i++)
    {
        x=s[i]-'0';
        ult[(i-1)%k]=((x!=ax)+ult[(i-1)%k])%2;
        cant[(i-1)%k][ult[(i-1)%k]]++;
        ax=x;
    }
    for(i=0; i<k; i++)
    {
        if(cant[i][0]>=cant[i][1])
        {
            unos+=cant[i][0];
            mod=(mod+1)%2;
        }
        else
            unos+=cant[i][1];
        mi=min(mi,abs(cant[i][0]-cant[i][1]));
    }
    ll ma1, ma0;
    if(mod==ix)
        ma1=unos;
    else
        ma1=unos-mi;
    ix=(ix+(k%2))%2;
    if(mod==ix)
        ma0=unos;
    else
        ma0=unos-mi;
    cout << n-ma0 << ' ' << ma1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
