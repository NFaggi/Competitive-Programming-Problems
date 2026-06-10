//Link: https://codeforces.com/contest/2185/problem/G
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

const int MAXA=1e6+1;

ll rep[MAXA], sigs[MAXA];

void solve()
{
    ll n, m, i, j, sum=0, ans=0, tam=1e6+1;
    cin >> n;
    vector<vector<ll>>v(n);
    vector<ll>mex(n,0), sig(n,0);
    for(i=0; i<n; i++)
    {
        cin >> m;
        v[i].resize(m);
        for(j=0; j<m; j++)
            cin >> v[i][j];
        sort(all(v[i]));
        for(j=0; j<m; j++)
            if(mex[i]==v[i][j])
                mex[i]++;
        rep[mex[i]]++;
        sig[i]=mex[i]+1;
        for(j=0; j<m; j++)
            if(sig[i]==v[i][j])
                sig[i]++;
        sigs[mex[i]]+=sig[i];
        sum+=mex[i];
    }


    ll act, aux;
    for(i=0; i<n; i++)
    {
        for(j=0; j<sz(v[i]); j++)
        {
            act=sum;
            if(mex[i]>v[i][j]&&!((j>0&&v[i][j-1]==v[i][j])||(j+1<sz(v[i])&&v[i][j+1]==v[i][j])))
            {
                act-=mex[i];
                act+=v[i][j];
            }
            rep[mex[i]]--;
            sigs[mex[i]]-=sig[i];

            aux=act*(n-1)-v[i][j]*rep[v[i][j]]+sigs[v[i][j]];

            ans+=aux;

            sigs[mex[i]]+=sig[i];
            rep[mex[i]]++;
        }
    }

    for(i=0; i<n; i++)
    {
        rep[mex[i]]--;
        sigs[mex[i]]-=sig[i];
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
