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

const int MAXN=1e5+1;

ll v[MAXN], n;

bool can(ll x)
{
    ll acum=0, i;
    for(i=0; i<n; i++)
    {
        acum+=v[i];
        acum-=x;
        if(acum<0)
            return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, mi=1, ma=1e9+1, piv, pos=0;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> v[i];

    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(piv))
        {
            pos=max(pos,piv);
            mi=piv+1;
        }
        else
            ma=piv-1;
    }
    cout << pos;
    return 0;
}
