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
    ll n, i, j, m, k;
    cin >> n >> m;
    vector<string>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            vector<bool>prob(4,0);
            prob[v[i][j]-'A']=1;
            if(i>0)
                prob[v[i-1][j]-'A']=1;
            if(j>0)
                prob[v[i][j-1]-'A']=1;
            for(k=0; k<4; k++)
                if(prob[k]==0)
                {
                    v[i][j]=char('A'+k);
                    break;
                }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            cout << v[i][j];
        cout << '\n';
    }
    return 0;
}

