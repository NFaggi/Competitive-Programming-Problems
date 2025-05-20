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
    ll n, k, i;
    cin >> n >> k;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    map<ll,ll>m;
    set<pair<ll,ll>>s;
    for(i=0; i<k; i++)
    {
        if(m[v[i]]>0)
        {
            auto it=s.find({m[v[i]],-v[i]});
            s.erase(it);
        }
        m[v[i]]++;
        s.insert({m[v[i]],-v[i]});
    }
    auto it=prev(s.end());
    cout << -it->second << ' ';
    for(i=k; i<n; i++)
    {
        it =s.find({m[v[i-k]],-v[i-k]});
        s.erase(it);
        m[v[i-k]]--;
        if(m[v[i-k]]>0)
            s.insert({m[v[i-k]],-v[i-k]});
        if(m[v[i]]>0)
        {
            it=s.find({m[v[i]],-v[i]});
            s.erase(it);
        }
        m[v[i]]++;
        s.insert({m[v[i]],-v[i]});
        it=prev(s.end());
        cout << -it->second << ' ';
    }
    return 0;
}
