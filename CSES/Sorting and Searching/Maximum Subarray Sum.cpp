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
    ll n, i, a, ma=LLONG_MIN, act=LLONG_MIN;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;
        if(act==LLONG_MIN||a+act<a)
            act=a;
        else
            act+=a;
        ma=max(ma,act);
    }
    cout << ma;
    return 0;
}
