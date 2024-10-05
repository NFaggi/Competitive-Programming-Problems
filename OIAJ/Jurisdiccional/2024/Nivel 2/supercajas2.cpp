//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

int supercajas(int N, int X, int Y, int Z, vector<int> &a, vector<int> &b, vector<int> &c)
{
    map<pair<int,pair<int, pair<int,int>>>,int>m;
    vector<int>orig(3),v(3);
    orig[0]=X;
    orig[1]=Y;
    orig[2]=Z;
    sort(orig.begin(),orig.end());
    int i, n=int(a.size()), j, vol, volOr=orig[0]*orig[1]*orig[2], res=-1;
    bool term;
    for(i=0; i<n; i++)
    {
        v[0]=a[i];
        v[1]=b[i];
        v[2]=c[i];
        vol=v[0]*v[1]*v[2];
        sort(v.begin(),v.end());
        term=0;
        for(j=0; j<3; j++)
        {
            if(v[j]<orig[j])
            {
                term=1;
                break;
            }
        }
        if(term)
            continue;
        pair<int,pair<int, pair<int,int>>>par;
        par.first=vol-volOr;
        par.second.first=v[0];
        par.second.second.first=v[1];
        par.second.second.second=v[2];
        m[par]++;
    }
    for(auto k:m)
    {
        if(k.second>=N)
        {
            res=k.first.first;
            break;
        }
    }
    return res;
}
