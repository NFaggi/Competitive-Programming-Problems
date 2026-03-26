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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, j;
    cin >> n >> q;
    vector<ll> a(n), b(n), c(n), acum(2,0);
    vector<vector<ll>>p(2,vector<ll>(n)), pref(2,vector<ll>(n));
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<n; i++)
        cin >> b[i];
    
    for(i=0; i<n; i++)
        c[i]=a[i]-b[i];
    
    p[1][1]=p[0][0]=1;
    p[0][1]=p[1][0]=0;

    for(i=2; i<n; i++)
        for(j=0; j<2; j++)
            p[j][i]=-(p[j][i-2]-p[j][i-1]);
        
    for(i=0; i<n; i++)
        for(j=0; j<2; j++)
        {
            acum[j]+=p[j][i]*c[i];
            pref[j][i]=p[j][i];
            if(i>0)
                pref[j][i]+=pref[j][i-1];
        }
    
    cout << ((acum[0]==0&&acum[1]==0)?"YES":"NO") << '\n';


    ll l, r, x, act;
    while(q--)
    {
        cin >> l >> r >> x;
        l--;
        r--;
        for(i=0; i<2; i++)
        {
            act=pref[i][r];
            if(l>0)
                act-=pref[i][l-1];
            acum[i]+=(act*x);
        }
        cout << ((acum[0]==0&&acum[1]==0)?"YES":"NO") << '\n';
    }
    return 0;
}
