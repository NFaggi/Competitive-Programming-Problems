//Link: https://codeforces.com/contest/1244/problem/E
#include <bits/stdc++.h>
using namespace std;
vector<long long>v;
vector<long long>up,down;
long long k, n;
bool can(long long piv)
{
    long long i,dis,mi,ma,mid,pos;
    for(i=0; i<n; i++)
    {
        dis=down[i];
        mi=0;
        ma=n-1;
        pos=n-1;
        while(mi<=ma)
        {
            mid=(mi+ma)/2;
            if(v[i]+piv<v[mid])
            {
                pos=mid;
                ma=mid-1;
            }
            else
            {
                mi=mid+1;
            }
        }
        if(v[pos]>v[i]+piv)
            dis+=up[pos]+abs(v[pos]-(v[i]+piv))*(n-(pos));
        if(dis<=k)
            return true;
    }
    for(i=n-1; i>=0; i--)
    {
        dis=up[i];
        mi=0;
        ma=n-1;
        pos=n-1;
        while(mi<=ma)
        {
            mid=(mi+ma)/2;
            if(v[i]-piv>v[mid])
            {
                pos=mid;
                mi=mid+1;
            }
            else
            {
                ma=mid-1;
            }
        }
        if(v[pos]<v[i]-piv)
            dis+=down[pos]+abs((v[i]-piv)-v[pos])*(pos+1);
        if(dis<=k)
            return true;
    }
    return false;
}
int main()
{
    long long i, mi=0, ma=1e9, piv,pos=10;
    cin >> n >> k;
    v.resize(n);
    up.resize(n);
    down.resize(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for(i=1; i<n; i++)
    {
        down[i]=(v[i]-v[i-1])*(i)+down[i-1];
    }
    for(i=n-2; i>=0; i--)
    {
        up[i]=(v[i+1]-v[i])*(n-(i+1))+up[i+1];
    }
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(piv))
        {
            ma=piv-1;
            pos=piv;
        }
        else
        {
            mi=piv+1;
        }
    }
    cout << pos;
    return 0;
}
