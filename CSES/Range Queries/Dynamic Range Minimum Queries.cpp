#include <bits/stdc++.h>
#define INF LONG_MAX
using namespace std;
vector<long long>v;
vector<long long>I;
vector<long long>D;
void update(long long pos)
{
    long long mi=min(v[pos*2+1],v[pos*2]);
    if(v[pos]!=mi)
    {
        v[pos]=mi;
        if(pos!=1)
        {
            update(pos/2);
        }
    }
}
long long buscMin(long long a, long long b, long long nodo)
{
    if(a>D[nodo]||b<I[nodo])
        return INF;
    if(a<=I[nodo]&&b>=D[nodo])
        return v[nodo];
    return min(buscMin(a,b,nodo*2),buscMin(a,b,nodo*2+1));
 
}
int main()
{
    long long n, pot=1, i, q;
    cin >> n >> q;
    while(pot<n)
        pot*=2;
    v.resize(pot*2,INF);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot+n; i++)
    {
        cin >> v[i];
    }
    for(i=pot; i<I.size(); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        v[i]=min(v[i*2],v[i*2+1]);
    }
    while(q--)
    {
        long long a, b, c, pos;
        cin >> a >> b >> c;
        if(a==1)
        {
            pos=b+pot-1;
            if(c!=v[pos])
            {
                v[pos]=c;
                update(pos/2);
            }
        }
        else
        {
            cout << buscMin(b+pot-1, c+pot-1, 1) << endl;
        }
    }
    return 0;
}
