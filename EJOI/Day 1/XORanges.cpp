//Link: https://oj.uz/problem/view/eJOI19_xoranges
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>st1,st2,I,D;

void update1(ll x, ll nod)
{
    st1[nod]=x;
    nod/=2;
    while(nod>0)
    {
        st1[nod]=st1[nod*2]^st1[nod*2+1];
        nod/=2;
    }
}

void update2(ll x, ll nod)
{
    st2[nod]=x;
    nod/=2;
    while(nod>0)
    {
        st2[nod]=st2[nod*2]^st2[nod*2+1];
        nod/=2;
    }
}

ll calc1(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return st1[nod];
    return calc1(a,b,nod*2)^calc1(a,b,nod*2+1);
}

ll calc2(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return st2[nod];
    return calc2(a,b,nod*2)^calc2(a,b,nod*2+1);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, j, k, q, x, pot=1, tam, op, l, r;
    cin >> n >> q;
    while(pot<n)
        pot*=2;
    st1.resize(pot*2,0);
    st2.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=0; i<n; i++)
    {
        cin >> x;
        if(i%2==0)
            update1(x,i+pot);
        else
            update2(x,i+pot);
    }
    for(i=pot; i<pot*2; i++)
        I[i]=D[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    while(q--)
    {
        cin >> op;
        if(op==1)
        {
            cin >> i >> x;
            i--;
            if(i%2==0)
                update1(x,i+pot);
            else
                update2(x,i+pot);
        }
        else
        {
            cin >> l >> r;
            tam=(r-l)+1;
            l--;
            r--;
            if(tam%2==0)
                cout << 0 << '\n';
            else
            {
                if(l%2==0)
                {
                    cout << calc1(l+pot,r+pot,1) << '\n';
                }
                else
                {
                    cout << calc2(l+pot,r+pot,1) << '\n';
                }
            }
        }
    }
    return 0;
}
