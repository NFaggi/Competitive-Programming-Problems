//Link: https://codeforces.com/gym/105665/problem/G
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



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, sum=21;
    double ans;
    cin >> n;
    if(n==1)
    {
        ans=(double)sum/(double)6;
        printf("%.5f",ans);
        return 0;
    }
    sum=sum*n;
    n-=2;
    sum-=7*n;
    sum-=2;
    ans=(double)sum/(double)6;
    printf("%.5f",ans);
    return 0;
}