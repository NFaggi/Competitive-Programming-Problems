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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll num, cant=0, act, pot=2, i;
    cin >> num;
    num++;
    for(i=0; i<60; i++)
    {
        cant+=(num/pot)*(pot/2ll);
        act=num%pot;
        act-=pot/2ll;
        pot*=2ll;
        if(act<=0)
            continue;
        cant+=act;
    }
    cout << cant;
    return 0;
}
