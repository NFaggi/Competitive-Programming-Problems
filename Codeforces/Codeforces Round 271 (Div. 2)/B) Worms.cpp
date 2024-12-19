//Link: https://codeforces.com/problemset/problem/474/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll busc(vector<ll>&v, ll x)
{
    ll mi=0, ma=int(v.size())-1, piv, pos=0;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(v[piv]==x)
            return (piv+1);
        else if(v[piv]>x)
            ma=piv-1;
        else
        {
            mi=piv+1;
            pos=max(pos,piv);
        }
    }
    return pos+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i,q,x;
    cin >> n;
    vector<ll>v(n);
    vector<ll>in(n),fin(n);
    cin >> v[0];
    fin[0]=v[0];
    in[0]=1;
    for(i=1; i<n; i++)
    {
        cin >> v[i];
        in[i]=fin[i-1]+1;
        fin[i]=(in[i]-1)+v[i];
    }
    cin >> q;
    while(q--)
    {
        cin >> x;
        cout << busc(in,x) << '\n';
    }
    return 0;
}
