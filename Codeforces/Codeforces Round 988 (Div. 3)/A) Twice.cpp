//Link: https://codeforces.com/contest/2037/problem/A
#include<bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
using namespace std;
void solve()
{
    ll n, i, punt=0, j;
    cin >> n;
    vector<ll>v(n),vis(n,0);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        vis[i]=0;
    }
    for(i=0; i<n; i++)
    {
        if(vis[i]==1)
            continue;
        for(j=i+1; j<n; j++)
        {
            if(vis[j]==1)
                continue;
            if(v[j]==v[i])
            {
                vis[i]=1;
                vis[j]=1;
                 punt++;
                break;
               
            }
        }
    }
    cout << punt << '\n';

}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
