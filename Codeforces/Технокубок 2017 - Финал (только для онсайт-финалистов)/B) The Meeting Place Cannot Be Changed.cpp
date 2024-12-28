//Link: https://codeforces.com/problemset/problem/780/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll,ll>>v;
ll n;

double calc(ll x)
{
    ll i,dist;
    double maT=0;
    for(i=0; i<n; i++)
    {
        dist=abs(x-v[i].first);
        maT=max(maT,(double)dist/(double)v[i].second);
    }
    return maT;
}

int main()
{
    ll i, mi=0, ma=1e15, piv, de,band=1, iz;
    double Tiz, Tde, miT;
    cin >> n;
    v.resize(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i].first;
        v[i].first=v[i].first*1000000ll;
    }
    for(i=0; i<n; i++)
    {
        cin >> v[i].second;
        v[i].second=v[i].second*1000000ll;
    }
    sort(v.begin(),v.end());
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        Tiz=calc(piv-1);
        Tde=calc(piv+1);
        if(Tiz<Tde)
        {
            ma=piv-1;
            if(band)
            {
                band=0;
                miT=calc(piv);
            }
            else
                miT=min(miT,calc(piv));
        }
        else
        {
            mi=piv+1;
            if(band)
            {
                band=0;
                miT=calc(piv);
            }
            else
                miT=min(miT,calc(piv));
        }

    }
    printf("%.12f",miT);
    return 0;
}
