//Link: https://codeforces.com/contest/2050/problem/C
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

void solve()
{
    ll sum=0, tres=0, dos=0, n,aum, i, j;
    string s;
    cin >> s;
    n=s.size();
    for(i=0; i<n; i++)
    {
        sum=sum+(s[i]-'0');
        if(s[i]=='2')
            dos++;
        else if(s[i]=='3')
            tres++;
    }
    tres=min(8ll,tres);
    dos=min(8ll,dos);
    for(i=0; i<=tres; i++)
    {
        for(j=0; j<=dos; j++)
        {
            aum=i*6ll+j*2ll;
            if((sum+aum)%9ll==0)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
