//Link: https://codeforces.com/contest/2036/problem/D
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s="1543";
void calcular(vector<vector<ll>>&capas,vector<string>&v,ll miI, ll maI, ll miM, ll maM)
{
    ll i, j;
    for(i=miI; i<=maI; i++)
    {
        if(v[i][miM]==s[0])
        {
            capas[i][miM]=1;
        }
        if(v[i][maM]==s[0])
        {
            capas[i][maM]=1;
        }
    }
    for(i=miM; i<=maM; i++)
    {
        if(v[miI][i]==s[0])
        {
            capas[miI][i]=1;
        }
        if(v[maI][i]==s[0])
        {
            capas[maI][i]=1;
        }
    }
    for(j=0; j<3; j++)
    {
        for(i=miI; i<=maI; i++)
        {
            if(i-1>=miI&&v[i-1][miM]==s[j+1]&&v[i][miM]==s[j])
            {
                capas[i-1][miM]=capas[i][miM];
            }
            if(i+1<=maI&&v[i+1][maM]==s[j+1]&&v[i][maM]==s[j])
            {
                capas[i+1][maM]=capas[i][maM];
            }
        }
        for(i=miM; i<=maM; i++)
        {
            if(i-1>=miM&&v[maI][i-1]==s[j+1]&&v[maI][i]==s[j])
            {
                capas[maI][i-1]=capas[maI][i];
            }
            if(i+1<=maM&&v[miI][i+1]==s[j+1]&&v[miI][i]==s[j])
            {
                capas[miI][i+1]=capas[miI][i];
            }
        }
    }
}
int main()
{
    ll t, n, m, miI, maI, miM, maM, i, j, calc;
    cin >> t;
    while(t--)
    {
        calc=0;
        cin >> n >> m;
        miI=0;
        maI=n-1;
        miM=0;
        maM=m-1;
        vector<string>v(n);
        vector<vector<ll>>capas(n,vector<ll>(m,0));
        for(i=0; i<n; i++)
        {
            cin >> v[i];
        }
        while(miI<=maI&&miM<=maM)
        {
            calcular(capas, v,miI,maI,miM, maM);
            miI++;
            maI--;
            miM++;
            maM--;
        }
        for(i=0; i<int(capas.size()); i++)
        {
            for(j=0; j<int(capas[i].size()); j++)
            {
                if(capas[i][j]==1&&v[i][j]=='3')
                {
                    calc++;
                }
            }
        }
        cout << calc << '\n';

    }
    return 0;
}