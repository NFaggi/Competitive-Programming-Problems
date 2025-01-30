//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=1e5+1;
const int MOD=1e9+7;

vector<ll>comp[MAXN];
ll id[MAXN];

ll cant=0;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, i, a, b, c, in, beau, sum=0, s1, s2;

    cin >> n;
    for(i=1; i<=n; i++)
    {
        id[i]=i;
        comp[i]={i};
    }
    priority_queue<pair<ll,pair<ll,ll>>>pq;
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b >> c;
        pq.push({-c,{a,b}});
    }

    while(pq.size())
    {
        beau=-pq.top().first;
        a=pq.top().second.first;
        b=pq.top().second.second;
        pq.pop();
        a=id[a];
        b=id[b];
        s1=comp[a].size();
        s2=comp[b].size();
        sum=(sum+(((s1*s2)%MOD)*beau)%MOD)%MOD;
        if(s1<s2)
            swap(a,b);
        for(auto k:comp[b])
        {
            comp[a].push_back(k);
            id[k]=a;
        }
    }

    cout << sum;

    return 0;
}
