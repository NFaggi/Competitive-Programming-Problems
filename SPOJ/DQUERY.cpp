//Link: https://www.spoj.com/problems/DQUERY/
#include<bits/stdc++.h>
using namespace std;
int dp[int(1e6+1)];
bool comp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b)
{
    return a.first < b.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, i, tam, a, b, cant=0,j;
    cin >> n;
    tam=sqrt(n);
    vector<int> v(n);
    vector<vector<pair<int,pair<int,int>>>>sq(tam+1);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    cin >> q;
    vector<int>queries(q);
    i=0;
    while(q--)
    {
        cin >> a >> b;
        sq[a/tam].push_back({b-1,{a-1,i}});
        i++;
    }
    for(i=0; i<tam+1; i++)
    {
        sort(sq[i].begin(),sq[i].end(), comp);
    }
    bool band=1;
    int in=0, fin=-1;
    for(i=0; i<=tam; i++)
    {
        for(auto k:sq[i])
        {
            if(k.second.first>fin||k.first<in)
                band=1;
            if(band)
            {
                memset(dp,0,sizeof(dp));
                cant=0;
                band=0;
                for(j=k.second.first; j<=k.first; j++)
                {
                    dp[v[j]]++;
                    if(dp[v[j]]==1)
                        cant++;
                }
            }
            else
            {
                a=k.second.first;
                b=k.first;
                if(a<in)
                {
                    for(j=a; j<in; j++)
                    {
                        dp[v[j]]++;
                        if(dp[v[j]]==1)
                            cant++;
                    }
                }
                else if(a>in)
                {
                    for(j=in; j<a; j++)
                    {
                        dp[v[j]]--;
                        if(dp[v[j]]==0)
                            cant--;
                    }
                }
                if(b<fin)
                {
                    for(j=b+1; j<=fin; j++)
                    {
                        dp[v[j]]--;
                        if(dp[v[j]]==0)
                            cant--;
                    }
                }
                else if(b>fin)
                {
                    for(j=fin+1; j<=b; j++)
                    {
                        dp[v[j]]++;
                        if(dp[v[j]]==1)
                            cant++;
                    }
                }
            }
            in=k.second.first;
            fin=k.first;
            queries[k.second.second]=cant;
        }
    }
    for(auto k:queries)
    {
        cout << k << '\n';
    }
    return 0;
}
