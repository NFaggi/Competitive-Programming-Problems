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

ll calc(ll n, ll k, ll par)
{
    if(n==1)
        return 1;
    ll cant;
    if(par==0)
        cant=n/2;
    else
        cant=(n+1)/2;
    if(cant>=k)
    {
        if(par==0)
        {
            return k*2;
        }
        else
        {
            return k*2-1;
        }
    }
    ll ret=calc(n-cant,k-cant,(n+par)%2);
    if(par==0)
    {
        return ret*2-1;
    }
    return ret*2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, n, k;
    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        cout << calc(n,k,0) << '\n';
    }
    return 0;
}
