//Link: https://juez.oia.unsam.edu.ar/task/117
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

ll f(ll K, ll N)
{
    if(N==1ll)
        return 0ll;
    ll K1=K%(N-1ll), ans;
    ans=f(K,N-1ll);
    //cout << K1 << ' ' << N << ' ' << ans << endl;
    if(ans+K1+1ll>=N)
        return (ans-(N-1-K1)+1);
    return ans+K1+1ll;
}

ll g(ll K, ll N)
{
    if(N==1)
        return 0ll;
    if(K==0)
        return N-1ll;
    if(K>=N-1)
        return f(K, N);
    ll ans, T, S;
    S=(N)%(K+1ll);
    T=(N)/(K+1ll);
    ans=g(K,N-T);
    if(ans<S)
        return N-S+ans;

    return ((ans-S)/K)+1ll+(ans-S);

}

int solitario(vector<int> c, long long N, int K)
{
    ll pos, M=(long long)c.size();
    pos=N-1ll-g(K, N);
    return c[pos%M];
}