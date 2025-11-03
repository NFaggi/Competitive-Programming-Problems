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

const int dig = 19, num = 10;

ll dp[dig][num][2];

string s;

void init()
{
    for (ll i = 0; i < dig; i++)
        for (ll j = 0; j < num; j++)
            for(ll k=0; k<2; k++)
                dp[i][j][k] = -1;
}

ll calc(ll idx, ll nu, ll t, ll in)
{
    if (idx == 0)
        return 1;
    if (t == 0 && dp[idx][nu][in] != -1)
        return dp[idx][nu][in];

    ll k = (t) ? (s[idx-1]-'0') : 9, ret = 0;
    for (ll j = 0; j <= k; j++)
    {
        if (j == nu&&!(in&&j==0))
            continue;
        ll nt=((s[idx-1]-'0')==j)?t:0;
        ret += calc(idx - 1, j, nt,(j==0)&&in);
    }
    if(t!=1)
        dp[idx][nu][in]=ret;
    return ret;
}

ll calcRange(string &a, string &b)
{
    init();
    s = b;
    reverse(all(s));
    ll ans = 0, i, ans2=0;
    int ac=b[0]-'0';
    for (i = 0; i <= ac; i++)
        ans += calc(sz(b) - 1, i, (i==ac),(i==0));

    s = a;
    reverse(all(s));
    ac=a[0]-'0';
    for (i = 0; i <= ac; i++)
        ans2+= calc(sz(a) - 1, i, (i==ac),(i==0));
    return ans-ans2;
}

ll can(string &a)
{
    for (ll i = 0; i < sz(a) - 1; i++)
        if (a[i] == a[i + 1])
            return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << calcRange(a, b) + can(a);
    return 0;
}
