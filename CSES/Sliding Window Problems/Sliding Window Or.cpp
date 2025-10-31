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
    ios::sync_with_stdio(false);cin.tie(nullptr);
    ll n, k, x, a, b, c, i, j, sa=0, sp=0, ans=0, val;
    cin >> n >> k >> x >> a >> b >> c;
    vector<ll>v(n);
    v[0]=x;
    for(i=1; i<n; i++)
    {
        val=1ll*(v[i-1]*a+b)%c;
        v[i]=val;
    }

    vector<ll>pref(n,0),suf(n,0);
    
    for(i=0; i<n; i++)
    {
        if(i%k!=0)
            pref[i]|=pref[i-1];
        pref[i]|=v[i];
    }

    for(i=n-1; i>=0; i--)
    {
        if((i+1)%k!=0&&i+1<n)
            suf[i]|=suf[i+1];
        suf[i]|=v[i];
    }
    for(i=0; i<n-k+1; i++)
    {
        if(i%k==0)
            ans=ans^suf[i];
        else
        {
            val=suf[i]|pref[i+k-1];
            ans=ans^val;
        }
    }
    cout << ans;
    return 0;
}
