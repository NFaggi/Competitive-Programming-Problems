//Link: https://oj.uz/problem/view/IOI14_friend
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

int findSample(int n, int confidence[], int host[], int protocol[])
{
    ll i;
    vector<ll>p(n),q(n,0);
    for(i=0; i<n; i++)
        p[i]=confidence[i];
    
    for(i=n-1; i>=1; i--)
    {
        ll nod=host[i];
        switch(protocol[i])
        {
            case 0: p[nod]=p[nod]+q[i];
                    q[nod]=q[nod]+max(p[i],q[i]);    
            break;
            case 1: p[nod]=max(q[nod]+p[i],max(p[nod]+p[i],p[nod]+q[i]));
                    q[nod]=q[nod]+q[i];
            break;
            default: 
                    p[nod]=max(p[nod]+q[i],q[nod]+p[i]);
                    q[nod]=q[nod]+q[i];
            break;
        }
    }
    return max(p[0],q[0]);
}
