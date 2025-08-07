//Score:100/100
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

const int MAXN=1e4+5;

vector<pair<int,int>>grafo[MAXN];
vector<ll>sub[MAXN];

void sor(vector<ll>&a)
{
    for(ll i=sz(a)-1; i>0; i--)
        if(a[i-1]>a[i])
            swap(a[i],a[i-1]);
}
ll cant;
vector<ll>a,b,up;
int i, j;
ll sum;
void bor(ll num)
{
    ll pos=0;
    for(i=0; i<sz(up); i++)
        if(up[i]==num)
            pos=i;
    up.erase(up.begin() + pos);        
}
void dfs(int nod, int pad, ll dis)
{
    sum=0;
    for(auto &k:grafo[nod])
    {
        if(k.fr==pad)
            continue;
        up.pb(dis);
        sor(up);
        
        dfs(k.fr,nod,dis+k.se);
        
        bor(dis);
        swap(a,sub[k.fr]);
        a.pb(dis+k.se);
        sor(a);
        
        b.resize(0);
        swap(b,sub[nod]);
        i=j=0;
        sub[nod].resize(a.size() + b.size());
        merge(all(a),all(b),sub[nod].begin());
        
    }

    i=0;
    j=sz(up)-1;
    sum=0;
    while(i<sz(sub[nod])&&j>=0)
    {
        if(sub[nod][i]+up[j]<dis*2ll)
        {
            i++;
            while(i<sz(sub[nod])&&sub[nod][i]==sub[nod][i-1])
            {
                cant+=sum;
                i++;
            }
            sum=0;
        }
        else if(sub[nod][i]+up[j]>dis*2ll)
        {
            j--;
        }
        else
        {
            sum++;
            cant++;
            j--;
        }
    }
    i++;
    while(i<sz(sub[nod])&&sub[nod][i]==sub[nod][i-1])
    {
        cant+=sum;
        i++;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, a, b, c;
    cin >> n;
    for(i=0; i<n-1; i++)
    {
        cin >> a >> b >> c;
        grafo[a].pb({b,c});
        grafo[b].pb({a,c});
    }
    dfs(1,0,0);
    cout << cant;
    return 0;
}