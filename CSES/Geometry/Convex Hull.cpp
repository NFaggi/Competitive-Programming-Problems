#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
using namespace std;
bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second>b.second;
}
ll valid(const pair<ll,ll> &a, const pair<ll,ll> &b, const pair<ll,ll> &c)
{
    return (a.first - b.first) * (c.second - b.second) - (a.second - b.second) * (c.first - b.first);
}
 
int main()
{
    ll n, i;
    cin >> n;
    vector<pair<ll,ll>>v(n);
    for(i=0; i<n; i++)
        cin >> v[i].first >> v[i].second;
    sort(all(v),comp);
    vector<pair<ll,ll>>s,s2;
    set<pair<ll,ll>> se;
    vector<pair<ll,ll>> ans;
    for(i=0; i<n; i++)
    {
        while(sz(s)>1&&valid(s[sz(s)-2],s.back(),v[i])>0ll)s.pop_back();
        s.push_back(v[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        while(sz(s2)>1&&valid(s2[sz(s2)-2],s2.back(),v[i])>0ll)s2.pop_back();
        s2.push_back(v[i]);
    }
 
    for (auto j : s)
    {
        if (!se.count(j))
        {
            ans.push_back(j);
            se.insert(j);
        }
    }
    for (auto j : s2)
    {
        if (!se.count(j))
        {
            ans.push_back(j);
            se.insert(j);
        }
    }
 
    cout << sz(ans) << '\n';
    for (auto j : ans)
        cout << j.first << ' ' << j.second << '\n';
    return 0;
}
