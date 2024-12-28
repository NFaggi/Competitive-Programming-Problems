//Link: https://codeforces.com/contest/1799/problem/E
#include <bits/stdc++.h>
#define ll int
#define LLONG_MAX INT_MAX
using namespace std;
vector<string>mat,mat2;
void fillup()
{
    ll n=int(mat.size()), m=int(mat[0].size()), i, j,put;
    vector<ll>cant(m,0);
    for(j=0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            if(mat[i][j]=='#')
                cant[j]++;
        }
    }
    for(j=0; j<m; j++)
    {
        put=0;
        for(i=0; i<n; i++)
        {
            if(cant[j]==0)
                break;
            if(mat[i][j]=='#')
            {
                put=1;
                cant[j]--;
            }
            if(put)
                mat[i][j]='#';
        }
    }
}

void fillright()
{
    ll n=int(mat.size()), m=int(mat[0].size()), i, j,put;
    vector<ll>cant(n,0);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat[i][j]=='#')
                cant[i]++;
        }
    }
    for(i=0; i<n; i++)
    {
        put=0;
        for(j=0; j<m; j++)
        {
            if(cant[i]==0)
                break;
            if(mat[i][j]=='#')
            {
                put=1;
                cant[i]--;
            }
            if(put)
                mat[i][j]='#';
        }
    }
}
void pint(ll x, ll y, ll x2, ll y2)
{
    ll i;
    if(y>y2)
        swap(y,y2);
    for(i=y; i<=y2; i++)
    {
        mat[x][i]='#';
    }
    if(x>x2)
        swap(x,x2);
    for(i=x; i<=x2; i++)
    {
        mat[i][y2]='#';
    }
}
void solve()
{
    ll n, m, i, j;
    cin >> n >> m;
    string s="";
    for(i=0; i<m; i++)
        s+='.';

    mat.resize(0);
    mat.resize(n);
    mat2.resize(0);

    for(i=0; i<n; i++)
        cin >> mat[i];
    fillup();
    fillright();
    fillup();
    fillright();
    mat2=mat;
    queue<pair<ll,ll>>q;
    for(j=0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            if(mat[i][j]=='#')
            {
                q.push({i,j});
                break;
            }
        }
        if(q.size())
            break;
    }
    ll maI=0,maJ=0,miJ=LLONG_MAX,miI=LLONG_MAX;
    while(q.size())
    {
        i=q.front().first;
        j=q.front().second;
        q.pop();
        maI=max(maI,i);
        maJ=max(maJ,j);
        miI=min(miI,i);
        miJ=min(miJ,j);
        mat2[i][j]='.';
        if(i-1>=0&&mat2[i-1][j]=='#')
        {
            q.push({i-1,j});
            mat2[i-1][j]='.';
        }
        if(i+1<n&&mat2[i+1][j]=='#')
        {
            mat2[i+1][j]='.';
            q.push({i+1,j});
        }
        if(j-1>=0&&mat2[i][j-1]=='#')
        {
            q.push({i,j-1});
            mat2[i][j-1]='.';
        }
        if(j+1<m&&mat2[i][j+1]=='#')
        {
            q.push({i,j+1});
            mat2[i][j+1]='.';
        }
    }
    ll cont=0;
    for(i=0; i<n; i++)
    {
        if(mat2[i]!=s)
        {
            cont=1;
        }
    }
    if(cont==0)
    {
        for(i=0; i<n; i++)
        {
            cout << mat[i] << '\n';
        }
        cout << '\n';
        return;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat2[i][j]=='#')
            {
                q.push({i,j});
                break;
            }
        }
        if(q.size())
            break;
    }
    ll maI2=0,maJ2=0,miJ2=LLONG_MAX,miI2=LLONG_MAX;
    while(q.size())
    {
        i=q.front().first;
        j=q.front().second;
        q.pop();
        maI2=max(maI2,i);
        maJ2=max(maJ2,j);
        miI2=min(miI2,i);
        miJ2=min(miJ2,j);
        mat2[i][j]='.';
        if(i-1>=0&&mat2[i-1][j]=='#')
        {
            q.push({i-1,j});
            mat2[i-1][j]='.';
        }
        if(i+1<n&&mat2[i+1][j]=='#')
        {
            mat2[i+1][j]='.';
            q.push({i+1,j});
        }
        if(j-1>=0&&mat2[i][j-1]=='#')
        {
            q.push({i,j-1});
            mat2[i][j-1]='.';
        }
        if(j+1<m&&mat2[i][j+1]=='#')
        {
            q.push({i,j+1});
            mat2[i][j+1]='.';
        }
    }
    if(miI<miI2)
    {
        pint(maI,maJ,miI2,miJ2);
    }
    else
    {
        pint(miI,maJ,maI2,miJ2);
    }
    fillup();
    fillright();
    fillup();
    fillright();
    for(i=0; i<n; i++)
    {
        cout << mat[i] << '\n';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
