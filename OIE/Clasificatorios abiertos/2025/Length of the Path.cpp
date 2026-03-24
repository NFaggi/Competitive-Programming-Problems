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

void solve()
{
    ll n, i, l, x = 0, y = 0, dis = 0, N, S, E, O;
    N = O = S = E = 0;
    char d;
    cin >> n;

    auto add = [&](ll ag)
    {
        switch (d)
        {
        case 'N':
            y += ag;
            break;
        case 'S':
            y -= ag;
            break;
        case 'E':
            x -= ag;
            break;
        default:
            x += ag;
            break;
        }
    };

    for (i = 0; i < n; i++)
    {
        cin >> d >> l;
        if (l == -1)
        {
            dis++;
            add(1);
            switch (d)
            {
            case 'N':
                N = 1;
                break;
            case 'S':
                S = 1;
                break;
            case 'E':
                E = 1;
                break;
            default:
                O = 1;
                break;
            }
        }
        else
        {
            dis += l;
            add(l);
        }
    }
    ll mi, ma;

    mi=dis;
    if(x>0)
    {
        if(E)
            mi+=x;
        else
            mi=LLONG_MIN;
    }
    if(x<0)
    {
        if(O)
            mi+=-x;
        else
            mi=LLONG_MIN;
    }

    if(y>0)
    {
        if(S)
            mi+=y;
        else
            mi=LLONG_MIN;
    }
    if(y<0)
    {
        if(N)
            mi+=-y;
        else
            mi=LLONG_MIN;
    }

    if(mi<0)
    {
        cout << -1 << ' ' << -1 << '\n';
    }
    else
    {
        ma=mi;
        if((S==1&&N==1)||(E==1&&O==1))
            ma=-1;
        cout << mi << ' ' << ma << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
