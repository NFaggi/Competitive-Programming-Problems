//Link: https://www.spoj.com/problems/TOPOSORT/
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

const int MAXN=1e4+1;

vector<ll>grafo[MAXN];

ll id[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, a, b;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        id[b]++;
    }
    priority_queue<ll>q;
    vector<ll>ord;
    for(i=1; i<=n; i++)
    {
        if(id[i]==0)
            q.push(-i);
    }
    while(q.size())
    {
        ll nod=-q.top();
        q.pop();
        ord.pb(nod);
        for(auto k:grafo[nod])
        {
            id[k]--;
            if(id[k]==0)
                q.push(-k);
        }
    }
    for(i=1; i<=n; i++)
    {
        if(id[i]>0)
        {
            cout << "Sandro fails.";
            return 0;
        }
    }
    for(auto k:ord)
    {
        cout << k << ' ';
    }
    return 0;
}
