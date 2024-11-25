//Link: https://codeforces.com/gym/104597/problem/B
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t, n,mi,i,x,cant;
    cin >> t;
    while(t--)
    {
        cin >> n;
        mi=LLONG_MAX;
        cant=0;
        priority_queue<ll>pq;
        for(i=0; i<n; i++)
        {
            cin >> x;
            pq.push(x);
            mi=min(mi,x);
        }
        while(pq.top()!=mi)
        {
            cant++;
            x=pq.top();
            pq.pop();
            x=x-(x+1)/2;
            mi=min(mi,x);
            pq.push(x);
        }
        cout << cant << '\n';
    }
    return 0;
}