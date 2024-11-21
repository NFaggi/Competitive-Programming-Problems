//Link: https://codeforces.com/gym/105047/problem/D
//Score: 100/100
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>seg,I,D;
ll pot;
void update(ll x, ll nod)
{
    seg[nod]=x;
    nod/=2;
    while(nod>0)
    {
        seg[nod]=min(seg[nod*2],seg[nod*2+1]);
        nod/=2;
    }
}
ll calc(ll a, ll b, ll x, ll nod)
{
    if(I[nod]>b||D[nod]<a)
    {
        return -2;
    }
    if(seg[nod]>x)
        return -1;
    if(nod>=pot)
    {
        return (nod-pot)+1;
    }
    ll res;
    if(seg[nod*2]<=x)
    {
        res= calc(a,b,x,nod*2);
        if(res>-2)
            return res;
    }
    return calc(a,b,x,nod*2+1);
}
int main()
{
    ll t, n, q, i,mi,pos,x,sum,ant, op, y;
    cin >> t;
    while(t--)
    {
        sum=0;
        mi=LLONG_MAX;
        pot=1;
        pos=0;
        cin >> n >> q;
        while(pot<n)
            pot*=2;
        seg.resize(0);
        seg.resize(pot*2,LLONG_MAX);
        I.resize(0);
        D.resize(0);
        I.resize(pot*2);
        D.resize(pot*2);
        for(i=pot; i<int(I.size()); i++)
        {
            I[i]=i;
            D[i]=i;
        }
        for(i=0; i<n; i++)
        {
            cin >> seg[i+pot];
        }
        for(i=pot-1; i>0; i--)
        {
            I[i]=I[i*2];
            D[i]=D[i*2+1];
            seg[i]=min(seg[i*2],seg[i*2+1]);
        }

        while(q--)
        {
            cin >> op >> x;
            if(op==1)
            {
                ant=1;
                pos=0;
                sum=0;
                while(pos<n)
                {
                    pos=calc(pos+pot,int(I.size())-1,x,1);
                    if(pos==-1)
                        pos=n+1;
                    sum+=((pos)-ant)*x;
                    x=x%seg[(pos-1)+pot];
                    ant=pos;
                    pos--;
                }
                cout << sum << '\n';
            }
            else
            {
                cin >> y;
                update(y,(x-1)+pot);
            }
        }
    }
    return 0;
}
