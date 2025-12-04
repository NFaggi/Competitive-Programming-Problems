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

const int MAXN=1001;

bool prim[MAXN];
vector<ll>v;
void prims()
{
    ll i, j;
    for(i=2; i<MAXN; i++)
    {
        if(!prim[i])
            continue;
        v.pb(i);
        for(j=i+i; j<MAXN; j+=i)
            prim[j]=0;
    }
}
ll has(vector<ll>&a)
{
    ll ha=1;
    for(auto k:a)
        ha=ha*k;
    return ha;    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(prim,1,sizeof(prim));
    prims();
    ll n, i, cant=0, x, j, k, mask,tot, ha;
    cin >> n;
    tot=(n*(n-1ll))/2ll;
    vector<vector<ll>>act(n);
    vector<ll>v2;
    unordered_map<ll,pair<ll,ll>>todos;
    for(i=0; i<n; i++)
    {
        cin >> x;
        for(j=0; j<sz(v); j++)
        {
            if(x%v[j]==0)
                act[i].pb(v[j]);
            while(x%v[j]==0)
                x=x/v[j];
        }
        if(x>1)
            act[i].pb(x);
        mask=(1<<sz(act[i]));
        for(j=1; j<mask; j++)
        {
            v2.resize(0);
            for(k=0; k<sz(act[i]); k++)
                if((1<<k)&j)
                    v2.pb(act[i][k]);
            ha=has(v2);
            auto it=todos.find(ha);
            if(it!=todos.end())
                it->se.se++;
            else
                todos[ha]= {sz(v2),1};
        }

    }
    for(auto k:todos)
    {
        if(k.se.fr%2!=0)
            cant+=(k.se.se*(k.se.se-1))/2;
        else
            cant-=(k.se.se*(k.se.se-1))/2;
    }
    cout << tot-cant;
    return 0;
}
