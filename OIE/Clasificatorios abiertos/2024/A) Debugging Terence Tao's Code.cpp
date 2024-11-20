//Link: https://codeforces.com/gym/105003/problem/A
//Score: 100/100
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n=1e8, s=1, t=1, i, q;
    cin >> q;
    set<pair<ll,ll>>se;
    while(s<n&&t<n)
    {
        
        s+=t;
        t+=s;
        se.insert({t,s});
        
    }


    while(q--)
    {
        cin >> i;
        auto it=se.lower_bound(make_pair(i,0));
        if(it->second>=i)
        {
            cout <<"OK\n";
        }
        else
        {
            cout << it->second << '\n';
        }
    }

    return 0;
}