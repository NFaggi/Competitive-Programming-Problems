//Link: https://codeforces.com/contest/230/problem/C
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n, m, i, j, res=LLONG_MAX, dist,act;
    cin >> n >> m;
    string s;
    vector<vector<ll>>mat(n,vector<ll>(m,0));
    vector<ll>ult(n,-1);
    vector<ll>in(n,-1);
    vector<ll>v(m,0);
    for(i=0; i<n; i++)
    {
        cin >> s;
        for(j=0; j<m; j++)
        {
            mat[i][j]=s[j]-'0';
            if(mat[i][j]==1)
            {
                ult[i]=j;
                if(in[i]==-1)
                    in[i]=j;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(ult[i]==-1)
        {
            cout << -1;
            return 0;
        }
        set<ll>s,s2;
        for(j=0; j<m; j++)
        {
            if(mat[i][j])
            {
                s.insert(j);
                s2.insert(-j);
            }
        }
        for(j=0; j<m; j++)
        {
            dist=LLONG_MAX;
            auto it=s.lower_bound(j);
            if(it!=s.end())
            {
                act=abs(*it-j);
                dist=min(dist,act);
            }
            auto it2=s2.lower_bound(-j);
            if(it2!=s2.end())
            {
                act=abs(j+(*it2));
                dist=min(dist,act);
            }
            act=(m-ult[i])+j;
            dist=min(dist,act);
            act=in[i]+(m-j);
            dist=min(dist,act);
            v[j]+=dist;
        }
    }
    dist=LLONG_MAX;
    for(i=0; i<int(v.size()); i++)
    {
        dist=min(dist,v[i]);
    }
    cout << dist;
    return 0;
}
