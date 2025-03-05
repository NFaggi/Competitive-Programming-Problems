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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, opp=0, same=0;
    cin >> n;
    vector<ll>v(n*2);
    for(i=0; i<n*2; i++)
        cin >> v[i];
    for(i=0; i<n; i++)
    {
        same+=abs(v[i]+v[i+n]);
        opp+=abs(v[i]-v[i+n]);
    }
    cout << max(same,opp);
    return 0;
}
