//Link: https://codeforces.com/problemset/problem/1117/C
#include<bits/stdc++.h>
using namespace std;
long long x, y, x2, y2, n, i;
string s="";
vector<pair<long long,long long>>v;
long long can(long long j)
{
    long long aX=x, aY=y, rep,dis,in=j;
    rep=j/n;
    aX+=v[n-1].first*rep;
    aY+=v[n-1].second*rep;

    j%=n;
    if(j>0) {
        aX+=v[j-1].first;
        aY+=v[j-1].second;
    }
    dis=abs(aX-x2);
    dis+=abs(aY-y2);
    return (dis-in);
}
int main()
{
    cin >> x >> y >> x2 >> y2 >> n >> s;
    v.resize(s.size(), {0,0});
    switch(s[0])
    {
    case 'U':
        v[0]= {0,1};
        break;
    case 'D':
        v[0]= {0,-1};
        break;
    case 'L':
        v[0]= {-1,0};
        break;
    case 'R':
        v[0]= {1,0};
        break;
    }
    for(i=1; i<n; i++)
    {
        v[i]=v[i-1];
        switch(s[i])
        {
        case 'U':
            v[i].second++;
            break;
        case 'D':
            v[i].second--;
            break;
        case 'L':
            v[i].first--;
            break;
        case 'R':
            v[i].first++;
            break;
        }
    }
    long long mi=0, ma=1e16, piv, pos=-1;
    long long res;
    bool q;

    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        res=can(piv);

        if(res<=0)
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