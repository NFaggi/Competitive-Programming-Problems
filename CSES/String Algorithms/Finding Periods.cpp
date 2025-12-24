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

const int MAXN=1e6+1;

ll z[MAXN];

void calcZ(string a)
{
    ll l=0, r=0, k;
    for(ll i=1; i<sz(a); i++)
    {
        k=i-l;
        if(i<=r)
            z[i]=min(r-i+1,z[k]);
        while(i+z[i]<sz(a)&&a[z[i]]==a[i+z[i]])
            z[i]++;
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    calcZ(s);
    ll n=sz(s);
    for(ll i=0; i<n; i++)
        if(z[i]==n-i)
             cout << n-z[i] << ' ';
    cout << n;
    return 0;
}
