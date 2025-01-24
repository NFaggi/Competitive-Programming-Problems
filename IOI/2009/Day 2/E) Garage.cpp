//Link: https://ioi.contest.codeforces.com/group/32KGsXgiKA/contest/103755/problem/E
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, i, ganancia=0, x;
    cin >> n >> k;
    vector<ll>costos(n),pesos(k);
    vector<bool>salir(k,0);

    forn(i,n)
        cin >> costos[i];

    forn(i,k)
        cin >> pesos[i];

    set<ll>s;
    map<ll,ll>m;

    forn(i,n)
        s.insert(i+1);
    queue<ll>q;
    forn(i,k*2)
    {
        cin >> x;
        if(x>0)
        {
            x--;
            q.push(x);
        }
        else
        {
            x*=-1;
            x--;
            if(m[x]==0)
            {
                salir[x]=1;
                continue;
            }
            s.insert(m[x]);
            m[x]=0;
        }
        while(sz(q)>0&&sz(s)>0)
        {
            x=q.front();
            q.pop();
            auto it=s.begin();
            ganancia+=costos[*it-1]*pesos[x];
            if(salir[x])
                continue;
            m[x]=*it;
            s.erase(it);
        }
    }
    cout << ganancia;
    return 0;
}
 