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
    ll j=1, i, n, a, b, m, prio=0;
    cin >> n >> m;
    vector<ll> fin(n+1);
    vector<pair<ll,ll>> ans(m), grafo[n+1];
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        grafo[a].pb({b,i});
        grafo[b].pb({a,i});
    }
    vector<ll>v(n+1,0),v2(n+1,0);
    queue<ll>q;
    while(j<=n)
    {
        if(v[j]==0)
            q.push(j);
        prio++;
        v[j]=prio;
        j++;
        while(q.size())
        {
            ll nod=q.front();
            q.pop();
            v[nod]=1;
            for(auto k:grafo[nod])
            {
                if(v[k.fr]==1)
                {
                    if(v2[nod]>v2[k.fr])
                    {
                        ans[k.se]={nod,k.fr};
                    }
                    else
                    {
                        ans[k.se]={k.fr,nod};
                    }
                    continue;
                }
                if(v2[k.fr]==0)
                {
                    ans[k.se]={k.fr,nod};
                    prio++;
                    v2[k.fr]=prio;
                }
                q.push(k.fr);
                v[k.fr]=1;
            }
        }
    }
    for(auto k:ans)
        cout << k.fr << ' ' << k.se << '\n';
    return 0;
}
