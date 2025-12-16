//Link: https://oj.uz/problem/view/IOI14_gondola
//Score: 100/100
#include <bits/stdc++.h>
#include "gondola.h"
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
map<ll,bool> ap;

int valid(int n, int inputSeq[])
{
    ll in = -1, i, x, sig;
    for (i = 0; i < n; i++)
    {
        if(ap[inputSeq[i]])
            return 0;
        ap[inputSeq[i]]=1;
        if (inputSeq[i] <= n)
        {
            in = i;
            x = inputSeq[i];
        }
    }
    if (in == -1)
        return 1;
    i = (in + 1) % n;
    sig = (x + 1) % (n + 1);
    if (sig == 0)
        sig = 1;
    while (i != in)
    {
        if (inputSeq[i] <= n && sig != inputSeq[i])
            return 0;
        i = (i + 1) % n;
        sig = (sig + 1) % (n + 1);
        if (sig == 0)
            sig = 1;
    }
    return 1;
}
//----------------------

int replacement(int n, int gondolaSeq[], int replacementSeq[])
{
    ll in = -1, i, j = 0, act = n + 1, x;
    vector<pair<ll, ll>> v;
    vector<ll> val(n);
    for (i = 0; i < n; i++)
    {
        if (gondolaSeq[i] <= n)
        {
            in = i;
            x = gondolaSeq[i];
            break;
        }
    }
    if (in == -1)
    {
        for (i = 0; i < n; i++)
            val[i] = i + 1;
    }
    else
    {
        val[in] = x;
        i = in;
        i = (i + 1) % n;
        x = (x + 1) % (n + 1);
        if (x == 0)
            x++;
        while (i != in)
        {
            val[i]=x;
            i = (i + 1) % n;
            x = (x + 1) % (n + 1);
            if (x == 0)
                x++;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (gondolaSeq[i] > n)
        {
            v.pb({gondolaSeq[i], val[i]});
        }
    }
    sort(all(v));
    reverse(all(v));
    while (sz(v) > 1)
    {
        if (v.back().fr > act)
        {
            replacementSeq[j] = v[0].se;
            j++;
            v[0].se = act;
            act++;
        }
        else
        {
            replacementSeq[j] = v.back().se;
            act++;
            j++;
            v.pop_back();
        }
    }
    if (sz(v))
    {
        while (act <= v[0].fr)
        {
            replacementSeq[j] = v[0].se;
            v[0].se = act;
            act++;
            j++;
        }
    }
    return j;
}

//----------------------

const ll MOD=1e9+9;
ll binpow(ll a, ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%MOD;
    ll ans=binpow(a,b/2);
    ans=(ans*ans)%MOD;
    if(b%2)
        ans=(ans*(a%MOD))%MOD;
    return ans;
}
int countReplacement(int n, int inputSeq[])
{
    if(!valid(n,inputSeq))
        return 0;
    vector<ll>v;
    ll i, x, y, ans=1, ant=n;
    for(i=0; i<n; i++)
        if(inputSeq[i]>n)
            v.pb(inputSeq[i]);
    sort(all(v));
    if(sz(v)<=1)
        return 1;
    for(i=0; i<sz(v); i++)
    {
        x=v[i]-ant-1;
        ant=v[i];
        y=sz(v)-i;
        ans=(1ll*ans*binpow(y,x))%MOD;
    }
    if(sz(v)==n)
        ans=(1ll*ans*n)%MOD;
    return ans;
}
