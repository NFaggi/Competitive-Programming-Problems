#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long i, n;
    long long a=0, b=0, res;
    cin >> n;
    vector<pair<long long, long long>>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for(i=0; i<n; i++)
    {
        if(i+1<n)
        {
            a+=v[i].first*v[i+1].second;
            b+=v[i].second*v[i+1].first;
        }
        else
        {
            a+=v[i].first*v[0].second;
            b+=v[i].second*v[0].first;
        }
    }
    res=abs(a-b);
    cout << res;
    return 0;
}