#include <bits/stdc++.h>
const int MAXN=2e5+1;
const int LOG=31;
using namespace std;
int up[MAXN][LOG];
int kth_ancestor(int v, int k) {
    for (int i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            v = up[v][i];
            if (v == -1) break;
        }
    }
    return v;
}
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, Q, x, k, i, nod;
    cin >> n >> Q;
    vector<int>v(n+1);
    queue<pair<int,int>>q;
    for(i=1; i<=n; i++)
    {
        cin >> v[i];
        up[i][0]=v[i];
        q.push({i,1});
    }
 
    while(q.size())
    {
       nod=q.front().first;
       k=q.front().second;
       q.pop();
       up[nod][k]=up[up[nod][k-1]][k-1];
       if(k+1<LOG)
        q.push({nod,k+1});
    }
    while(Q--)
    {
        cin >> nod >> k;
        if(k>0)
            cout << kth_ancestor(nod,k) << '\n';
        else
            cout << nod << '\n';
    }
    return 0;
}
