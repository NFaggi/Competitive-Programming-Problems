#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
 
ll n, mid, l, r, L, R, piv;
 
ll query(ll x)
{
    char ans;
    cout << "? " << x << endl;
    cin >> ans;
    return (ans=='B') ? 1 : 0;
}
void res(ll x)
{
    cout << "! " << x << endl;
}
 
void der()
{
    while(R-L>2)
    {
        mid=(R+L-1)/2;
        piv=query(mid);
        if(mid%2!=L%2&&piv==l||mid%2==L%2&&piv!=l)
        {
            R=mid;
            r=piv;
        }
        else
        {
            L=mid;
            l=piv;
        }
    }
    if(L+1==R)
    {
        res(L);
    }
    else if(R-L==2)
    {
        mid=R-1;
        piv=query(mid);
        if(piv==r)
        {
            res(mid);
        }
        else
        {
            res(L);
        }
    }
    else
    {
        mid=L+1;
        piv=query(mid);
        if(piv==l)
        {
            res(L);
        }
        else
        {
            res(mid);
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    L=1;
    mid=n/2;
    R=mid;
    l=query(1);
    r=query(mid);
    if(mid%2==0&&l==r||mid%2!=0&&l!=r)
    {
        der();
    }
    else
    {
        L=n+1;
        swap(L,R);
        swap(l,r);
        der();
    }
    return 0;
}
