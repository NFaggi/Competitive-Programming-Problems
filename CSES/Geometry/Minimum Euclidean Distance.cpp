#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}
ll dist (pair<ll,ll> a, pair<ll,ll> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i, j=0;
    ll d, dis;
    cin >> n;
    vector<pair<ll,ll>>v(n);
    pair<ll,ll>p;
    for(i=0; i<n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    set<pair<ll,ll>,bool(*)(pair<ll, ll>, pair<ll, ll>)>s(cmp);
 
    dis=dist(v[0],v[1]);
 
    for(i=0; i<n; i++)
    {
        d=(ll)ceil(sqrt(dis));
        p= {v[i].first,v[i].second-d};
        while(j<int(v.size())&&v[i].first-v[j].first>d)
        {
            auto it2=s.find(v[j]);
            if(it2!=s.end())
                s.erase(it2);
            j++;
        }
        auto it=s.lower_bound(p);
        while(it!=s.end()&&abs(v[i].second-(it->second))<=d)
        {
            dis=min(dis,dist(v[i],*it));
            it++;
        }
        s.insert(v[i]);
    }
    cout << dis;
    return 0;
}
