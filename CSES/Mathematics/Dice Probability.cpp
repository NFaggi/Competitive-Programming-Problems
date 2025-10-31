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
    ll n, a, b, i, j, k;
    double prob=double(1.0/6.0), tot=0, act;
    cin >> n >> a >> b;
    vector<vector<double>>v(n,vector<double>(n*6+1, 0));
    for(i=1; i<=6; i++)
        v[0][i]=prob;
    
    for(i=1; i<n; i++)
    {
        for(j=1; j<sz(v[i]); j++)
        {
            for(k=1; k<=6; k++)
            {
                if(j-k<=0)
                    break;
                v[i][j]+=v[i-1][j-k]*prob;
            }
        }
    }
    
    for(i=a; i<=b; i++)
        tot=tot+v[n-1][i];
    printf("%.6f",tot);
    return 0;
}
