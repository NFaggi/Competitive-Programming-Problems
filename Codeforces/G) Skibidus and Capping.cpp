//Link: https://codeforces.com/contest/2065/problem/G
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

pair<ll,ll> factorizar(ll n) {
    vector<ll> factores;

    while (n % 2 == 0) {
        factores.push_back(2);
        n /= 2;
    }

    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factores.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factores.push_back(n);
    }
    if(sz(factores)>2||sz(factores)==0)
        return {-1,-1};
    if(sz(factores)==1)
        return {0,0};
    return {factores[0],factores[1]};
}

void solve()
{
    ll n, i, cant=0;
    cin >> n;
    vector<ll>v(n),primos, cantFacts(n+1,0),cantSemis(n+1,0),act(n+1,0);
    pair<ll,ll>p,op1={-1,-1},op2={0,0};
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        p=factorizar(v[i]);
        if(p==op1)
            continue;
        else if(p==op2)
            primos.pb(v[i]);
        else
        {
            cantSemis[v[i]]++;
            cant+=cantSemis[v[i]];
            cantFacts[p.fr]++;
            if(p.fr!=p.se)
                cantFacts[p.se]++;
        }
    }
    sort(all(primos));
    for(i=0; i<sz(primos); i++)
    {
        cant+=cantFacts[primos[i]];
        cant+=(i-act[primos[i]]);
        act[primos[i]]++;
    }
    cout << cant << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
