//Link: https://codeforces.com/gym/105668/problem/F
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

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    ll cA1=0, cA2=0, cost=0, dist, i, jp, ji, us=0;
    for(auto k:s1)
        if(k=='A')
            cA1++;
    for(auto k:s2)
        if(k=='A')
            cA2++;
    if(cA1!=cA2)
    {
        cout << -1 << '\n';
        return;
    }
    jp=0;
    ji=1;
    for(i=0; i<sz(s1); i++)
    {
        if(s1[i]=='A')
            continue;
        us=0;
        if(i%2==0)
        {
            for(jp; jp<sz(s2); jp+=2)
            {
                if(s2[jp]=='B')
                {
                    us=1;
                    cost+=abs(i-jp)/2;
                    jp+=2;
                    break;
                }
            }
            if(!us)
            {
                cout << -1 << '\n';
                return;
            }
        }
        else
        {
            for(ji; ji<sz(s2); ji+=2)
            {
                if(s2[ji]=='B')
                {
                    us=1;
                    cost+=abs(i-ji)/2;
                    ji+=2;
                    break;
                }
            }
            if(!us)
            {
                cout << -1 << '\n';
                return;
            }
        }
    }

    cout << cost << '\n';
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
