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

const int MAXN=(1<<15);

ll grafo[MAXN][2], n;
bool vis[MAXN][2];

vector<ll>ord;
string s;
void dfs(ll nod)
{
    for(ll i=0; i<2; i++)
    {
        if(!vis[nod][i])
        {
            vis[nod][i]=1;
            dfs(grafo[nod][i]);
        }
    }
    ord.pb(nod);
}

void tostr(ll x)
{
    for(ll i=n-2; i>=0; i--)
    {
        if((1<<i)&x)
            s+="1";
        else
            s+="0";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll mask, lim, i, sig;
    cin >> n;
    if(n==1)
    {
        cout << 10;
        return 0;
    }
    lim=(1<<(n-1))-1;
    mask=(1<<(n-1));
    for(i=0; i<mask; i++)
    {
        sig=(i<<1)&lim;
        grafo[i][0]=sig;
        grafo[i][1]=sig+1;
    }
    dfs(0);
    reverse(all(ord));
    tostr(ord[0]);
    for(i=0; i<sz(ord)-1; i++)
    {
        sig=(ord[i]<<1)&lim;
        if(sig==ord[i+1])
            s+="0";
        else
            s+="1";
    }
    cout << s;
    return 0;
}
