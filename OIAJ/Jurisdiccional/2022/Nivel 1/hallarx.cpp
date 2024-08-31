//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/66
#include <bits/stdc++.h>

using namespace std;
string sum(string a, string b, int c)
{
    if(a.size()<b.size())
        swap(a,b);
    string su;
    su.resize(c,'0');
    int sob=0, j=b.size()-1, pos=0;
    for(int i=min(int(a.size())-1,c); i>=0; i--)
    {
        if(j>=0)
            sob+=a[i]-'0'+b[j]-'0';
        else
            sob+=a[i]-'0';
        if(sob<=9)
        {
            su[pos]=sob+'0';
            sob=0;
        }
        else
        {
            su[pos]=(sob%10)+'0';
            sob/=10;
        }
        pos++;
        j--;
    }
    while(sob>0)
    {
        if(su.size()<=pos)
        {
            while(sob>0)
            {
                if(sob<=9)
                {
                    su+=sob+'0';
                    sob=0;
                }
                else
                {
                    su+=(sob%10)+'0';
                    sob/=10;
                }
            }
        }
        else
        {

            if(sob<=9)
            {
                su[pos]=sob+'0';
                sob=0;
            }
            else
            {
                su[pos]=(sob%10)+'0';
                sob/=10;
            }
            pos++;
        }
    }
    reverse(su.begin(),su.end());
    return su;
}
int hallarx(string &a, string &b, string &c)
{
    bool e=false;
    int i=0, px=0, ps=0;
    string s="";
    for(i=0; i<a.size(); i++)
    {
        if(a[i]=='x')
        {
            ps=0;
            px=i;
            e=true;
            break;
        }
    }
    if(!e)
    {
        for(i=0; i<b.size(); i++)
        {
            if(b[i]=='x')
            {
                ps=1;
                px=i;
                e=true;
                break;
            }
        }
    }
    if(!e)
    {
        for(i=0; i<c.size(); i++)
        {
            if(c[i]=='x')
            {
                ps=2;
                px=i;
                e=true;
                break;
            }
        }
    }
    if(ps==0)
    {
        for(i=0; i<=9; i++)
        {
            a[px]=(i+'0');
            s=sum(a,b,c.size());
            if(s==c)
            {
                return i;
            }

        }
    }
    else if(ps==1)
    {
        for(i=0; i<=9; i++)
        {
            b[px]=(i+'0');
            s=sum(a,b,c.size());
            if(s==c)
            {
                return i;
            }

        }
    }
    else if(ps==2)
    {
        for(i=0; i<=9; i++)
        {
            c[px]=(i+'0');
            s=sum(a,b,c.size());
            if(s==c)
            {
                return i;
            }

        }
    }
    return -1;
}
