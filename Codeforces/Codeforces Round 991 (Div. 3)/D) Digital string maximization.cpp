//Link: https://codeforces.com/contest/2050/problem/D
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll i,x,j,n,ma,pos,l;
    string s,res="";
    cin >> s;
    n=s.size();
    vector<ll>v;
    for(l=0; l<n; l++)
    {
        v.resize(0);
        for(i=l; i<min(n,l+9ll); i++)
        {
            v.push_back((s[i]-'0')-(i-l));
            j=i;
        }
        ma=0;
        pos=0;
        for(i=0; i<int(v.size()); i++)
        {
            if(ma<v[i])
            {
                ma=v[i];
                pos=i;
            }
        }
        res+=('0'+v[pos]);
        for(i=pos+l-1; i>=l; i--)
        {
            swap(s[i],s[i+1]);
        }
    }
    cout << res << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}