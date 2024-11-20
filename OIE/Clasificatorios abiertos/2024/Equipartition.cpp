//Link: https://codeforces.com/gym/105003/problem/C
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, i, x, y, ci=0, cj=0, V,tot=0, ag=1e9,s1=0,s2=0,s3=0,s4=0;
        cin >> n;
        vector<pair<ll,pair<ll,ll>>>v(n);
        vector<ll>dp(n,0);
        for(i=0; i<n; i++)
        {
            cin >> x >> y >> V;
            v[i]= {x,{y,V}};
            tot+=V;
        }
        sort(v.begin(),v.end());
        for(i=0; i<n; i++)
        {
            dp[i]=v[i].second.second;
            swap(v[i].first,v[i].second.first);
            if(i>0)
            {
                dp[i]+=dp[i-1];
            }
        }
        for(i=0; i<n-1; i++)
        {
            ci=(v[i+1].second.first+ag)-(v[i].second.first+ag);
            if(dp[i]==tot-dp[i])
            {
                x=v[i].second.first;
                break;
            }
            else
            {
                ci=0;
            }
        }
        sort(v.begin(),v.end());
        for(i=0; i<n; i++)
        {
            dp[i]=v[i].second.second;
            if(i>0)
            {
                dp[i]+=dp[i-1];
            }
        }
        for(i=0; i<n-1; i++)
        {
            cj=(v[i+1].first+ag)-(v[i].first+ag);
            if(dp[i]==tot-dp[i])
            {
                y=v[i].first;
                break;
            }
            else
            {
                cj=0;
            }
        }
        for(i=0; i<n; i++)
        {
            if(v[i].first<=y&&v[i].second.first<=x)
            {
                s1+=v[i].second.second;
            }
            else if(v[i].first<=y&&v[i].second.first>x)
            {
                s2+=v[i].second.second;
            }
            else if(v[i].first>y&&v[i].second.first<=x)
            {
                s3+=v[i].second.second;
            }
            else
            {
                s4+=v[i].second.second;
            }
        }
        if(s1==s2&&s3==s4&&s2==s3)
            cout << ci*cj << '\n';
        else
            cout << 0 << '\n';    
    }
    return 0;
}
