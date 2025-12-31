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
    ll n, k, j=0, i, sum;
    cin >> n >> k;
    sum=n-1;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        v[i]=i+1;

    for(i=0; i<n; i++)
    {
        if(sum<=k)
        {
            k-=sum;
            cout << v.back() << ' ';
            v.pop_back();
        }
        else
            cout << v[j++] << ' ';
        sum--;
    }
    return 0;
}
