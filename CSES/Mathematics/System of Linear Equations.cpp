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

const int MOD=1e9+7;

ll binpow(ll a, ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%MOD;
    ll ans=binpow(a,b/2);
    ans=(ans*ans)%MOD;
    if(b%2==1)
        ans=(ans*(a%MOD))%MOD;
    return ans;
}

ll inv(ll x)
{
    return binpow(x,MOD-2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, i, j, k, x, o;
    cin >> n >> m;
    vector<vector<ll>>a(n,vector<ll>(m)), aBK;
    vector<ll>b(n),bBK;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            cin >> a[i][j];
        cin >> b[i];
    }
    aBK=a;
    bBK=b;
    j=0;
    for(i=0; i<n; i++)
    {
        if(j>=m)
            break;
        if(a[i][j]==0)
        {
            for(k=i; k<n; k++)
            {
                if(a[i][k]!=0)
                {
                    swap(a[i],a[k]);
                    break;
                }
            }
            if(a[i][j]==0)
            {
                j++;
                i--;
                continue;
            }
        }
        x=a[i][j];
        for(k=j; k<m; k++)
            a[i][k]=(a[i][k]*inv(x))%MOD;
        b[i]=(b[i]*inv(x))%MOD;
        for(k=i+1; k<n; k++)
        {
            x=a[k][j];
            for(o=j; o<m; o++)
            {
                a[k][o]=(a[k][o]-(a[i][o]*x)%MOD)%MOD;
                if(a[k][o]<0)
                    a[k][o]+=MOD;
            }
            b[k]=(b[k]-(b[i]*x)%MOD)%MOD;
            if(b[k]<0)
                b[k]+=MOD;
        }
        j++;
    }
    i--;
    j--;
    vector<ll>ans(m,0);
    bool band;
    for(; i>=0; i--)
    {
        x=b[i];
        band=0;
        for(k=0; k<=j; k++)
        {
            if(a[i][k]!=0)
            {
                band=1;
                break;
            }
        }
        if(!band)
            continue;
        while(j>=0&&a[i][j]!=1)
            j--;
        if(j<0)
            break;
        for(k=j+1; k<m; k++)
        {
            x=(x-(ans[k]*a[i][k])%MOD)%MOD;
            if(x<0)
                x+=MOD;
        }
        ans[j]=x;
        j--;
    }
    swap(a,aBK);
    swap(b,bBK);
    for(i=0; i<n; i++)
    {
        x=0;
        for(j=0; j<m; j++)
            x=(x+(a[i][j]*ans[j])%MOD)%MOD;
        if(x!=b[i])
        {
            cout << -1;
            return 0;
        }
    }

    for(i=0; i<m; i++)
        cout << ans[i] << ' ';
    return 0;
}
