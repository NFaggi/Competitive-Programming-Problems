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
ll ag=1e9+1;
ll INF=ag*2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, a, b, maS=-INF, miS=INF, maR=-INF, miR=INF;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        maS=max(a+b,maS);
        miS=min(a+b,miS);
        miR=min(a-b,miR);
        maR=max(a-b,maR);
        cout << max(maS-miS,maR-miR) << '\n';
    }
    return 0;
}
