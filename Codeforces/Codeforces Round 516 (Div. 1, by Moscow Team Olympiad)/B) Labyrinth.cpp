//Link: https://codeforces.com/contest/1063/problem/B
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

ll INF = INT_MAX;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, a, b, x, y, i, j, c, r;
    cin >> n >> m >> a >> b >> x >> y;
    a--;
    b--;

    vector<string> v(n);

    for (i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    vector<vector<ll>> proc(n, vector<ll>(m, 0));
    vector<vector<pair<ll, ll>>> dist(n, vector<pair<ll, ll>>(m, {INF, INF}));
    priority_queue<vector<ll>> pq;
    auto calc = [&](ll band)
    {
        dist[a][b] = {0, 0};
        vis[a][b] = 1;
        pq.push({0, 0, a, b});

        vector<ll> nod;
        pair<ll, ll> p;
        while (sz(pq))
        {
            nod = pq.top();
            pq.pop();
            c = nod[2];
            r = nod[3];
            if (proc[c][r])
                continue;
            vis[c][r] = proc[c][r] = 1;
            if (c - 1 >= 0 && v[c - 1][r] == '.')
            {
                if (dist[c - 1][r] > dist[c][r])
                {
                    dist[c - 1][r] = dist[c][r];
                    pq.push({-dist[c][r].fr, -dist[c][r].se, c - 1, r});
                }
            }
            if (c + 1 < n && v[c + 1][r] == '.')
            {
                if (dist[c + 1][r] > dist[c][r])
                {
                    dist[c + 1][r] = dist[c][r];
                    pq.push({-dist[c][r].fr, -dist[c][r].se, c + 1, r});
                }
            }

            if (r - 1 >= 0 && v[c][r - 1] == '.')
            {
                p = dist[c][r];
                if (!band)
                    p.fr++;
                else
                    p.se++;
                if (p.fr <= x && p.se <= y && dist[c][r - 1] > p)
                {
                    dist[c][r - 1] = p;
                    pq.push({-dist[c][r].fr, -dist[c][r].se, c, r - 1});
                }
            }

            if (r + 1 < m && v[c][r + 1] == '.')
            {
                p = dist[c][r];
                if (!band)
                    p.se++;
                else
                    p.fr++;
                if (p.fr <= x && p.se <= y && dist[c][r + 1] > p)
                {
                    dist[c][r + 1] = p;
                    pq.push({-dist[c][r].fr, -dist[c][r].se, c, r + 1});
                }
            }
        }
    };
    calc(0);
    ll cant=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(vis[i][j])
                cant++;
    cout << cant;
    return 0;
}
