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

const int MAXN=2001;

ll G[MAXN];
void precalc()
{
    ll j;
    for(ll i=3; i<MAXN; i++)
    {
        vector<ll>v;
        for(j=1; j<i; j++)
            if(j!=(i-j))
                v.pb(G[j]^G[i-j]);
        sort(all(v));
        v.erase(unique(all(v)),v.end());
        v.pb(sz(v)+1);
        for(j=0; j<sz(v); j++)
        {
            if(j!=v[j])
            {
                G[i]=j;
                break;
            }
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    if(n>=MAXN)
        cout << "first\n";
    else
        cout << ((G[n]>0)?"first":"second") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
