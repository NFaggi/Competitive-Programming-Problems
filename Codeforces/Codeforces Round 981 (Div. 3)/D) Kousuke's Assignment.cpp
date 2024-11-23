//Link: https://codeforces.com/contest/2033/problem/D
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, i, sum=0,cal, sig=LLONG_MAX, cant=0;
    cin >> n;
    vector<ll>v(n+1,0);
    vector<ll>sums(n+1,0);
    set<pair<ll,ll>>s;
    for(i=1; i<=n; i++)
    {
        cin >> v[i];
        sums[i]=sum;
        sum+=v[i];
        s.insert({sum,i});
    }
    for(i=1; i<=n; i++)
    {
        if(sig==i)
        {
            cant++;
            sig=LLONG_MAX;
            continue;
        }
        auto it=s.lower_bound({sums[i],i});
        if(it!=s.end())
        {
            if(it->first==sums[i])
            {
                sig=min(sig,it->second);
                if(sig==i)
                {
                    cant++;
                    sig=LLONG_MAX;
                    continue;
                }
            }
        }
    }
    cout << cant << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
