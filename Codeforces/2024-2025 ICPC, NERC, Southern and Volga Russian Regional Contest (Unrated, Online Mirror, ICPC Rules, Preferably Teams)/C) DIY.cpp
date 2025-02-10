//Link: https://codeforces.com/problemset/problem/2038/C
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
    ll n, i, x, x12, y13, y24, x34, ma=-1, a, b, act, band, j, k;
    cin >> n;
    vector<ll>v, pos;
    map<ll,ll>m;
    for(i=0; i<n; i++)
    {
        cin >> x;
        if(m[x])
        {
            m[x]=0;
            v.push_back(x);
        }
        else
            m[x]++;
    }
    sort(v.begin(),v.end());
    if(sz(v)<4)
    {
        cout << "NO\n";
        return;
    }
    pos.pb(v[0]);
    pos.pb(v[1]);
    pos.pb(v[sz(v)-2]);
    pos.pb(v[sz(v)-1]);
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(j==i)
                continue;
            act=abs(pos[i]-pos[j]);
            band=1;
            for(k=0; k<4; k++)
            {
                if(k!=i&&k!=j&&band==1)
                {
                    a=k;
                    band=0;
                }
                else if(k!=i&&k!=j)
                    b=k;
            }
            act*=abs(pos[a]-pos[b]);
            if(ma<act)
            {
                ma=act;
                x12=i;
                x34=j;
                y13=a;
                y24=b;
            }
        }
    }
    cout << "YES\n";
    cout << pos[x12] << ' ' << pos[y13] << ' ' << pos[x12] << ' ' << pos[y24] << ' ' << pos[x34] << ' ' << pos[y13] << ' ' << pos[x34] << ' ' << pos[y24] << '\n';

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

