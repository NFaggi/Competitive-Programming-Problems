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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll ans=30, n, k, x, i, j;
    string s;
    cin >> n >> k;
    vector<int>v(n);
    for(i=0; i<n; i++)
    {
        cin >> s;
        x=0;
        for(j=0; j<k; j++)
        {
            if(s[j]=='1')
            x|=1<<j;
        }
        v[i]=x;
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            ans=min(ans,__builtin_popcount(v[i]^v[j]));
        }
    }
    cout << ans;
    return 0;
}
    