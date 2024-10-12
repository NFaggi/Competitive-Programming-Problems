//Link: https://juez.oia.unsam.edu.ar/task/116
//Score: 100/100
#include <bits/stdc++.h>
using namespace std;
struct bald
{
    int pos, a, b;
};
int sendero(int B, int G, int N, string &baldosas)
{
    vector<vector<int>>v(baldosas.size(),vector<int>(3,2e9+1));
    vector<vector<int>>ant(baldosas.size(),vector<int>(3,-1));
    int i, n=int(baldosas.size()), emp=0, mi;
    bald in;
    in.pos=0;
    in.a=1;
    in.b=2;
    vector<bald>c(26,in);
    in.pos=1;
    in.a=0;
    c['G'-'A']=in;
    in.b=1;
    in.pos=2;
    c['N'-'A']=in;
    if(baldosas[0]=='R')
    {
        v[0][0]=B;
        v[0][1]=G;
        v[0][2]=N;
    }
    else
    {
        v[0][c[baldosas[0]-'A'].pos]=0;
    }
    for(i=1; i<n; i++)
    {
        if(baldosas[i]=='R')
        {
            v[i][0]=v[i-1][1];
            ant[i][0]=1;
            if(v[i][0]>v[i-1][2])
            {
                v[i][0]=v[i-1][2];
                ant[i][0]=2;
            }
            v[i][0]+=B;
            v[i][1]=v[i-1][0];
            ant[i][1]=0;
            if(v[i][1]>v[i-1][2])
            {
                v[i][1]=v[i-1][2];
                ant[i][1]=2;
            }
            v[i][1]+=G;
            v[i][2]=v[i-1][1];
            ant[i][2]=1;
            if(v[i][2]>v[i-1][0])
            {
                v[i][2]=v[i-1][0];
                ant[i][2]=0;
            }
            v[i][2]+=N;
        }
        else
        {
            v[i][c[baldosas[i]-'A'].pos]=v[i-1][c[baldosas[i]-'A'].a];
            ant[i][c[baldosas[i]-'A'].pos]=c[baldosas[i]-'A'].a;
            if(v[i][c[baldosas[i]-'A'].pos]>v[i-1][c[baldosas[i]-'A'].b])
            {
                v[i][c[baldosas[i]-'A'].pos]=v[i-1][c[baldosas[i]-'A'].b];
                ant[i][c[baldosas[i]-'A'].pos]=c[baldosas[i]-'A'].b;
            }
        }
    }

    mi=v[n-1][0];
    if(mi>v[n-1][1])
    {
        mi=v[n-1][1];
        emp=1;
    }
    if(mi>v[n-1][2])
    {
        mi=v[n-1][2];
        emp=2;
    }
    int act=emp;
    string s="";
    for(i=n-1; i>=0; i--)
    {
        if(act==0)
            s+='B';
        else if(act==1)
            s+='G';
        else
            s+='N';
        act=ant[i][act];
    }
    reverse(s.begin(),s.end());
    baldosas=s;
    return mi;
}
