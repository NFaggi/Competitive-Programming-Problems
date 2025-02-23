//Link: https://codeforces.com/problemset/problem/1918/F
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

const int MAXN=2e5+1;

ll hijos[MAXN], prof[MAXN],depth[MAXN];
vector<ll>arbol[MAXN];

ll DFS(ll nod, ll pad)
{
    for(auto k:arbol[nod])
    {
        if(k==pad)
            continue;
        hijos[nod]+=DFS(k,nod);
    }
    return hijos[nod]+1;
}

ll DFS2(ll nod, ll pad, ll dep)
{
    prof[nod]=dep;
    depth[nod]=dep;
    for(auto k:arbol[nod])
    {
        prof[nod]=max(prof[nod],DFS2(k,nod,dep+1));
    }
    return prof[nod];
}

vector<vector<ll>>optis; /// beneficio, suma con beneficio, suma original
ll N, ans=0;
void calc(ll nod, ll pad, ll anc)
{
    N--;
    if(N==0)
        return;
    ll hijo=sz(arbol[nod]);
    vector<pair<ll,ll>>v;
    for(auto k:arbol[nod])
    {
        v.push_back({prof[k],k});
    }
    sort(v.begin(),v.end());
    for(auto k:v)
    {
        hijo--;
        ans++;
        if(hijo)
            calc(k.second,nod,nod);
        else
            calc(k.second,nod,anc);
    }
    if(sz(arbol[nod])==0)
    {
        if(depth[anc]-1<abs(depth[anc]-depth[nod]))
        {
            vector<ll>tmp(3);
            tmp[0]=(abs(depth[anc]-depth[nod])-(depth[anc]-1));
            tmp[1]=depth[anc]-1;
            tmp[2]=abs(depth[anc]-depth[nod]);
            optis.pb(tmp);
        }
        else
        {
            ans+=abs(depth[anc]-depth[nod]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, a, y;
    cin >> n >> y;
    N=n;
    for(i=0; i<n-1; i++)
    {
        cin >> a;
        arbol[a].pb(i+2);
    }
    DFS(1,0);
    DFS2(1,0,1);
    calc(1,0,1);
    sort(all(optis));
    reverse(all(optis));
    i=0;
    for(auto k:optis)
    {
        if(!y)
            break;
        y--;
        i++;
        ans+=k[1];
    }
    for(i; i<sz(optis); i++)
        ans+=optis[i][2];
    cout << ans;
    return 0;
}
