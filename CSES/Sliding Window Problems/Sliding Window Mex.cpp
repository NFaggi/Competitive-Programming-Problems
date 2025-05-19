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
    set<ll>s;
    for(i=0; i<=n; i++)
        s.insert(i);
    for(i=0; i<k; i++)
    {
        if(m[v[i]]==0)
        {
            auto it=s.find(v[i]);
            if(it!=s.end())
                s.erase(it);
        }
        m[v[i]]++;
    }
    cout << *s.begin() << ' ';
    for(i=k; i<n; i++)
    {
        m[v[i-k]]--;
        if(m[v[i-k]]==0)
            s.insert(v[i-k]);
        if(m[v[i]]==0)
        {
            auto it=s.find(v[i]);
            if(it!=s.end())
                s.erase(it);
        }
        m[v[i]]++;
        cout << *s.begin() << ' ';
    }
    return 0;
}
