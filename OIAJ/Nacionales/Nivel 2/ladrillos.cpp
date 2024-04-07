//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/70
#include <bits/stdc++.h>
using namespace std;
 
pair<long long, long long> calc(long long v1, long long v2, long long cX)
{
    long long res;
    if(cX==1)
    {
        return {1,0};
    }
    else if(cX==2)
    {
        return {1,v1};
    }
    pair<long long, long long> p1;
    pair<long long, long long> p2;
    p1=calc(v1,v2,cX-1);
    p2=calc(v1,v2,cX-2);
    return {p1.first+p2.first,p1.second+p2.second};
}
 
int main() {
    ifstream en ("ladrillos.in");
    ofstream sa ("ladrillos.out");
    long long n, i, cant=0, pos1, pos2;
    en >> n;
    vector <string> v(n);
    vector <long long>res(n);
    for(i=0; i<n; i++)
    {
        en >> v[i];
        if(v[i]!="*")
        {
            cant++;
            if(cant==1)
            {
                pos1=i;
            }
            else if(cant==2)
            {
                pos2=i;
            }
        }
    }
    if(cant==0)
    {
        if(res.size()>=1)
            res[0]=0;
        if(res.size()>1)
            res[1]=1;
        for(i=2; i<n; i++)
        {
            res[i]=res[i-1]+res[i-2];
        }
    }
    else if(cant==1)
    {
        long long sig = stoi(v[pos1])+stoi(v[pos1])/2;
        res[pos1]=stoi(v[pos1]);
        for(i=pos1+1; i<n; i++)
        {
            if(i==pos1+1)
                res[i]=sig;
            else
                res[i]=res[i-1]+res[i-2];
        }
        for(i=pos1-1; i>=0; i--)
        {
            if(i==pos1-1)
                res[i]=sig-res[i+1];
            else
                res[i]=res[i+2]-res[i+1];
        }
    }
    else
    {
        res[pos1]=stoi(v[pos1]);
        long long sig;
        if(pos2-pos1<2)
            sig=stoi(v[pos2]);
        else if(pos2-pos1==2)
            sig=stoi(v[pos2])-stoi(v[pos1]);
        else
        {
 
            pair<long long, long long> p1;
            p1 = calc(stoi(v[pos1]),stoi(v[pos2]), pos2-pos1);
            sig=(stoi(v[pos2])-p1.second)/p1.first;
        }
        res[pos1+1]=sig;
        for(i=pos1+2; i<n; i++)
        {
            if(v[i]=="*")
            {
                res[i]=res[i-1]+res[i-2];
            }
            else
            {
                res[i]=stoi(v[i]);
            }
        }
        for(i=pos1-1; i>=0; i--)
        {
            if(v[i]=="*")
            {
                res[i]=res[i+2]-res[i+1];
            }
            else
            {
                res[i]=stoi(v[i]);
            }
        }
    }
    for(i=0; i<n; i++)
        sa << res[i] << " ";
    return 0;
}
