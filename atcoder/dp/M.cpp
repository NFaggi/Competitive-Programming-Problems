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

const int MOD=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, x, a, j, k;
    cin >> n >> x;
    vector<ll>v(x+1,0), nv, aum;
    v[0]=1;
    for(i=0; i<n; i++)
    {
        cin >> a;
        nv=v;
        aum.resize(0);
        aum.resize(x+1,0);
        for(j=0; j<=x; j++)
        {
            if(j>0)
                aum[j]=(aum[j]+aum[j-1])%MOD;
            aum[j+1]=(aum[j+1]+nv[j])%MOD;
            if(j+a+1<=x)
            {
                aum[j+a+1]=(aum[j+a+1]-nv[j])%MOD;
                if(aum[j+a+1]<0)
                    aum[j+a+1]+=MOD;
            }
            v[j]=(v[j]+aum[j])%MOD;
        }
    }
    cout << v[x];
    return 0;
}
