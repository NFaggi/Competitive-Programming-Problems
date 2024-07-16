//link: https://oj.uz/problem/view/IOI19_transfer
//score: 100/100
#include <bits/stdc++.h>
#define SIZE(x) int(x.size())
using namespace std;
std::vector<int> get_attachment(std::vector<int> source)
{
    vector<int>cal;
    vector<int>ag, ag2;
    int pot=1, i, pos=0,cP=0, j, un;
    for(i=0; pos<SIZE(source); i++)
    {
        if(i+1==pot)
        {
            pot*=2;
            cP++;
            cal.push_back(2);
        }
        else
        {
            cal.push_back(source[pos]);
            pos++;
        }
    }
    pot=1;
    for(i=0; i<cP; i++)
    {
        un=0;
        for(j=pot-1; j<SIZE(cal); j++)
        {
            if((j+1)&pot)
            {
                if(cal[j]==1)
                    un++;
            }
        }
        if(un%2==0)
            ag.push_back(0);
        else
            ag.push_back(1);
        pot*=2;
 
    }
    for(i=SIZE(ag)-1; i>=0; i--)
    {
        ag2.push_back(ag[i]);
    }
    return ag2;
}
 
std::vector<int> retrieve(std::vector<int> data)
{
    vector<int>ret(SIZE(data)), comp(SIZE(data)), ag, ag2;
    int pot=1, pos=0, i, cP=0, j, un;
    for(i=0; i<SIZE(ret); i++)
    {
        if(i+1==pot)
        {
            ret[i]=data[SIZE(data)-1];
            comp[i]=2;
            cP++;
            ag2.push_back(ret[i]);
            data.pop_back();
            pot*=2;
        }
        else
        {
            ret[i]=data[pos];
            comp[i]=ret[i];
            pos++;
        }
    }
    pot=1;
    for(i=0; i<cP; i++)
    {
        un=0;
        for(j=pot-1; j<SIZE(comp); j++)
        {
            if((j+1)&pot)
            {
                if(comp[j]==1)
                    un++;
            }
        }
        if(un%2==0)
            ag.push_back(0);
        else
            ag.push_back(1);
        pot*=2;
 
    }
    vector<bool>bus(cP,1);
    for(i=0; i<SIZE(ag); i++)
    {
        if(ag[i]!=ag2[i])
        {
            bus[i]=0;
        }
    }
    pot=1;
    int arr=0;
    for(auto k:bus)
    {
        if(k==0)
        {
            arr=arr|pot;
        }
        pot*=2;
    }
    for(i=0; i<SIZE(ret); i++)
    {
        if(i+1==arr)
        {
            ret[i]=!ret[i];
        }
    }
    vector<int>ans;
    pot=1;
    for(i=0; i<SIZE(ret); i++)
    {
        if(i+1==pot)
        {
            pot*=2;
        }
        else
        {
            ans.push_back(ret[i]);
        }
    }
    return ans;
}
