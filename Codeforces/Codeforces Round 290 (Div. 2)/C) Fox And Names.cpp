//Link: https://codeforces.com/problemset/problem/510/C
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
vector<ll>grafo[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i,pos=0, j,dif,l;
    cin >> n;
    vector<string>v(n);
    vector<ll>id(26,0);
    vector<ll>ord(26,-1);
    for(i=0; i<n; i++)
        cin >> v[i];
    for(i=0; i<n-1; i++)
    {
        dif=0;
        for(l=i+1; l<n; l++)
        {
            for(j=0; j<sz(v[i])&&j<sz(v[l]); j++)
            {
                if(v[i][j]!=v[l][j])
                {
                    dif=1;
                    id[v[l][j]-'a']++;
                    grafo[v[i][j]-'a'].pb(v[l][j]-'a');
                    break;
                }
            }
            if(dif==0&&sz(v[i])>sz(v[l]))
            {
                cout << "Impossible";
                return 0;
            }

        }

    }
    queue<ll>q;
    for(i=0; i<26; i++)
    {
        if(id[i]==0)
            q.push(i);
    }
    while(sz(q))
    {
        i=q.front();
        q.pop();
        ord[i]=pos;
        pos++;
        for(auto k:grafo[i])
        {
            id[k]--;
            if(id[k]==0)
                q.push(k);
        }
    }
    for(i=0; i<26;i++)
    {
        if(id[i]>0)
        {
            cout << "Impossible";
            return 0;
        }
    }
    vector<pair<ll,char>>res;
    for(i=0; i<26; i++)
    {
        res.pb({ord[i],'a'+i});
    }
    sort(all(res));
    for(auto k:res)
    {
        cout << k.se;
    }

    return 0;
}
