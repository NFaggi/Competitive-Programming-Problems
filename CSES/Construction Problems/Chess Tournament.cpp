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
    ll n, i, x;
    cin >> n;
    set<pair<ll,ll>>s,del;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        if(x)
            s.insert({x,i});
    }
    pair<ll,ll>p, p2;
    vector<pair<ll,ll>>ans;
    while(sz(s))
    {
        auto it=prev(s.end());
        p=*it;
        s.erase(it);
        if(sz(s)<p.fr)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        while(p.fr)
        {
            p.fr--;
            it=prev(s.end());
            p2=*it;
            ans.pb({p2.se,p.se});
            s.erase(it);
            p2.fr--;
            if(p2.fr)
                del.insert(p2);
        }
        while(sz(del))
        {
            it=prev(del.end());
            p2=*it;
            del.erase(it);
            s.insert(p2);
        }
    }
    cout << sz(ans) << '\n';
    for(auto k:ans)
        cout << k.fr << ' ' << k.se << '\n';
    return 0;
}
