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
const int MOD=1e9+7;

vector<vector<ll>>A;

vector<vector<ll>>mul(vector<vector<ll>>&a,vector<vector<ll>>&b)
{
    vector<vector<ll>>ret(sz(a),vector<ll>(sz(b[0]),0));
    ll i, j, k;
    for(i=0; i<sz(a); i++)
    {
        for(j=0; j<sz(b[0]); j++)
        {
            for(k=0; k<sz(a); k++)
            {
                ret[i][j]=(ret[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }
    return ret;
}

vector<vector<ll>> binpow(ll x)
{
    if(x==1)
        return A;
    vector<vector<ll>>ans=binpow(x/2);
    ans=mul(ans,ans);
    if(x%2!=0)
        ans=mul(ans,A);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, i, a, b;
    cin >> n >> m >> k;
    A.resize(n,vector<ll>(n,0));
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        A[a][b]++;
    }

    vector<vector<ll>>ans=binpow(k);

    cout << ans[0][n-1];
    return 0;
}
