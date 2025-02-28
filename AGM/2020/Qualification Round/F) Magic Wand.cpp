//Link: https://codeforces.com/gym/102566/problem/F
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

vector<ll>seg;

void update(int nod)
{
    seg[nod]++;
    nod/=2;
    while(nod>0)
    {
        seg[nod]=seg[nod*2]+seg[nod*2+1];
        nod/=2;
    }
}

ll calc(int l, int r)
{
    ll L=0, R=0;
    for(; l < r; l /= 2, r /= 2)
    {
        if(l%2!=0) L = L+seg[l++];
        if(r%2!=0) R = seg[--r]+R;
    }
    return L+R;
}

void solve()
{
    int n, i, num=1;
    ll ans=0;
    cin >> n;
    seg.resize(0);
    seg.resize(n*2,0);
    vector<int>v(n),ord;
    map<int,int>m;
    for(i=0; i<n; i++)
        cin >> v[i];
    ord=v;
    sort(all(ord));
    for(i=0; i<n; i++)
        if(m[ord[i]]==0)
        {
            m[ord[i]]=num;
            num++;
        }
    for(i=0; i<n; i++)
    {
        v[i]=m[v[i]]-1;
    }
    for(i=0; i<n; i++)
    {
        ans+=calc(v[i]+1+n, n+n)*8ll;
        update(v[i]+n);
    }
    cout << ans << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}