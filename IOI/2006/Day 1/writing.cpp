//Link: https://juez.oia.unsam.edu.ar/tasks/ioi.2006.day1.writing
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

vector<ll>ori(26*2,0), act(26*2,0);

ll car(char k)
{
    if(k>='A'&&k<='Z')
        return int(k-'A');
    return int(k-'a')+26;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, ans=0, i, dif=0;
    string a, b;
    cin >> n >> m >> a >> b;
    for(auto k:a)
        ori[car(k)]++;
    for(i=0; i<min(m,n); i++)
        act[car(b[i])]++;
    for(i=0; i<26*2; i++)
        if(act[i]!=ori[i])
            dif++;    
    if(dif==0)
        ans++;
    for(i=n; i<m; i++)
    {
        if(act[car(b[i-n])]==ori[car(b[i-n])])
            dif++;
        act[car(b[i-n])]--;
        if(act[car(b[i-n])]==ori[car(b[i-n])])
            dif--;
        if(act[car(b[i])]==ori[car(b[i])])
            dif++;    
        act[car(b[i])]++;
        if(act[car(b[i])]==ori[car(b[i])])
            dif--;
        if(dif==0)
            ans++;
    }
    cout << ans;
    return 0;
}
