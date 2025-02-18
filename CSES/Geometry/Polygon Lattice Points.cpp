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
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, lim=0, x, y, sig, area=0, interior;
    cin >> n;
    vector<ll>ptsX(n), ptsY(n);
    for(i=0; i<n; i++)
        cin >> ptsX[i] >> ptsY[i];
    for(i=0; i<n; i++)
    {
        sig=(i+1)%n;
        area+=ptsX[i]*ptsY[sig]-ptsY[i]*ptsX[sig];
        if(ptsX[i]==ptsX[sig])
        {
            lim+=abs(ptsY[i]-ptsY[sig]);
        }
        else if(ptsY[i]==ptsY[sig])
        {
            lim+=abs(ptsX[i]-ptsX[sig]);
        }
        else
        {
            x=abs(ptsX[i]-ptsX[sig]);
            y=abs(ptsY[i]-ptsY[sig]);
            lim+=gcd(x,y);
        }
    }
    area=abs(area);
    interior=(area+2-lim)/2;
    cout << interior << ' ' << lim;
    return 0;
}
