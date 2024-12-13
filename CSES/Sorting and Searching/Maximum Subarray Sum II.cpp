#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b,sum=0, i,ma=-LLONG_MAX;
    cin >> n >> a >> b;
    vector<ll>v(n),dp(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    set<pair<ll,ll>>s;
    queue<pair<ll,ll>>pq;
    for(i=0; i<n; i++)
    {
        dp[i]=sum;
        pq.push({i,sum});
        if(pq.size()&&pq.front().first==i-(a-1))
        {
            s.insert({pq.front().second,pq.front().first});
            pq.pop();
        }
        if(i-b>=0)
        {
            auto it= s.find(make_pair(dp[i-b],i-b));
            if(it!=s.end())
                s.erase(it);
        }
        if(s.size())
        {
            auto it2=s.begin();
            ma=max(ma,v[i]+sum-(it2->first));
        }
        sum+=v[i];
    }
    cout << ma;
    return 0;
}
