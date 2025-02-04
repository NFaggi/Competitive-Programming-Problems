//Link: https://juez.oia.unsam.edu.ar/task/159
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

int editora(vector<int> &tinta, vector<long long> &articulos, string &ordenamiento)
{
    string cad="";
    vector<int>dp(1<<int(articulos.size()),INT_MAX);
    vector<int>dpA(1<<int(articulos.size()));
    vector<long long>in(1<<int(articulos.size()));
    vector<int>costs(1<<int(articulos.size()));
    vector<char>cam(1<<int(articulos.size()));
    int i, j,cost,ti;
    long long ind;
    dp[0]=0;
    dpA[0]=-1;
    in[0]=1;
    for(i=0; i<int(dp.size()); i++)
    {
        for(j=0; j<int(articulos.size()); j++)
        {
            if((i&(1<<j))>0)
                continue;
            in[(i|(1<<j))]=in[i]+articulos[j];
        }
    }
    for(i=0; i<int(in.size()); i++)
    {
        long long cost=0;
        ind=in[i];
        while(ind>0)
        {
            ti=ind%10;
            cost+=tinta[ti];
            ind/=10;
        }
        costs[i]=cost;
    }
    for(i=0; i<int(dp.size())-1; i++)
    {
        if(dp[i]==INT_MAX)
            continue;
        for(j=0; j<int(articulos.size()); j++)
        {
            if((i&(1<<j))>0)
                continue;
            cost=costs[i];
            if(dp[(i|(1<<j))]>dp[i]+cost)
            {
                dp[(i|(1<<j))]=dp[i]+cost;
                dpA[(i|(1<<j))]=i;
                cam[(i|(1<<j))]='A'+j;
            }
        }
    }
    int sig=int(dp.size())-1;
    string ne="";
    while(sig>=0)
    {
        cad+=cam[sig];
        sig=dpA[sig];
    }
    for(i=int(cad.size())-2; i>=0; i--)
    {
        ne+=cad[i];
    }
    ordenamiento=ne;
    return dp[int(dp.size())-1];
}
