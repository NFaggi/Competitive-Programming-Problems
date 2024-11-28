//Link: https://codeforces.com/problemset/problem/289/B
#include <bits/stdc++.h>
#define ll int
using namespace std;
const int MAXN=1e4+1;
ll tam, v[MAXN], memo[MAXN], d, in;
ll f(ll x)
{
    ll i, calc, tot=0;
    for(i=0; i<tam; i++)
    {
        calc=abs(v[i]-x);
        tot+=calc/d;
    }
    return tot;
}
int main()
{
    ll n, m, i, j, mi,ant, difs=0, pos=1, num, ma, res=INT_MAX, piv,c;
    cin >> n >> m >> d;
    tam=n*m;
    for(i=0; i<tam; i++)
    {
        cin >> v[i];
        if(i>0)
        {
            if(ant!=v[i])
                difs=1;
            if(mi!=v[i]%d)
                pos=0;
        }
        mi=v[i]%d;
        ant=v[i];
    }
    if(difs==0)
    {
        cout << 0;
        return 0;
    }
    if(pos==0)
    {
        cout << -1;
        return 0;
    }
    in=mi;
    num=d+mi;
    for(i=0; i<MAXN; i++)
    {
        memo[i]=num;
        ma=i;
        num+=d;
        if(num>MAXN)
            break;
    }
    mi=0;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        c=f(memo[piv]);
        res=min(res,c);
        if(mi==ma)
        {
            break;
        }
        if(c>f(memo[piv+1]))
        {
            mi=piv+1;
        }
        else
        {
            ma=piv-1;
        }
    }
    cout << res;
    return 0;
}
