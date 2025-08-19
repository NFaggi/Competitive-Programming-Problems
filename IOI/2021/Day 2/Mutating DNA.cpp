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
string A, B;
map<char,ll>m;
vector<ll>pref;
vector<vector<ll>>pA,pB,pV;
void init(std::string a, std::string b)
{
    A=a;
    B=b;
    m['A']=0;
    m['C']=1;
    m['T']=2;
    pref.resize(sz(a));
    pA.resize(sz(a),vector<ll>(3,0));
    pV.resize(sz(a),vector<ll>(6,0));
    pB.resize(sz(b),vector<ll>(3,0));
    pref[0]=(A[0]!=B[0]);
    for(ll i=1; i<sz(a); i++)
    {
        pref[i]=pref[i-1]+(A[i]!=B[i]);
    }
    for(ll i=0; i<3; i++)
        pA[0][i]=pB[0][i]=0;
    pA[0][m[A[0]]]=1;
    pB[0][m[B[0]]]=1;
    for(ll i=1; i<sz(a); i++)
    {
        for(ll j=0; j<3; j++)
        {
            pA[i][j]=pA[i-1][j];
            pB[i][j]=pB[i-1][j];
        }
        pA[i][m[A[i]]]++;
        pB[i][m[B[i]]]++;
    }
    for(ll i=0; i<sz(a); i++)
    {
        if(i>0)
            pV[i]=pV[i-1];
        if(A[i]==B[i])
            continue;
        if(A[i]=='A')
        {
            if(B[i]=='C')
                pV[i][0]++;
            else
                pV[i][1]++;
        }
        else if(A[i]=='C')
        {
            if(B[i]=='A')
                pV[i][2]++;
            else
                pV[i][3]++;
        }
        else
        {
            if(B[i]=='A')
                pV[i][4]++;
            else
                pV[i][5]++;
        }
    }
}
int get_distance(int x, int y)
{
    ll i, cant=0;
    vector<ll>aC(3,0), bC(3,0);
    for(i=0; i<3; i++)
    {
        aC[i]=pA[y][i];
        bC[i]=pB[y][i];
        if(x>0)
        {
            aC[i]-=pA[x-1][i];
            bC[i]-=pB[x-1][i];
        }
    }
    if(aC!=bC)
        return -1;
    vector<ll>v(6,0);
    v=pV[y];
    if(x>0)
    {
        for(i=0; i<6; i++)
        {
            v[i]-=pV[x-1][i];
        }
    }
   
    ll bor=min(v[0],v[2]);
    cant=bor;
    v[0]-=bor;
    v[2]-=bor;
    
    bor=min(v[1],v[4]);
    cant+=bor;
    v[1]-=bor;
    v[4]-=bor;

    bor=min(v[3],v[5]);
    cant+=bor;
    v[3]-=bor;
    v[5]-=bor;

    ll extra=0;
    for(auto k:v)
        extra+=k;
    cant+=(extra/3)*2;
    return cant;
}
