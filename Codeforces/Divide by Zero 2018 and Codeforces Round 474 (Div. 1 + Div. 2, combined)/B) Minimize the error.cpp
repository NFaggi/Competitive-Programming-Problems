//Link: https://codeforces.com/contest/960/problem/B
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
    ll n, k1, k2, i, sum=0;
    cin >> n >> k1 >> k2;
    vector<ll>a(n),b(n);
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<n; i++)
        cin >> b[i];
    priority_queue<pair<ll,ll>>pq;
    for(i=0; i<n; i++)
        pq.push({abs(a[i]-b[i]),i});

    while(sz(pq)&&(k1!=0||k2!=0))
    {
        i=pq.top().se;
        pq.pop();
        if(k1)
        {
            k1--;
            if(a[i]<=b[i])
                a[i]++;
            else
                a[i]--;
            pq.push({abs(a[i]-b[i]),i});
        }
        else
        {
            k2--;
            if(b[i]<=a[i])
                b[i]++;
            else
                b[i]--;
            pq.push({abs(a[i]-b[i]),i});
        }
    }
    for(i=0; i<n; i++)
        sum=sum+(a[i]-b[i])*(a[i]-b[i]);
    cout << sum;
    return 0;
}
