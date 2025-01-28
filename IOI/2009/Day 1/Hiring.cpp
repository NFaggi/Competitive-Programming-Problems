//Link: https://oj.uz/problem/view/IOI09_hiring
//Score: 100/100
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
    ll n, w, i, s, q, ma=0, cant, j, sum=0;
    double costLevel, acum, mi;
    cin >> n >> w;

    vector<pair<double,pair<ll,ll>>>trab(n);

    for(i=0; i<n; i++)
    {
        cin >> s >> q;
        costLevel=double(s)/double(q);
        trab[i]={costLevel,{q,i}};
    }
    sort(all(trab));
    vector<ll>maV;

    priority_queue<ll>pq;

    for(i=0; i<n; i++)
    {
        sum+=trab[i].second.first;
        costLevel=trab[i].first*double(sum);
        pq.push(trab[i].second.first);
        while(costLevel>double(w))
        {
            ll x=pq.top();
            pq.pop();
            sum-=x;
            costLevel=trab[i].first*double(sum);
        }
        if(ma<int(pq.size()))
        {
            ma=int(pq.size());
            mi=costLevel;
        }
        else if(ma==int(pq.size())&&mi>costLevel)
        {
            mi=costLevel;
        }
    }
    priority_queue<pair<ll,ll>>pq2;
    sum=0;
    for(i=0; i<n; i++)
    {
        sum+=trab[i].second.first;
        costLevel=trab[i].first*double(sum);
        pq2.push(trab[i].second);
        while(costLevel>double(w))
        {
            ll x=pq2.top().first;
            pq2.pop();
            sum-=x;
            costLevel=trab[i].first*double(sum);
        }
        if(ma==int(pq2.size())&&mi==costLevel)
        {
            break;
        }
    }
    while(pq2.size())
    {
        ll x=pq2.top().second;
        pq2.pop();
        maV.pb(x);
    }
    sort(all(maV));

    cout << maV.size() << '\n';
    for(auto k:maV)
        cout << k+1 << '\n';
    return 0;
}
