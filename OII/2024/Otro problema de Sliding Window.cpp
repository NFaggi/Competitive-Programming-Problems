//Score: 100/100
#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int>v, seg, I, D;
int busMin(int a, int b, int nod)
{
    if(I[nod]>b||D[nod]<a)
        return INT_MAX;
    if(I[nod]>=a&&D[nod]<=b)
        return seg[nod];
    return min(busMin(a,b,nod*2),busMin(a,b,nod*2+1));        
}
int BS(int i)
{
    int mi=i/2, ma=i-1, piv, res=-1,dif;
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        dif=i-piv;
        if(v[piv-(dif-1)]+v[i]<=x)
        {
            mi=piv+1;
            res=piv;
        }
        else
            ma=piv-1;
    }
    return res;
}
int main()
{
cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
    int i, pot=1, q, a, b, piv;
    cin >> n >> x;
    while(pot<n)
        pot*=2;
    v.resize(n);
    seg.resize(pot*2,INT_MAX);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        seg[i+pot]=BS(i);
    }
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
        seg[i]=min(seg[i*2],seg[i*2+1]);
    }
    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        a--;
        b--;
        if(a==b)
        {
            if(v[a]<=x)
                cout << 1;
            else
                cout << 0;
            continue;       
        }
        if((b-a)%2==0)
        {
            if(v[b]>x)
            {
                cout << 0;
                continue;
            }
            b--;
        }
        piv=(a+b)/2;
        if(busMin(piv+1+pot,b+pot,1)>=piv)
            cout << 1;
        else
            cout << 0;  
    }
    return 0;
}
