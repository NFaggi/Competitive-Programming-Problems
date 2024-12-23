//Link: https://codeforces.com/problemset/problem/1851/E
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
    ll n, k,x,i,m,j;
    cin >> n >> k;
    vector<vector<ll>>grafo(n);
    vector<ll>c(n);
    vector<bool>proc(n,0);
    vector<ll>calc(n,0);
    for(i=0; i<n; i++)
    {
        cin >> c[i];
    }
    for(i=0; i<k; i++)
    {
        cin >> x;
        x--;
        c[x]=0;
    }
    vector<ll>id(n,0);
    for(i=0; i<n; i++)
    {
        cin >> m;
        if(c[i]==0ll)
        {
            for(j=0; j<m; j++)
            {
                cin >> x;
            }
            m=0;
        }
        id[i]=m;
        for(j=0; j<m; j++)
        {
            cin >> x;
            x--;
            grafo[x].pb(i);
        }
    }
    queue<ll>q;
    for(i=0; i<n; i++)
    {
        if(id[i]==0)
            q.push(i);
    }
    while(sz(q))
    {
        i=q.front();
        q.pop();
        if(proc[i])
            c[i]=min(c[i],calc[i]);
        for(auto k:grafo[i])
        {
            proc[k]=1;
            calc[k]+=c[i];
            id[k]--;
            if(id[k]==0)
                q.push(k);
        }
    }
    for(i=0; i<n; i++)
    {
        cout << c[i] << ' ';
    }
    cout << '\n';
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
