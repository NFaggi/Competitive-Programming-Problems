//Link: https://codeforces.com/contest/126/problem/B
#include<bits/stdc++.h>
using namespace std;
vector<int>lps;
pair<int,int> cLPS(string & x)
{
    int i=1, n=x.size(), len=0;
    lps.resize(n,0);
    while(i<n)
    {
        if(x[i]==x[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                i++;
            }
        }
    }
    return {lps[n-1],lps[lps[n-1]-1]};
}

bool ma(string & a, string & b)
{
    int i=0, j=0, n=a.size(), m=b.size(), cant=0;
    while(i<n)
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            j=lps[j-1];
            cant++;
            return true;
        }
        else if(i<n&&a[i]!=b[j])
        {
            if(j>0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return false;
}

int main()
{
    int i;
    pair<int,int>tam;
    string b, a="", B;
    cin >> b;
    B=b;
    tam= cLPS(b);
    if(tam.first>0)
    {

        for(i=0; i<tam.first; i++)
            a+=b[i];
        b.pop_back();
        reverse(b.begin(),b.end());
        b.pop_back();
        reverse(b.begin(),b.end());
        if(ma(b,a))
            cout << a;
        else if(tam.second>0)
        {
            a="";
            b=B;
            for(i=0; i<tam.second; i++)
                a+=b[i];
            b.pop_back();
            reverse(b.begin(),b.end());
            b.pop_back();
            reverse(b.begin(),b.end());
            if(ma(b,a))
                cout << a;
            else
                cout << "Just a legend";
        }
        else
            cout << "Just a legend";
    }
    else
        cout << "Just a legend";
    return 0;
}
