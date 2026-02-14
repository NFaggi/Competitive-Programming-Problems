//Link: https://codeforces.com/contest/2193/problem/F
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

ll INF=1e9+1;

void solve()
{
    ll n, i, j, ax, ay, bx, by, topx, topy, botx, boty, actx, dT, dB;
    cin >> n >> ax >> ay >> bx >> by;
    vector<ll>x(n),y(n);
    vector<pair<ll,ll>>cords;
    for(i=0; i<n; i++)
        cin >> x[i];
    for(i=0; i<n; i++)
        cin >> y[i];
    for(i=0; i<n; i++)
        cords.pb({x[i],y[i]});
    sort(all(cords));
    i=0;
    vector<ll>miTop={0,ax,ay},miBot={0,ax,ay}, actT, actB;
    while(i<sz(cords))
    {
        botx=boty=INF;
        topx=topy=0;
        actx=cords[i].fr;
        while(i<sz(cords)&&cords[i].fr==actx)
        {
            if(cords[i].se>topy)
            {
                topx=cords[i].fr;
                topy=cords[i].se;
            }
            if(cords[i].se<boty)
            {
                botx=cords[i].fr;
                boty=cords[i].se;
            }
            i++;
        }
        dT=abs(miTop[1]-topx)+abs(miTop[2]-topy), dB=abs(miBot[1]-topx)+abs(miBot[2]-topy);
        actB={min(miTop[0]+dT,miBot[0]+dB)+abs(botx-topx)+abs(boty-topy),botx,boty};
        dT=abs(miTop[1]-botx)+abs(miTop[2]-boty), dB=abs(miBot[1]-botx)+abs(miBot[2]-boty);
        actT={min(miTop[0]+dT,miBot[0]+dB)+abs(botx-topx)+abs(boty-topy),topx,topy};
        miTop=actT;
        miBot=actB;
    }
    dT=abs(miTop[1]-bx)+abs(miTop[2]-by), dB=abs(miBot[1]-bx)+abs(miBot[2]-by);
    ll ans=min(miTop[0]+dT,miBot[0]+dB);
    cout << ans << '\n';
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
