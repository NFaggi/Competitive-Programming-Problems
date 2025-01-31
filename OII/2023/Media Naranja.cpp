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

const int MAX_P=524288;

ll seg[MAX_P*2], I[MAX_P*2], D[MAX_P*2];

void update(ll nod, ll x)
{
    while(nod>0)
    {
        seg[nod]+=x;
        nod=nod/2;
    }
}

ll calc(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    return calc(a,b,nod*2)+calc(a,b,nod*2+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, l, r, i, sum=0, j=0;
    double oMid;
    cin >> n;
    vector<pair<ll,ll>>rangs(n);
    map<double,ll>m;
    vector<double>ids;
    for(i=0; i<n; i++)
    {
        cin >> l >> r;
        rangs[i]={l,r};
        oMid=((double)l+(double)r)/double(2);
        ids.pb(l);
        ids.pb(oMid);
    }
    sort(all(ids));
    for(i=0; i<n*2; i++)
        m[ids[i]]=i;
    vector<pair<double,pair<ll,ll>>>v;
    vector<pair<double,ll>>del;
    for(i=0; i<n; i++)
    {
        l=rangs[i].fr;
        r=rangs[i].se;
        oMid=((double)l+(double)r)/double(2);
        v.push_back({oMid,{m[oMid],m[l]}});
        del.push_back({r,m[oMid]});
    }
    sort(v.begin(),v.end());
    sort(del.begin(),del.end());
    for(i=MAX_P; i<MAX_P*2; i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=MAX_P-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }

    for(i=0; i<sz(v); i++)
    {
        while(j<sz(del)&&v[i].fr>del[j].fr)
        {
            update(del[j].se+MAX_P, -1);
            j++;
        }
        sum+=calc(v[i].se.se+MAX_P, v[i].se.fr+MAX_P, 1);
        update(v[i].se.fr+MAX_P, 1);
    }
    cout << sum << '\n';
    return 0;
}
