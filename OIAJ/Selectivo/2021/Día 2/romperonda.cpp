//Link: https://juez.oia.unsam.edu.ar/task/114
//Score: 82/100
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

const int MOD=16;

ll n, K;
vector<ll>v;

ll calcSeg()
{
    ll i, j, k=K, l,acum=0,sum=0, act;
    vector<vector<ll>>dp(n,vector<ll>(k,-1));
    sum=v[0]%MOD;
    sum=sum*sum;
    dp[0][0]=sum;
    for(i=1; i<n; i++)
    {
        acum=(acum+v[i])%MOD;
        dp[i][1]=acum*acum+sum;
    }
    vector<ll>memo(MOD,-1), newMemo(MOD);
    for(i=2; i<k; i++)
    {
        for(l=0; l<MOD; l++)
            memo[l]=-1;
        for(j=i; j<n; j++)
        {
            sum=dp[j-1][i-1];
            for(l=0; l<MOD; l++)
            {
                newMemo[l]=-1;
            }
            for(l=0; l<MOD; l++)
            {
                newMemo[(l+v[j])%MOD]=max(newMemo[(l+v[j])%MOD],memo[l]);
            }
            newMemo[v[j]%MOD]=max(newMemo[v[j]%MOD],sum);
            memo=newMemo;
            for(l=0; l<MOD; l++)
            {
                if(memo[l]==-1)
                    continue;
                dp[j][i]=max(l*l+memo[l],dp[j][i]);
            }
        }
    }
    return dp[n-1][k-1];
}
ll calcPri(ll in)
{
    ll i, j, k=K, l,acum=0,sum=0, act;
    vector<vector<ll>>dp(n,vector<ll>(k,-1));
    i=in;
    while(true)
    {
        acum=(acum+v[i])%MOD;
        dp[i][0]=acum*acum;
        i=(i+1)%n;
        if(i==in)
            break;
    }
    vector<ll>memo(MOD,-1), newMemo(MOD);
    for(i=1; i<k; i++)
    {
        for(l=0; l<MOD; l++)
            memo[l]=-1;
        j=(in+i)%n;
        while(true)
        {
            sum=dp[(j-1+n)%n][i-1];
            for(l=0; l<MOD; l++)
            {
                newMemo[l]=-1;
            }
            for(l=0; l<MOD; l++)
            {
                newMemo[(l+v[j])%MOD]=max(newMemo[(l+v[j])%MOD],memo[l]);
            }
            newMemo[v[j]%MOD]=max(newMemo[v[j]%MOD],sum);
            memo=newMemo;
            for(l=0; l<MOD; l++)
            {
                if(memo[l]==-1)
                    continue;
                dp[j][i]=max(l*l+memo[l],dp[j][i]);
            }
            j=(j+1)%n;
            if(j==in)
                break;
        }
    }
    in--;
    if(in<0)
        in+=n;
    return dp[in][k-1];
}

ll calcPriK2(ll in)
{
    ll ma=0, k1=0, k2=0,i;

    for(i=0; i<n; i++)
    {
        k1+=v[i];
    }

    for(i=in; (i+1)%n!=in; i=(i+1)%n)
    {
        k1-=v[i];
        k2+=v[i];
        ma=max(ma,(k1%MOD)*(k1%MOD)+(k2%MOD)*(k2%MOD));
    }
    return ma;
}

vector<int> romperonda(vector<int> &ronda, int k)
{
    vector<ll>ans(2,0);
    v=ronda;
    K=k;
    n=sz(ronda);
    if(n<=350)
    for(ll i=0; i<n; i++)
    {
        ans[0]=max(ans[0],calcPri(i));
    }
    else
        for(ll i=0; i<n; i++)
        {
            ans[0]=max(ans[0],calcPriK2(i));
        }
    ans[1]=calcSeg();
    return ans;
}
