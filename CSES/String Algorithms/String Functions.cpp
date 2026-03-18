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

ll z[MAXN], lps[MAXN];

void calcZ(string &s)
{
    ll i, l=0, r=0, n=sz(s);

    for(i=1; i<n; i++)
    {
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        
        while(i+z[i]<sz(s)&&s[i+z[i]]==s[z[i]])
            z[i]++;
        
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
}

void calcLPS(string &s)
{
    ll i, n=sz(s), len=0;

    for(i=1; i<n; i++)
    {
        while(len>0&&s[i]!=s[len])
            len=lps[len-1];
        
        if(s[i]==s[len])
            len++;
        lps[i]=len;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i;
    string s;
    cin >> s;
    n=sz(s);
    calcZ(s);
    calcLPS(s);
    for(i=0; i<n; i++)
        cout << z[i] << ' ';
    cout << '\n';

    for(i=0; i<n; i++)
        cout << lps[i] << ' ';
    return 0;
}
