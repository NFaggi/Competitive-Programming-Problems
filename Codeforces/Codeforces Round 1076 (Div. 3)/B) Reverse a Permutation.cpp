//Link: https://codeforces.com/contest/2193/problem/B
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

void solve()
{
    ll n, i, ma, j;
    cin >> n;
    ma=n;
    vector<ll>v(n),ans;
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=0; i<n; i++)
    {
        if(v[i]==ma)
        {
            ma--;
            ans.pb(v[i]);
        }
        else
        {
            for(j=i; j<n; j++)
                if(v[j]==ma)
                    break;
            ll aux=j;
            while(j>=i)
            {
                ans.pb(v[j]);
                j--;
            }
            for(j=aux+1; j<n; j++)
                ans.pb(v[j]);
            break;
        }
    }
    for(auto k:ans)
        cout << k << ' ';
    cout << '\n';
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
