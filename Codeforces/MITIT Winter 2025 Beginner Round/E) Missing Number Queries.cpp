//Link: https://codeforces.com/gym/105668/problem/E
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

    ll n, q, x, op, l, r, i;
    cin >> n >> q;
    map<ll,ll>m;
    set<pair<ll,ll>>s;
    vector<ll>v(n);
    forn(i,n)
    {
        s.insert({-1,i+1});
        m[i+1]=0;
    }
    forn(i,n)
    {
        cin >> x;
        v[i]=x;
        if(m[x]==0)
        {
            auto it=s.find(make_pair(-1,x));
            s.erase(it);
        }
        s.insert({i,x});
        m[x]++;
    }

    while(q--)
    {
        cin >> op >> l >> r;
        l--;
        if(op==1)
        {
            m[v[l]]--;
            if(m[v[l]]==0)
            {
                s.insert({-1,v[l]});
            }
            auto it=s.find(make_pair(l,v[l]));
            s.erase(it);

            v[l]=r;
            if(m[r]==0)
            {
                auto it=s.find(make_pair(-1,r));
                s.erase(it);
            }
            s.insert({l,r});
            m[r]++;
        }
        else
        {
            r--;
            auto it=s.begin();
            pair<ll,ll>p=*it;
            if(p.fr<l)
                cout << p.se << '\n';
            else
            {
                it=prev(s.end());
                p=*it;
                cout << p.se << '\n';
            }
        }
    }
    return 0;
}
