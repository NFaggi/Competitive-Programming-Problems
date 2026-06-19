//Link: https://juez.oia.unsam.edu.ar/tasks/tachadigitos
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

int k9(int K, string &d)
{
    vector<ll>cant(K+1,0);
    for(auto k:d)
        cant[k-'0']++;
    ll tot=sz(d);

    ll act=K, ans=0, ma, i;
    while(tot)
    {
        ma=0;
        for(i=act; i>0; i--)
        {
            if(cant[i]!=0)
            {
                ma=i;
                break;
            }
        }
        if(ma==3&&act==6)
        {
            if(cant[2]>=3)
            {
                cant[2]-=3;
                tot-=3;
                ans++;
                act=K;
                continue;
            }
        }
        if(ma==4&&act==5)
        {
            if(cant[3]&&cant[2])
            {
                cant[3]--;
                cant[2]--;
                tot-=2;
                ans++;
                act=K;
                continue;
            }
        }
        if(ma==3&&act==4)
        {
            if(cant[2]>=2)
            {
                cant[2]-=2;
                tot-=2;
                ans++;
                act=K;
                continue;
            }
        }
        if(ma==0)
        {
            ans++;
            act=K;
            continue;
        }
        else
        {
            cant[ma]--;
            tot--;
            act=act-ma;
        }
    }
    if(act!=K)
        ans++;
    return ans;
}

int k7(int K, string &d)
{
    vector<ll>cant(K+1,0);
    for(auto k:d)
        cant[k-'0']++;
    ll tot=sz(d);

    ll act=K, ans=0, ma, i;
    while(tot)
    {
        ma=0;
        for(i=act; i>0; i--)
        {
            if(cant[i]!=0)
            {
                ma=i;
                break;
            }
        }
        if(ma==0)
        {
            ans++;
            act=K;
            continue;
        }
        else if(ma==3&&act==4)
        {
            if(cant[2]&&(cant[2]-1))
            {
                cant[2]--;
                cant[2]--;
                tot-=2;
                act=act-4;
            }
            else
            {
                cant[ma]--;
                tot--;
                act=act-ma;
            }
        }
        else
        {
            cant[ma]--;
            tot--;
            act=act-ma;
        }
    }
    if(act!=K)
        ans++;
    return ans;
}

int tachadigitos(int K, string &d)
{
    if(K==7)
        return k7(K,d);
    if(K==9)
        return k9(K,d);
    vector<ll>cant(K+1,0);
    for(auto k:d)
        cant[k-'0']++;
    ll tot=sz(d);

    ll act=K, ans=0, ma, i;
    while(tot)
    {
        ma=0;
        for(i=act; i>0; i--)
        {
            if(cant[i]!=0)
            {
                ma=i;
                break;
            }
        }
        if(ma==4)
        {
            bool band=0;
            while(cant[3]&&act>=3)
            {
                act-=3;
                cant[3]--;
                tot--;
                band=1;
            }
            if(band)
                continue;
        }
        if(ma==0)
        {
            ans++;
            act=K;
            continue;
        }
        else if(ma==3&&act==4)
        {
            if(cant[2]&&(cant[2]-1))
            {
                cant[2]--;
                cant[2]--;
                tot-=2;
                act=act-4;
            }
            else
            {
                cant[ma]--;
                tot--;
                act=act-ma;
            }
        }
        else
        {
            cant[ma]--;
            tot--;
            act=act-ma;
        }
    }
    if(act!=K)
        ans++;
    return ans;
}
