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

vector<ll>ans;

bool query(ll a, ll b)
{
    string x;
    cout << "? " << a << ' ' << b << endl;
    cin >> x;
    if(x[0]=='Y')
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, mi, ma, piv, pos, i, j;
    cin >> n;
    ans.pb(1);
    for(i=2; i<=n; i++)
    {
        mi=0;
        ma=sz(ans)-1;
        pos=-1;
        while(mi<=ma)
        {
            piv=(mi+ma)/2;
            if(query(ans[piv],i))
            {
                pos=max(pos,piv);
                mi=piv+1;
            }
            else
                ma=piv-1;
        }
        vector<ll>v;
        for(j=0; j<sz(ans); j++)
        {
            if(j-1==pos)
                v.pb(i);
            v.pb(ans[j]);
        }
        if(pos==sz(ans)-1)
            v.pb(i);
        ans=v;
    }
    vector<ll>res(n);
    ll num=1;
    for(auto k:ans)
        res[k-1]=num++;
    cout << "! ";
    for(i=0; i<sz(res); i++)
    {
        cout << res[i];
        if(i+1<sz(res))
            cout << ' ';
    }
    cout << endl;
    return 0;
}
