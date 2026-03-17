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
 
const int MAXN=2e5+1;
const int MOD=1e9+7;
ll p1=31, p2=97;
 
 
vector<ll>seg[2],segInv[2],I,D; 
ll pots[2][MAXN], invPots[2][MAXN], pot=1, n;
 
ll binpow(ll a, ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%MOD;
    ll ans=binpow(a,b/2);
    ans=(ans*ans)%MOD;
    if(b%2!=0)
        ans=(ans*(a%MOD))%MOD;
    return ans;
}
 
ll inv(ll x)
{
    return binpow(x,MOD-2);
}
 
void update(ll nod, ll nod2, ll x)
{
    ll j;
    for(j=0; j<2; j++)
        seg[j][nod]=(x*pots[j][nod-pot])%MOD;
    nod/=2;
    while(nod>0)
    {
        for(j=0; j<2; j++)
            seg[j][nod]=(seg[j][nod*2]+seg[j][nod*2+1])%MOD;
        nod/=2;
    }
 
    for(j=0; j<2; j++)
        segInv[j][nod2]=(x*pots[j][nod2-pot])%MOD;
    nod2/=2;
    while(nod2>0)
    {
        for(j=0; j<2; j++)
            segInv[j][nod2]=(segInv[j][nod2*2]+segInv[j][nod2*2+1])%MOD;
        nod2/=2;
    }
}
 
ll calc(ll a, ll b, ll p, ll t, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
    {
        if(t==0)
            return seg[p][nod];
        return segInv[p][nod];
    }
    return (calc(a,b,p,t,nod*2)+calc(a,b,p,t,nod*2+1))%MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt","r",stdin);
    ll m, i, j;
    string s, sInv;
    cin >> n >> m >> s;
 
    sInv=s;
    reverse(all(sInv));
 
    pots[0][0]=pots[1][0]=1;
    invPots[0][0]=invPots[1][0]=inv(1);
 
    for(i=1; i<=n; i++)
    {
        pots[0][i]=(pots[0][i-1]*p1)%MOD;
        pots[1][i]=(pots[1][i-1]*p2)%MOD;
        invPots[0][i]=inv(pots[0][i]);
        invPots[1][i]=inv(pots[1][i]);
    }
 
    while(pot<n)
        pot*=2;
 
    for(i=0; i<2; i++)
    {
        seg[i].resize(pot*2,0);
        segInv[i].resize(pot*2,0);
    }
    I.resize(pot*2);
    D.resize(pot*2);
 
    for(i=pot; i<pot*2; i++)
    {
        I[i]=D[i]=i;
        if(i-pot<n)
        {
            for(j=0; j<2; j++)
            {
                seg[j][i]=(pots[j][i-pot]*(s[i-pot]-'a'))%MOD;
                segInv[j][i]=(pots[j][i-pot]*(sInv[i-pot]-'a'))%MOD;
            }
        }
    }
 
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        for(j=0; j<2; j++)
        {
            seg[j][i]=(seg[j][i*2]+seg[j][i*2+1])%MOD;
            segInv[j][i]=(segInv[j][i*2]+segInv[j][i*2+1])%MOD;
        }
    }
 
    ll t, a, b, k, a2, b2;
    ll r[4];
    char x;
    while(m--)
    {
        cin >> t;
        if(t==1)
        {
            cin >> k >> x;
            k--;
            a=k+pot;
            b=n-1-k+pot;
            update(a,b,(x-'a'));
        }
        else
        {
            cin >> a >> b;
            a--;
            b--;
            a2=n-1-b;
            b2=n-1-a;
            a+=pot;
            b+=pot;
            a2+=pot;
            b2+=pot;
            r[0]=(calc(a,b,0,0,1)*invPots[0][a-pot])%MOD;
            r[1]=(calc(a2,b2,0,1,1)*invPots[0][a2-pot])%MOD;
            r[2]=(calc(a,b,1,0,1)*invPots[1][a-pot])%MOD; 
            r[3]=(calc(a2,b2,1,1,1)*invPots[1][a2-pot])%MOD;
            if(r[0]==r[1]&&r[2]==r[3])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
 
    return 0;
}
