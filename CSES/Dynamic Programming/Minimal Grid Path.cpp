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
    ll n, i, j;
    char mi, ant;
    cin >> n;
    vector<string>v(n);
    vector<vector<bool>>vis(n,vector<bool>(n,0));
    for(i=0; i<n; i++)
        cin >> v[i];
    string s="";
    queue<pair<char,pair<ll,ll>>>q,pq;
    q.push({v[0][0],{0,0}});
    ant=v[0][0];
    vis[0][0]=1;
    while(q.size()||pq.size())
    {
        mi='Z';
        s+=ant;
        while(q.size())
        {
            if(q.front().fr!=ant)
            {
                q.pop();
                continue;
            }
            i=q.front().se.fr;
            j=q.front().se.se;
            q.pop();
            if(i+1<n&&vis[i+1][j]==0)
            {
                vis[i+1][j]=1;
                pq.push({v[i+1][j],{i+1,j}});
                mi=min(mi,v[i+1][j]);
            }
            if(j+1<n&&vis[i][j+1]==0)
            {
                vis[i][j+1]=1;
                pq.push({v[i][j+1],{i,j+1}});
                mi=min(mi,v[i][j+1]);
            }
        }
        swap(q,pq);
        ant=mi;
    }
    cout << s;
    return 0;
}
