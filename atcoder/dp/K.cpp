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
    ll n, k, i, j;
    cin >> k >> n;
    vector<ll>v(n+1,0),p(k);
    for(i=0; i<k; i++)
        cin >> p[i];
    for(i=1; i<=n; i++)
    {
        for(j=0; j<k; j++)
        {
            if(i-p[j]<0)
                continue;
            if(v[i-p[j]]==0)
            {
                v[i]=1;
                break;
            }
        }
    }
    if(v[n])
        cout << "First";
    else
        cout << "Second";
    return 0;
}
