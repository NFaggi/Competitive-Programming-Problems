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
ll isprim[MAXN];
vector<ll>prims;

void calcPrim()
{
    ll i, j;
    for(i=2; i<MAXN; i++)
    {
        if(isprim[i])
            continue;
        prims.pb(i);
        for(j=i+i; j<MAXN; j+=i)
            isprim[j]=1;
    }
}

void solve()
{
    ll x, i;
    cin >> x;
    if(x<MAXN&&prims.back()>x)
    {
        for(i=0; i<sz(prims); i++)
        {
            if(x<prims[i])
            {
                cout << prims[i] << '\n';
                return;
            }
        }
    }
    else
    {
        x++;
        for(i=x; i<=x+5000; i++)
        {
            bool band=1;
            for(auto k:prims)
            {
                if(i%k==0)
                {
                    band=0;
                    break;
                }
            }
            if(band)
            {
                cout << i << '\n';
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calcPrim();
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
