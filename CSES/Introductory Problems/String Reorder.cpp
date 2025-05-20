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

ll cant[26];

bool can(ll j)
{
    ll tot = 0, ma=0, i;
    for(i=0; i<26; i++)
    {
        tot+=cant[i];
        ma=max(ma,cant[i]);
    }
    return ma<=(tot+1)/2&&cant[j]<=(tot)/2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, sig, j, ant=-1;
    char c;
    string s, ans = "";
    cin >> s;
    for (i = 0; i < sz(s); i++)
        cant[s[i] - 'A']++;
    for (i = 0; i < sz(s); i++)
    {
        sig = 0;
        for (j = 0; j < 26; j++)
        {
            if (cant[j] <= 0||ant==j)
                continue;
            cant[j]--;
            if (can(j))
            {
                c = 'A' + j;
                ans += c;
                sig = 1;
                ant=j;
                break;
            }
            else
                cant[j]++;
        }
        if (!sig)
        {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
