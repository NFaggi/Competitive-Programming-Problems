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

vector<vector<ll>>st;
vector<ll>I,D;

void update(ll x, ll y,ll val)
{
    ll nod;
    while(x>0)
    {
        nod=y;
        st[x][nod]+=val;
        nod/=2;
        while(nod>0)
        {
            st[x][nod]=st[x][nod*2]+st[x][nod*2+1];
            nod/=2;
        }
        x/=2;
    }
}

ll calc2(ll a, ll b, ll nod, ll x)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return st[x][nod];
    return calc2(a,b,nod*2,x)+calc2(a,b,nod*2+1,x);
}

ll calc(ll a, ll b, ll a2, ll b2, ll nod)
{
    if(I[nod]>b||D[nod]<a)
        return 0;
    if(I[nod]>=a&&D[nod]<=b)
        return calc2(a2,b2,1,nod);
    return calc(a,b,a2,b2,nod*2)+calc(a,b,a2,b2,nod*2+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, i, j, pot=1, op, a, b, a2, b2;
    cin >> n >> q;
    while(pot<n)
        pot*=2;
    I.resize(pot*2);
    D.resize(pot*2);
    st.resize(pot*2,vector<ll>(pot*2,0));
    for(i=pot; i<pot*2; i++)
    {
        I[i]=D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    string s;
    vector<string>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        for(j=0; j<n; j++)
        {
            if(v[i][j]=='*')
                update(i+pot,j+pot,1);
        }
    }

    while(q--)
    {
        cin >> op;
        if(op==1)
        {
            cin >> i >> j;
            i--;
            j--;
            if(v[i][j]=='*')
            {
                update(i+pot,j+pot,-1);
                v[i][j]='.';
            }
            else
            {
                update(i+pot,j+pot,1);
                v[i][j]='*';
            }
        }
        else
        {
            cin >> a >> a2 >> b >> b2;
            a--;
            b--;
            a2--;
            b2--;
            a+=pot;
            b+=pot;
            a2+=pot;
            b2+=pot;
            cout << calc(a,b,a2,b2,1) << '\n';
        }
    }

    return 0;
}
