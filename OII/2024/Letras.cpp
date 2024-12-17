//Score: 100/100
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, i, j, a, b, ma;
    string s;
    cin >> n >> s >> q;
    vector<vector<int>>v(n+1,vector<int>(5,n+1));
    vector<vector<int>>bin(n+1,vector<int>(19,n+1));
    vector<int>l(26);
    vector<int> cost(19,1);
    for(i=1; i<19; i++)
    {
        cost[i]=cost[i-1]*2;
    }
    l['a'-'a']=0;
    l['e'-'a']=1;
    l['i'-'a']=2;
    l['o'-'a']=3;
    l['u'-'a']=4;
    for(i=n-1; i>=0; i--)
    {
        v[i][l[s[i]-'a']]=i+1;
        ma=0;
        for(j=0; j<5; j++)
        {
            v[i][j]=min(v[i][j],v[i+1][j]);
            ma=max(ma,v[i][j]);
        }
        bin[i][0]=ma;
    }
    for(j=1; j<19; j++)
    {
        for(i=0; i<=n; i++)
        {
            if(bin[i][j-1]!=n+1)
                bin[i][j]=bin[bin[i][j-1]][j-1];
            else
                break;
        }
    }
    int pos, cant,prox, k,antP;
    while(q--)
    {
        cin >> a >> b;
        cant=0;
        pos=0;
        k=a-1;
        while(true)
        {
            if(bin[k][0]>b)
            {
                cant+=cost[0];
                break;
            }
            antP=0;
            for(i=1; i<19; i++)
            {
                if(bin[k][i]>b)
                    break;
                else
                {
                    antP=i;
                }
            }
            cant+=cost[antP];
            k=bin[k][antP];
        }
        cout << cant << '\n';
    }
    return 0;
}
