//Link: https://juez.oia.unsam.edu.ar/task/79
//Score: 100/100
#include <bits/stdc++.h>
using namespace std;
pair<long long,long long> cal(vector<long long>v)
{
    long long i, n=v.size();
    vector<pair<long long, long long>>dp(n+1,{0,0});
    for(i=0; i<n; i++)
    {
        dp[i+1]={dp[i].first,dp[i].second+v[i]};
        if(i>0)
        {
            dp[i+1]=max(dp[i+1],{dp[i-1].first+v[i]*v[i-1],dp[i-1].second});
            cout << dp[i+1].first << ' ' << dp[i+1].second << '\n';
        }
    }
    return dp[n];
}
int main() {
    long long n, i, x, mul, sum;
    ifstream cin ("maxinum.in");
    ofstream cout ("maxinum.out");
    cin >> n;
    vector<long long>v, v2;

    for(i=0; i<n; i++)
    {
        cin >> x;
        if(i%2==0)
            v.push_back(x);
        else
           v2.push_back(x);
    }
    pair<long long, long long>p=cal(v);
    mul=p.first;
    sum=p.second;
    p=cal(v2);
    mul+=p.first;
    sum+=p.second;
    cout << mul << '\n' << sum << '\n';
    return 0;
}
