#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i, j, pos=0, mi, ma, piv, y, xd;
    ll x, act, falt, cant, sum;
    cin >> n >> x;
    vector<ll>vin(n);
    multiset<ll>general;
    vector<multiset<ll>>v(n);
    vector<pair<ll,pair<ll,ll>>>sums;
    for(i=0; i<n; i++)
    {
        cin >> vin[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            general.insert(vin[i]+vin[j]);
            v[i].insert(vin[i]+vin[j]);
            v[j].insert(vin[i]+vin[j]);
            sums.push_back({vin[i]+vin[j],{i,j}});
        }
    }
    sort(sums.begin(),sums.end());
    for(i=0; i<n&&!pos; i++)
    {
        for(j=i+1; j<n&&!pos; j++)
        {
            act=vin[i]+vin[j];
            falt=x-act;
            cant=general.count(falt);
            cant-=v[i].count(falt);
            cant-=v[j].count(falt);
            if(act==falt)
                cant++;
            if(cant>0)
            {
                xd=i;
                y=j;
                pos=1;
                sum=act;
            }
        }
    }
    if(!pos)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        falt=x-sum;
        mi=0;
        ma=int(sums.size());
        while(mi<=ma)
        {
            piv=(mi+ma)/2;
            if(sums[piv].first>=falt)
            {
                pos=piv;
                ma=piv-1;
            }
            else
            {
                mi=piv+1;
            }
        }
        for(i=pos; i<int(sums.size()); i++)
        {
            if(sums[i].second.first!=xd&&sums[i].second.first!=y&&sums[i].second.second!=xd&&sums[i].second.second!=y)
            {
                cout << xd+1 << ' ' << y+1 << ' ' << sums[i].second.first+1 << ' ' <<  sums[i].second.second+1;
                break;
            }
        }
    }

    return 0;
}
