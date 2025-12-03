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

ll n, i;
string s;
void qs(vector<bool> &cons)
{
    cout << "? ";
    for (i = 0; i < n; i++)
        cout << cons[i];
    cout << endl;
    cin >> s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<ll> v(n), v2, a, b, c, d, ans(n);
    for (i = 0; i < n; i++)
        v[i] = i;
    queue<pair<vector<ll>, vector<ll>>> q, nq;
    nq.push({v, v});
    while (sz(nq))
    {
        swap(nq, q);
        while (sz(nq))
            nq.pop();

        vector<bool> cons(n, 0);
        while (sz(q))
        {
            v = q.front().fr;
            v2 = q.front().se;
            q.pop();
            if (sz(v) == 1)
            {
                ans[v2[0]] = v[0] + 1;
                continue;
            }
            for (i = 0; i < sz(v) / 2; i++)
            {
                a.pb(v[i]);
                cons[v[i]] = 1;
            }
            nq.push({v, v2});
        }
        if (!sz(nq))
            break;
        swap(nq, q);
        qs(cons);
        while (sz(q))
        {
            v = q.front().fr;
            v2 = q.front().se;
            q.pop();
            vector<bool> ap(n, 0);
            a=b=c=d={};
            for (i = 0; i < sz(v); i++)
            {
                ap[v2[i]] = 1;
                if (i < sz(v) / 2)
                    a.pb(v[i]);
                else
                    c.pb(v[i]);
            }
            for (i = 0; i < n; i++)
            {
                if (s[i] == '1' && ap[i])
                    b.pb(i);
                else if (s[i] == '0' && ap[i])
                    d.pb(i);
            }
            nq.push({a, b});
            nq.push({c, d});
        }
    }
    cout << "! ";
    for (i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
