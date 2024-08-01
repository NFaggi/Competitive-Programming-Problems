#include <bits/stdc++.h>

using namespace std;
vector<long long>segt,I,D;
void update(long long nod, long long x)
{
    segt[nod]=x;
    nod/=2;
    while(nod>0)
    {
        segt[nod]=max(segt[nod],x);
        nod/=2;
    }
}
long long cal(long long a, long long b, long long nod)
{
    if(I[nod]>b||D[nod]<a)
    return 0;
    else if(I[nod]>=a&&D[nod]<=b)
    {
        return segt[nod];
    }
    return max(cal(a,b,nod*2),cal(a,b,nod*2+1));
}

int main()
{
    long long n, i, pot=1, sum;
    cin >> n;
    vector<long long>h(n),a(n);
    for(i=0; i<n; i++)
    {
        cin >> h[i];
    }
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    while(pot<n)
    {
        pot*=2;
    }
    segt.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<I.size(); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    long long ma=0;
    for(i=0; i<n; i++)
    {
        sum=cal(pot,pot+(h[i]-1),1)+a[i];
        update(pot+(h[i]-1),sum);
        ma=max(ma,sum);
    }
    cout << ma;
    return 0;
}