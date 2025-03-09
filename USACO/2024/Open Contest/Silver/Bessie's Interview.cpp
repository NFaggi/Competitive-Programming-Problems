//Link: https://usaco.org/index.php?page=viewproblem2&cpid=1422
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
    ll n, k, i, pos,K;
    cin >> n >> K;
    vector<ll>t(n);
    forn(i,n)
        cin >> t[i];
    priority_queue<pair<ll,ll>>pq;
    forn(i,K)
        pq.push({-t[i],i});
    pos=K;
    vector<vector<ll>>ev;
    ll last, tim;
    while(pq.size())
    {
        ll nod=pq.top().se;
        ll cost=pq.top().fr;
        pq.pop();
        vector<ll>act={nod};
        while(cost==pq.top().fr)
        {
            act.pb(pq.top().se);
            pq.pop();
        }
        if(sz(act)>1)
            ev.pb(act);
        cost=-cost;
        if(sz(act)+pos>n)
        {
            last=nod;
            tim=cost;
            break;
        }
        for(auto k:act)
        {
            pq.push({-(cost+t[pos]),k});
            pos++;
        }
    }
    cout << tim << '\n';
    vector<bool>can(K,0);
    can[last]=1;
    for(i=sz(ev)-1; i>=0; i--)
    {
        bool enc=0;

        for(auto k:ev[i])
            if(can[k])
            {
                enc=1;
                break;
            }
        if(enc==0)
            continue;
        for(auto k:ev[i])
            can[k]=1;
    }
    for(auto k:can)
        cout << k;
    return 0;
}
