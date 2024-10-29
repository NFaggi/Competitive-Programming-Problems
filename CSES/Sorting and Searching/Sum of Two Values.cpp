#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i;
    ll x, falt;
    cin >> n >> x;
    vector<ll>v(n);
    set<pair<ll,ll>>s;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        s.insert({v[i],i});
    }
    for(i=0; i<n; i++)
    {
        falt=x-v[i];
        auto it=s.lower_bound({falt,0});
        if(it->second==i)
            it++;
        if(it!=s.end()&&it->first==falt)
        {
            cout << i+1 << ' ' << it->second+1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
