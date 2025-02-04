//Link: https://juez.oia.unsam.edu.ar/task/115
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int medir(string cad);

string subtask1(int &N)
{
    string res="", s="";
    ll mi=0, ma=N, piv, pos=0, i;
    for(i=0; i<N; i++)
        s+='A';
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(medir(s.substr(0,piv)))
        {
            mi=piv+1;
            pos=max(pos,piv);
        }
        else
            ma=piv-1;
    }
    for(i=pos; i<N; i++)
        s[i]='C';
    return s;
}
string subtask2y3(int N=10)
{
    string res="", s="";
    ll mi=0, ma=N, piv, pos=0, i, j=0;
    for(i=0; i<N; i++)
        s+='G';
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(medir(s.substr(0,piv)))
        {
            mi=piv+1;
            pos=max(pos,piv);
        }
        else
            ma=piv-1;
    }
    while(int(s.size())>pos)
        s.pop_back();
    while(int(s.size())<N)
    {
        if(j<int(s.size())&&medir(s.substr(0,j)+'T'+s.substr(j,int(s.size())-j)))
            s=s.substr(0,j)+'T'+s.substr(j,int(s.size())-j);
        else if(j>=int(s.size()))
            s+='T';
        j++;
    }
    return s;
}

string subtask4(int &N, string &s)
{
    ll i, mi, ma, n=N, piv, c,j;
    string res="";
    vector<string>v(4,"");
    vector<char>ch={'A','C','G','T'};
    vector<ll>cant(4,0);
    for(i=0; i<N; i++)
    {
        v[0]+='A';
        v[1]+='C';
        v[2]+='G';
        v[3]+='T';
    }
    priority_queue<pair<ll,ll>>pq;
    for(i=0; i<4; i++)
    {
        mi=0;
        ma=n;
        while(mi<=ma)
        {
            piv=(mi+ma)/2;
            if(medir(v[i].substr(0,piv)))
            {
                mi=piv+1;
                cant[i]=max(piv,cant[i]);
            }
            else
                ma=piv-1;
        }
        n-=cant[i];
        pq.push({-cant[i],i});
    }

    c=pq.top().second;
    pq.pop();
    res=v[c].substr(0,cant[c]);
    while(pq.size())
    {
        j=0;
        c=pq.top().second;
        pq.pop();
        while(cant[c]>0)
        {
            if(j<int(res.size())&&medir(res.substr(0,j)+ch[c]+res.substr(j,int(res.size())-j)))
            {
                res=res.substr(0,j)+ch[c]+res.substr(j,int(res.size())-j);
                cant[c]--;
            }
            else if(j>=int(res.size()))
            {
                res+=ch[c];
                cant[c]--;
            }
            j++;
        }
    }
    return res;
}

string subtask5(int &N, string &s)
{
    ll i, mi, ma, n=N, piv, c,j;
    string res="", a, b;
    vector<string>v(52,"");
    vector<char>ch;
    for(char l='a'; l<='z'; l++)
        ch.push_back(l);
    for(char l='A'; l<='Z'; l++)
        ch.push_back(l);
    vector<ll>cant(52,0);
    for(i=0; i<N; i++)
    {
        for(j=0; j<52; j++)
        {
            v[j]+=ch[j];
        }
    }
    priority_queue<pair<ll,string>>pq;
    for(i=0; i<51; i++)
    {
        mi=1;
        ma=n;
        if(n==0)
            break;
        if(medir(v[i].substr(0,1))==0)
           continue;
        while(mi<=ma)
        {
            piv=(mi+ma)/2;
            if(medir(v[i].substr(0,piv)))
            {
                mi=piv+1;
                cant[i]=max(piv,cant[i]);
            }
            else
                ma=piv-1;
        }
        n-=cant[i];
        pq.push({-cant[i],v[i].substr(0,cant[i])});
    }
    cant[51]=n;
    pq.push({-cant[51],v[51].substr(0,n)});
    while(pq.size()>1)
    {
        i=0;
        j=0;
        a=pq.top().second;
        pq.pop();
        b=pq.top().second;
        pq.pop();
        res="";
        while(res.size()<a.size()+b.size())
        {
            if(i<int(b.size())&&(j==int(a.size())||medir(res+b[i]+a.substr(j,int(a.size())-j))))
            {
                res+=b[i];
                i++;
            }
            else
            {
                res+=a[j];
                j++;
            }
        }
        pq.push({-int(res.size()),res});
    }
    res=pq.top().second;
    return res;
}


string secuenciar(int N, string s)
{
    int k=s.size();
    string res;
    if(k==2&&s[0]=='A'&&s[1]=='C')
        res=subtask1(N);
    else if(k==2&&s[0]=='G'&&s[1]=='T'&&N==10)
        res=subtask2y3();
    else if(k==2&&s[0]=='G'&&s[1]=='T')
        res=subtask2y3(N);
    else if(k==4)
        res=subtask4(N,s);
    else
        res=subtask5(N,s);
    return res;
}
