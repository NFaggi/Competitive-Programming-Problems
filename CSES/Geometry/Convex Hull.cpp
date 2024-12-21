#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
using namespace std;
struct Punto
{
    ll x, y;
};
bool comp(const Punto &a, const Punto &b)
{
    if(a.y!=b.y)
        return a.y<b.y;
    return a.x<b.x;
}
ll valid(const Punto &a, const Punto &b, const Punto &c)
{
    return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

int main()
{
    ll n, i;
    cin >> n;
    vector<Punto>v(n);
    for(i=0; i<n; i++)
        cin >> v[i].x >> v[i].y;
    sort(all(v),comp);
    vector<Punto>s,s2;
    set<pair<ll,ll>> se;
    vector<Punto> ans;
    for(i=0; i<n; i++)
    {
        while(sz(s)>1&&valid(s[sz(s)-2],s[sz(s)-1],v[i])>0ll)s.pop_back();
        s.push_back(v[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        while(sz(s2)>1&&valid(s2[sz(s2)-2],s2[sz(s2)-1],v[i])>0ll)s2.pop_back();
        s2.push_back(v[i]);
    }

    pair<ll,ll>p;
    for (auto j : s)
    {
        p={j.x,j.y};
        if (!se.count(p))
        {
            ans.push_back(j);
            se.insert(p);
        }
    }
    for (auto j : s2)
    {
        p={j.x,j.y};
        if (!se.count(p))
        {
            ans.push_back(j);
            se.insert(p);
        }
    }

    cout << sz(ans) << '\n';
    for (auto j : ans)
        cout << j.x << ' ' << j.y << '\n';
    return 0;
}
