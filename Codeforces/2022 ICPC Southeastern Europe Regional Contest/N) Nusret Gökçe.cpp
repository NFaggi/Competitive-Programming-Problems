#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, i;
    long long k, cost=0;
    cin >> n >> k;
    vector<long long>v(n);
    priority_queue<pair<long long, long long>>pq;
    vector<long long>proc(n,0);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        pq.push({v[i],i});
    }
    while(pq.size())
    {
        long long pos=pq.top().second;
        pq.pop();
        if(proc[pos])
        {
            continue;
        }
        proc[pos]=1;
        if(pos-1>=0&&v[pos]-v[pos-1]>k)
        {
            v[pos-1]=v[pos]-k;
            pq.push({v[pos-1],pos-1});
        }
        if(pos+1<n&&v[pos]-v[pos+1]>k)
        {
            v[pos+1]=v[pos]-k;
            pq.push({v[pos+1],pos+1});
        }
    }
    for(i=0; i<n; i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}