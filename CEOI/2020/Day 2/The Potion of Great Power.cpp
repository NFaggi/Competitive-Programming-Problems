//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN = 1e5 + 1;
const int SQ=318;
const int has=1000;
const int tam=628;
ll h[MAXN], n;
void init(int N, int D, int H[])
{
    ll i;
    for (i = 0; i < N; i++)
        h[i] = H[i];
    n=N;
}
vector<pair<ll,ll>>ars[MAXN];
vector<ll> ma[MAXN];
vector<vector<ll>>grafo[MAXN];
void curseChanges(int U, int A[], int B[])
{
    ll i, j, k;
    for(i=0; i<U; i++) 
    {
        ars[A[i]].pb({B[i],i});
        ars[B[i]].pb({A[i],i});
    }
    vector<ll>act;
    for(i=0; i<n; i++)
    {
        act.clear();
        for(j=0; j<sz(ars[i]); j++)
        {
            k=j/SQ;
            if(sz(ma[i])<=k)
                ma[i].pb(ars[i][j].se);
            else
                ma[i][k]=ars[i][j].se;
            auto it=find(all(act),ars[i][j].fr);
            if(it==act.end())
                act.pb(ars[i][j].fr);
            else
            {
                swap(*it,act.back());
                act.pop_back();
            }
            if((j+1)%SQ==0||j+1>=sz(ars[i]))
                grafo[i].pb(act);
        }
    }
}

ll k, ul, j, mi, ant;
vector<ll>retX,retY;
vector<ll>adyX;
int question(int x, int y, int v)
{
    v--;
    retX.clear();
    retY.clear();
    auto calc=[&]()
    {
        adyX.clear();
        k=0, ul=-1;
        for(k; k<sz(ma[x]); k++)
        {
            if(ma[x][k]>v)
                break;
            ul=k;
        }
        if(ul>=0)
            adyX=grafo[x][ul];
        for(j=SQ*(ul+1); j<min(sz(ars[x]),SQ*(ul+2)); j++)
        {
            if(ars[x][j].se<=v)
            {
                auto it=find(all(adyX),ars[x][j].fr);
                if(it==adyX.end())
                    adyX.pb(ars[x][j].fr);
                else
                {
                    swap(*it,adyX.back());
                    adyX.pop_back();
                }
            }
            else
                break;
        }
        for(auto &k:adyX)
            retX.pb(h[k]);
        sort(all(retX));
    };
    calc();
    swap(x,y);
    swap(retX,retY);
    calc();

    if(sz(retX) == 0 || sz(retY) == 0)
        return 1000000000;

    mi = 1e9, ant=-1;
    ll i, j=0;
    for(i=0; i<sz(retX); i++)
    {
        while(j+1<sz(retY)&&retY[j+1]<retX[i])
            j++;
        mi=min(mi,abs(retY[j]-retX[i]));
        if(j+1<sz(retY))
            mi=min(mi,abs(retY[j+1]-retX[i]));
    }
    return mi;
}
