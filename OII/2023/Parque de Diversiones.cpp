//Score: 100/100
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    ll n, m, j, i, ult, cant, an;
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<ll>>v(n,vector<ll>(m));
    vector<ll>ults(n), exp(n,0);
    vector<ll>ans(m,0);
    for(i=0; i<n; i++)
    {
        ult=0;
        for(j=0; j<m; j++)
        {
            cin >> v[i][j];
            if(v[i][j])
                ult=j;
        }
        ults[i]=ult;
    }
    for(i=0; i<m; i++)
    {
        vector<ll>mex;
        for(j=0; j<n; j++)
        {
            if(ults[j]!=i)
                continue;
            if((exp[j]>0&&v[j][i]>0)||(exp[j]<0&&v[j][i]<0))
                continue;
            if(exp[j]==0)
            {
                mex.pb(0);
                continue;
            }
            cant=abs(exp[j])/abs(v[j][i]);
            if(exp[j]%v[j][i]!=0)
                continue;
            mex.pb(cant);
        }

        sort(mex.begin(),mex.end());
        unique(mex.begin(),mex.end());
        an=0;
        for(auto k:mex)
        {
            if(an==k)
                an++;
            else
                break;
        }
        ans[i]=an;
        for(j=0; j<n; j++)
        {
            exp[j]+=v[j][i]*an;
        }
    }
    for(auto k: ans)
        cout << k << ' ';
    return 0;
}