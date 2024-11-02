//Link: https://codeforces.com/contest/2036/problem/C
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll rest(ll ind, ll v)
{
    ll n=s.size();
    ll a = max(ind-3,0ll), b=min(ind+3,n-1), i, res=0;
    vector<ll>vec(10,0);
    for(i=a; i<=b; i++)
    {
        if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0')
        {
            vec[i-a]=1;
        }
    }
    if(v==0)
    {
        s[ind]='0';
    }
    else
    {
        s[ind]='1';
    }
    for(i=a; i<=b; i++)
    {
        if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0')
        {
            if(vec[i-a]==0)
                res--;
        }
        else if(vec[i-a]==1)
        {
            res++;
        }
    }
    return res;
}
int main()
{
    ll t, q, i, v, cant=0, ind;
    cin >> t;
    while(t--)
    {
        cin >> s >> q;
        cant=0;
        for(i=0; i<int(s.size())-3; i++)
        {
            if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0')
            {
                cant++;
            }
        }
        while (q--)
        {
            cin >> ind >> v;
            ind--;
            cant-=rest(ind,v);
            if(cant==0)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }


    }
    return 0;
}
