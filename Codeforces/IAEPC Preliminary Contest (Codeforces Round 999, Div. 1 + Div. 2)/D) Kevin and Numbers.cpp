//Link: https://codeforces.com/problemset/problem/2061/D
#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,ll>m;

vector<pair<ll,ll>>borr;

bool del(ll x, ll cant)
{
    if(x==1)
    {
        if(m[x]>=cant)
        {
            m[x]-=cant;
            return 1;
        }
        else
            return 0;
    }
    if(m[x]>0)
    {
        if(m[x]>=cant)
        {
            m[x]-=cant;
            return 1;
        }
        else
        {
            cant-=m[x];
            m[x]=0;
            if(x%2==0)
            {
                return del(x/2,cant*2);
            }
            else
            {
                return del(x/2,cant)&&del(x/2+1,cant);
            }
        }
    }
    else
    {
        if(x%2==0)
        {
            return del(x/2,cant*2);
        }
        else
        {
            return del(x/2,cant)&&del(x/2+1,cant);
        }
    }
    return 0;
}

bool borrar(ll x)
{
    if(!del(x, 1))
    {
        return 0;
    }
    return 1;
}

void solve()
{
    borr.resize(0);
    m.clear();
    ll n, M, i, x;
    cin >> n >> M;
    vector<ll>b(M);
    for(i=0; i<n; i++)
    {
        cin >> x;
        m[x]++;
    }
    for(i=0; i<M; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    for(i=0; i<M; i++)
    {
        if(!borrar(b[i]))
        {
            cout << "No\n";
            return;
        }
    }
    for(auto k:m)
    {
        if(k.second>0)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main()
{

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
