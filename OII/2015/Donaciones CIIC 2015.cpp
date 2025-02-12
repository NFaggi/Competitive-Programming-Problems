//Score: 100/100
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

vector<ll>ST,EN,I,D;
vector<vector<ll>>Q;

void aumST(ll nod, ll x)
{
    ST[nod]+=x;
    nod/=2;
    while(nod>0)
    {
        ST[nod]=ST[nod*2]+ST[nod*2+1];
        nod/=2;
    }
}

void aumEN(ll nod, ll x)
{
    EN[nod]+=x;
    nod/=2;
    while(nod>0)
    {
        EN[nod]=EN[nod*2]+EN[nod*2+1];
        nod/=2;
    }
}

void resST(ll nod, ll x)
{
    ST[nod]-=x;
    nod/=2;
    while(nod>0)
    {
        ST[nod]=ST[nod*2]+ST[nod*2+1];
        nod/=2;
    }
}

void resEN(ll nod, ll x)
{
    EN[nod]-=x;
    nod/=2;
    while(nod>0)
    {
        EN[nod]=EN[nod*2]+EN[nod*2+1];
        nod/=2;
    }
}

ll calST(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return ST[nod];
    return calST(a,b,nod*2)+calST(a,b,nod*2+1);
}

ll calEN(ll a, ll b, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return EN[nod];
    return calEN(a,b,nod*2)+calEN(a,b,nod*2+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, q, pot=1, t, a, b, ans=0;
    cin >> n;
    Q.resize(n,vector<ll>(3));
    while(pot<1000001ll)
        pot*=2;
    ST.resize(pot*2,0);
    EN.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<pot*2; i++)
        D[i]=I[i]=i;
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    for(i=0; i<n; i++)
    {
        cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
        aumST(Q[i][0]+pot,Q[i][2]);
        aumEN(Q[i][1]+pot,Q[i][2]);
    }
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t==1)
        {
            cin >> a >> b;
            ans=calST(pot,b+pot,1);
            ans-=calEN(pot,(a-1)+pot, 1);
            cout << ans << '\n';
        }
        else
        {
            cin >> i;
            i--;
            resST(Q[i][0]+pot,Q[i][2]);
            resEN(Q[i][1]+pot,Q[i][2]);
            cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
            aumST(Q[i][0]+pot,Q[i][2]);
            aumEN(Q[i][1]+pot,Q[i][2]);
        }
    }

    return 0;
}
