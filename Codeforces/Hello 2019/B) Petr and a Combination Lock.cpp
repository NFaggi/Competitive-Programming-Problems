//Link: https://codeforces.com/problemset/problem/1097/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, tot=0,ang=0,pos=0,a,b, i;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    queue<pair<ll,ll>>q;
    q.push({ang,pos});
    while(!q.empty())
    {
        ang=q.front().first;
        pos=q.front().second;
        q.pop();
        if(pos==n)
        {
            if(ang==0)
            {
                cout << "YES";
                return 0;
            }
            else
                continue;
        }
        a=(ang+v[pos])%360;
        b=(ang-v[pos]);
        if(b<0)
            b+=360;
        pos++;
        q.push({a,pos});
        q.push({b,pos});
    }
    cout << "NO";
    return 0;
}
