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
 
const int MAXN=5e5+1;
const int MOD=999999937;
ll p[2]={31,97};
 
ll pref[2][MAXN], n, invPot[2][MAXN], pot[2][MAXN];
 
long long binpow(long long a, long long b)
{
    long long ans=1ll;
    while(b)
    {
        if(b&1ll)
        {
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1ll;
    }
    return ans;
}
 
bool can(ll x)
{
    ll i, act[2], j;
    map<long long,ll>m;
    for(i=x-1; i<n; i++)
    {
        for(j=0; j<2; j++)
        {
            act[j]=pref[j][i];
            if(i-x>0)
            act[j]-=pref[j][i-x];
            if(act[j]<0)
                act[j]+=MOD;
            act[j]=(1ll*act[j]*invPot[j][i+1])%MOD;
        }
        if(m[1ll*act[0]*1e9+act[1]])
            return 1;
        m[1ll*act[0]*1e9+act[1]]=1;
    }
    return 0;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, j, x;
    long long invP[2]={binpow(p[0],MOD-2),binpow(p[1],MOD-2)};
    string s;
    cin >> s;
    n=sz(s);
    pot[0][0]=pot[1][0]=1;
    invPot[0][0]=invPot[1][0]=binpow(1,MOD-2);
    for(i=1; i<=n; i++)
    {
        x=s[i-1]-'a';
        for(j=0; j<2; j++)
        {
            pot[j][i]=(1ll*pot[j][i-1]*p[j])%MOD;
            invPot[j][i]=(invPot[j][i-1]*invP[j])%MOD;
            pref[j][i-1]=(1ll*pot[j][i]*x)%MOD;
            if(i-1>0)
                pref[j][i-1]=(pref[j][i-1]+pref[j][i-2])%MOD;
        }
    }
 
    ll l=1, r=sz(s)-1, pos=0, piv;
 
    while(l<=r)
    {
        piv=(l+r)/2;
        if(can(piv))
        {
            pos=piv;
            l=piv+1;
        }
        else
            r=piv-1;
    }
 
    ll act[2];
    if(pos>0)
    {
 
        unordered_map<long long,ll>m;
        for(i=pos-1; i<n; i++)
        {
            for(j=0; j<2; j++)
            {
                act[j]=pref[j][i];
                if(i-pos>0)
                act[j]-=pref[j][i-pos];
                if(act[j]<0)
                    act[j]+=MOD;
                act[j]=(1ll*act[j]*invPot[j][i+1])%MOD;
            }
            if(m[1ll*act[0]*1e9+act[1]])
            {
                for(j=i-pos+1; j<=i; j++)
                    cout << s[j];
                return 0;
            }
            m[1ll*act[0]*1e9+act[1]]=1;
        }
    }
    cout << -1;
    return 0;
}
