//Link: https://codeforces.com/gym/105046/problem/D
//Score: 100/100
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool imppar(vector<ll>&imp,vector<ll>&par,ll n, ll m,ll pari,vector<vector<ll>>&mat)
{
    ll im=0,pa=0, i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(pari==0)
            {
                if(pa>=int(par.size()))
                {
                    return 0;
                }
                mat[i][j]=par[pa];
                pa++;
                pari=1;
            }
            else
            {
                if(im>=int(imp.size()))
                {
                    return 0;
                }
                mat[i][j]=imp[im];
                im++;
                pari=0;
            }
        }
        if(mat[i][0]%2==0)
            pari=1;
        else
            pari=0;    
    }
    return 1;
}
int main()
{
    ll t, i, n, m, j,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<ll>par,imp;
        vector<vector<ll>>v(n,vector<ll>(m));
        for(i=0; i<n*m; i++)
        {
            cin >> x;
            if(x%2==0)
            {
                par.push_back(x);
            }
            else
            {
                imp.push_back(x);
            }
        }
        if(imppar(imp,par,n,m,0,v))
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    cout << v[i][j] << ' ';
                }
                cout << '\n';
            }
        }
        else if(imppar(imp,par,n,m,1,v))
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    cout << v[i][j] << ' ';
                }
                cout << '\n';
            }
        }
        else
        {
            cout << -1 << '\n';
        }
        
    }
    return 0;
}