//Link: https://juez.oia.unsam.edu.ar/task/161
//Score: 92/100
#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9+9;
long long dp[int(7e5)];
set<int> factorizar(int n)
{
    int cant;
    set<int> factores;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        cant=0;
        while (n % i == 0)
        {
            cant++;
            n /= i;
        }
        if(cant%2==1)
        {
            factores.insert(i);
        }
    }
    if (n > 1)
    {
        factores.insert(n);
    }
    return factores;
}
void factorizar2(set<int>&fact, pair<int ,set<int>>&factores)
{
    for(auto k:fact)
    {
        auto it=factores.second.find(k);
        if(it==factores.second.end())
            factores.second.insert(k);
        else
            factores.second.erase(it);
    }
}
long long perfectos(vector<int> &ronda)
{
    long long cant=0,ma=0, n=ronda.size(), i, j, prim, Hash,k=1,H2;
    dp[0]=1;
    for(i=1; i<int(7e5); i++)
    {
        dp[i]=(dp[i-1]*37ll)%MOD;
    }
    vector<set<int>>fact(n);
    vector<pair<int,int>>in(n),fact2(n);
    for(i=0; i<n; i++)
    {
        fact[i]=factorizar(ronda[i]);
    }
    map<pair<int,int>,long long>s;
    pair<int ,set<int>> ins,ultIns,vacio;
    for(i=0; i<n; i++)
    {
        Hash=0;
        H2=0;
        factorizar2(fact[i],ins);
        j=0;
        for(auto l:ins.second)
        {
            Hash=(Hash+(l*dp[j])%MOD)%MOD;
            H2+=l;
            j++;
        }
        ins.first=Hash;
        s[{ins.first,H2}]+=1ll;
        in[i]={ins.first,H2};
    }
    ultIns=ins;
    cant+=s[{0,0}];
    s[in[0]]--;
    for(i=0; i<n-1; i++)
    {
        factorizar2(fact[i],ultIns);
        Hash=0;
        H2=0;
        j=0;
        for(auto l:ultIns.second)
        {
            Hash=(Hash+(l*dp[j])%MOD)%MOD;
            H2+=l;
            j++;
        }
        ultIns.first=Hash;
        fact2[i]={ultIns.first,H2};
    }
    for(i=1; i<n; i++)
    {
        if(i-2>=0)
        {
            s[fact2[i-2]]+=1ll;
        }
        cant+=s[in[i-1]];
        s[in[i]]-=1ll;
    }
    return cant;
}
