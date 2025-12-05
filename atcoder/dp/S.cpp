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

const int DIG=1e4+1;
const int NUM=10;
const int D=100;
const int MOD=1e9+7;
ll dp[DIG][NUM][D][2];
bool vis[DIG][NUM][2];
string s;
ll d;
void calc(ll idx, ll nu, ll t)
{
    ll i, j, sig;
    if(idx==0)
    {
        dp[idx][nu][nu%d][t]=1;
        return;
    }
    if(vis[idx][nu][t])
        return;
    vis[idx][nu][t]=1;
    for(i=0; i<=9; i++)
    {
        sig=0;
        if(t==1)
        {
            if(i>s[idx-1]-'0')
                continue;
            if(i==s[idx-1]-'0')
            {
                calc(idx-1,i,1);
                sig=1;
            }
            else
                calc(idx-1,i,0);
        }
        else
            calc(idx-1,i,0);
        for(j=0; j<d; j++)
            dp[idx][nu][(j+nu)%d][t]=(dp[idx][nu][(j+nu)%d][t]+dp[idx-1][i][j][sig])%MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, tot=0, j;
    cin >> s >> d;
    reverse(all(s));
    calc(sz(s)-1,s.back()-'0', 1);
    for(i=(s.back()-'0')-1; i>=0; i--)
        calc(sz(s)-1,i,0);
    for(i=0; i<=9; i++)
        for(j=0; j<2; j++)
            tot=(tot+dp[sz(s)-1][i][0][j])%MOD;
    tot--;
    if(tot<0)
        tot+=MOD;
    cout << tot;
    return 0;
}
