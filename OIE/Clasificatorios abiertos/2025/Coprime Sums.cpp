//Link: https://codeforces.com/gym/105783/problem/D
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN=200001;

void solve()
{
    ll n, i, j, p, k, todo=0;
    cin >> n >> p;
    vector<ll>a(n+1), sum(n+1,0), prims;
    vector<bool>prim(n+1,1);
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        todo+=a[i];
    }
    
    for(i=2; i<=n; i++)
    {
        if(!prim[i])
            continue;
        prims.pb(i);
        for(j=i+i; j<=n; j+=i)
            prim[j]=0;
    }

    ll sq, mask, par, ans, num;
    bool band;
    vector<ll>fact;

    auto calc=[&]()
    {
        sq=sqrt(k);
        fact.resize(0);
        for(j=0; j<sz(prims); j++)
        {
            if(sq<prims[j]||k==1)
                break;
            band=0;
            while(k%prims[j]==0)
            {
                k/=prims[j];
                band=1;
            }
            if(band)
                fact.pb(prims[j]);
        }
        if(k>1)
            fact.pb(k);
        mask=(1<<sz(fact));
    };

    ll ik;
    for(k=2; k<=n; k++)
    {
        ik=k;
        calc();
        k=ik;
        for(i=1; i<mask; i++)
        {
            num=1;
            for(j=0; j<sz(fact); j++)
                if((1<<j)&i)
                    num=num*fact[j];
            sum[num]+=a[k];
        }
    }

    
    while(p--)
    {
        cin >> k;

        calc();

        ans=0;
        for(i=1; i<mask; i++)
        {
            par=__builtin_popcount(i)%2;
            num=1;
            for(j=0; j<sz(fact); j++)
                if((1<<j)&i)
                    num=num*fact[j];
            if(par)
                ans+=sum[num];
            else
                ans-=sum[num];
        }
        cout << todo-ans << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
