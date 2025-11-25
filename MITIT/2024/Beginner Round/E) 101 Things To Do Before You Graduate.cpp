#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, i, ma = -1, lim = 0, x, y, cant=0;
    cin >> n >> k;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];

    multiset<ll> s;
    s.insert(v[0]);
    map<ll,ll>ub;
    priority_queue<pair<ll,ll>>pq;
    ub[v[0]]=0;
    for (i = 1; i < n; i++)
    {
        
        if (sz(s))
        {
            
            auto f = [&]()
            {
                if(sz(s))
                {
                    auto it = s.upper_bound(v[i]);
                    if (it != s.begin())
                    {
                        auto it2 = prev(it);
                        y = *it2;
                    }
                    else
                        y = *it;
                    if (it != s.end())
                        x = *it;
                    else
                        x = y;
                }
            };
            f();
            while (sz(s) && ((x ^ v[i]) < k || (y ^ v[i]) < k))
            {
                auto it = s.find(v[lim]);
                s.erase(it);
        
                f();
                lim++;
            }
            if(sz(s))
            {
                auto it = s.upper_bound(v[i]);
                ll mi=LLONG_MAX;
                if(it!=s.end())
                {
                    x=((*it)^v[i]);
                    if(x==k)
                        ma=max(ma,ub[*it]);
                }
                if(it!=s.begin())
                {
                    it=prev(it);
                    x=((*it)^v[i]);
                    if(x==k)
                        ma=max(ma,ub[*it]);
                }
            }
            s.insert(v[i]);
        }
        else
            s.insert(v[i]);
        if(ma>=lim)
            cant=(cant+(ma-lim+1));
        ub[v[i]]=i;
    }
    cout << cant;
    return 0;
}
