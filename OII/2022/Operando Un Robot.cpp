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

vector<vector<ll>>st;
ll n;

vector<ll> conv(vector<ll>a, vector<ll>b)
{
    vector<ll>c=a;
    if(a[2]==0)
    {
        c[0]+=b[0];
        c[1]+=b[1];
    }
    else if(a[2]==1)
    {
        c[0]-=b[1];
        c[1]+=b[0];
    }
    else if(a[2]==2)
    {
        c[0]-=b[0];
        c[1]-=b[1];
    }
    else
    {
        c[0]+=b[1];
        c[1]-=b[0];
    }
    c[2]=(c[2]+b[2])%4;
    return c;
}

void update(ll i, ll t, ll m)
{
    if(t==1)
        st[i]={m,0,0};
    else
        st[i]={0,0,m};
    i/=2;
    while(i>0)
    {
        st[i]=conv(st[i*2],st[i*2+1]);
        i/=2;
    }
}

vector<ll> calc(ll l, ll r)
{
    vector<ll> L(3,0), R(3,0);
    for(; l < r; l /= 2, r /= 2)
    {
        if(l%2!=0) L = conv(L, st[l++]);
        if(r%2!=0) R = conv(st[--r],R);
    }
    return conv(L,R);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, i, t, m, l, r;
    vector<ll>ans;
    cin >> n;
    st.resize(n*2,vector<ll>(3,0));//x, y, ang
    for(i=0; i<n; i++)
    {
        cin >> t >> m;
        if(t==1)
            st[i+n]={m,0,0};
        else
            st[i+n]={0,0,m};
    }
    for(i=n-1; i>0; i--)
        st[i]=conv(st[i*2],st[i*2+1]);
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t==1)
        {
            cin >> l >> r;
            ans=calc(l+n,r+n+1);
            cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
        }
        else
        {
            cin >> i >> t >> m;
            update(i+n,t,m);
        }
    }
    return 0;
}
