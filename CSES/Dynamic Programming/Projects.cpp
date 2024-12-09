#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, a, b, c,ma=0, i;
    cin >> n;
    priority_queue<vector<ll>>pq,pq2;
    vector<ll>v(3);
    for(i=0; i<n; i++)
    {
        cin >> v[0] >> v[1] >> v[2];
        v[0]*=-1;
        v[1]*=-1;
        pq.push(v);
    }
    while(!pq.empty())
    {
        v=pq.top();
        pq.pop();
        v[0]*=-1;
        v[1]*=-1;
        while(!pq2.empty()&&(pq2.top()[0]*-1)<v[0])
        {
            ma=max(pq2.top()[1],ma);
            pq2.pop();
        }
        v[0]=v[1]*-1;
        v[1]=v[2]+ma;
        pq2.push(v);
    }
    while(!pq2.empty())
    {
        ma=max(pq2.top()[1],ma);
        pq2.pop();
    }
    cout << ma;
    return 0;
}
