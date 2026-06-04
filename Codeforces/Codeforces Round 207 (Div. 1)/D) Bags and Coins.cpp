//Link: https://codeforces.com/problemset/problem/356/D
#include <bits/stdc++.h>
#define ll int
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
    ll n, s, i, x, ma=0, mai=0;
    cin >> n >> s;
    map<ll,vector<vector<ll>>>his;
    vector<ll>tam(n);
    for(i=0; i<n; i++)
    {
        cin >> tam[i];
        x=tam[i];
        ma=max(ma,x);
        his[x].pb({i});
    }
    mai=his[ma].back().back();
    his[ma].pop_back();
    s-=ma;

    if(s<0)
    {
        cout << -1;
        return 0;
    }
    ll act=0;
    vector<ll>a,b,vac;
    while(true)
    {
        auto it=his.upper_bound(act);
        if(it==his.end())
            break;
        act=it->fr;
        if(act>s)
            break;
        while(sz(it->se)>=3)
        {
            swap((it->se).back(),a);
            (it->se).pop_back();
            swap((it->se).back(),b);
            (it->se).pop_back();
            if(sz(a)<sz(b))
                swap(a,b);
            for(auto k:b)
                a.pb(k);
            his[act+act].pb(vac);
            swap(his[act+act].back(),a);
        }
    }
    vector<pair<ll,vector<ll>>>v;

    for(auto &k:his)
    {
        if(k.fr>s)
        break;
        for(auto &o:k.se)
        {
            v.pb({k.fr,o});
        }
    }
    vector<ll>dp(s+1,0);
    vector<ll>cons(s+1);
    

    dp[0]=1;
    ll j, val;
    for(i=0; i<sz(v); i++)
    {
        val=v[i].fr;
        for(j=s; j>=val; j--)
        {
            if(dp[j])
                continue;
            if(dp[j-val])
            {
                dp[j]=1;
                cons[j]=i;
            }
        }
    }
    if(dp[s]==0)
    {
        cout << -1;
        return 0;
    }


    vector<bool>ap(n,0);
    i=s;

    while(i>0)
    {
        for(auto k:v[cons[i]].se)
            ap[k]=1;
        i-=v[cons[i]].fr;
    }


    vector<pair<ll,ll>>lib;
    vector<ll>S(n,0), punt(n,-1);
    for(i=0; i<n; i++)
    {
        if(ap[i]||i==mai)
            S[i]=tam[i];
        else
            lib.pb({tam[i],i});

    }

    sort(all(lib));

    ll ant=mai;
    while(sz(lib))
    {
        x=lib.back().se;
        S[x]=tam[x];
        S[ant]-=tam[x];
        punt[ant]=x;
        ant=x;
        lib.pop_back();
    }

    for(i=0; i<n; i++)
    {
        cout << S[i] << ' ';
        if(punt[i]==-1)
            cout << 0 << '\n';
        else
            cout << 1 << ' ' << punt[i]+1 << '\n';
    }
    return 0;
}
