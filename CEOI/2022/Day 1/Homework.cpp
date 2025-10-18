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
string s;
ll n=0;
vector<ll>mids;
pair<ll,ll>calc(ll l, ll r)
{
    if(l==r)
        return {1,n};
    pair<ll,ll>a=calc(l+4,mids[l]-1), b=calc(mids[l]+1,r-1);
    if(s[l+1]=='i')
        return {min(a.fr,b.fr),n-((n-a.se+1)+(n-b.se+1))+1};
    return {a.fr+b.fr,max(a.se,b.se)};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i;
    cin >> s;
    mids.resize(sz(s));
    for(i=0; i<sz(s); i++)
        if(s[i]=='?')
            n++;

    stack<ll>q;
    for(i=0; i<sz(s); i++)
    {
        if(s[i]=='m')
            q.push(i);
        else if(s[i]==',')
        {
            mids[q.top()]=i;
            q.pop();
        }
    }
    pair<ll,ll>a=calc(0, sz(s)-1);
    cout << (a.se-a.fr+1);
    return 0;
}
