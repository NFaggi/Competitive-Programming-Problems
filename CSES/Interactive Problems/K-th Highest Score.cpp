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

const int MAXN=1e5+1;

ll memoF[MAXN], memoS[MAXN], n, k;
ll consF(ll x)
{
    if(x>n)
        return 0;
    if(x==0)
        return LLONG_MAX;
    if(memoF[x])
        return memoF[x];
    cout << "F " << x << endl;
    cin >> memoF[x];
    return memoF[x];
}

ll consS(ll x)
{
    if(x>n)
        return 0;
    if(x==0)
        return LLONG_MAX;
    if(memoS[x])
        return memoS[x];
    cout << "S " << x << endl;
    cin >> memoS[x];
    return memoS[x];
}

void ans(ll a, ll b)
{
    cout << "! " << min(consF(a),consS(b)) << endl;
}

ll valid(ll a, ll b)
{
    ll x=consF(a), x2=consF(a+1), y=consS(b), y2=consS(b+1);
    if(y2>x)
        return 0;
    if(x2>y)
        return -1;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    ll l=1, r=min(n,k-1), piv, res;
    if(valid(min(n,k),k-min(n,k))==1)
    {
        ans(min(n,k),k-min(n,k));
        return 0;
    }
    if(valid(k-min(n,k),min(n,k))==1)
    {
        ans(k-min(n,k),min(n,k));
        return 0;
    }

    while(l<=r)
    {
        piv=(l+r)/2;
        res=valid(piv,k-piv);
        if(res==1)
        {
            ans(piv,k-piv);
            return 0;
        }
        else if(res==0)
            r=piv-1;
        else
            l=piv+1;
    }
    return 0;
}
