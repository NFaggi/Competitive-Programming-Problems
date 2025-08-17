//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define fr first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
const int LIM = 100;
const int MAXN = 17000000;
int cant[MAXN];


vector<int> nums;
vector<ll>prims;

ll bpow(ll x, ll y)
{
    ll ans = 1;
    for (ll i = 0; i < y; i++)
        ans = ans * x;
    return ans;
}

void fact(ll x)
{
    ll tot = 1, act, in = x;
    for (auto k : prims)
    {
        if(k>31623)
            break;
        act = 1;
        while (x % k == 0)
        {
            x = x / k;
            act++;
        }
        tot = tot * act;
    }
    if (tot == 9)
    {
        nums.pb(in);
    }
}

int main()
{
    ll t, i, a, b, j, k;
    cin >> t;
    for (i = 1; i < MAXN; i++)
        cant[i] = 2;
    nums.pb(1);
    string s;
    for (i = 2; i < MAXN; i++)
    {
        s = to_string(i);
        if (sz(s) == cant[i])
            nums.pb(i);
        if (cant[i] == 2)
        {
            prims.pb(i);
        }
        for (j = i + i; j < MAXN; j += i)
            cant[j]++;
    }
    for (int i = 0; i < (int)prims.size(); i++)
    {
        ll p = bpow(prims[i],7);
        if (p >= 100000000)
            break;
        if (p >= MAXN && p < 100000000)
        {
            nums.push_back(p);
        }
    }
    for (int i = 0; i < (int)prims.size(); i++)
    {
        if (bpow(prims[i],3) >= 100000000)
            break;
        for (int j = 0; j < (int)prims.size(); j++)
        {
            if (i == j)
                continue;
            if (bpow(prims[i],3) * prims[j] >= 100000000)
                break;
            if (bpow(prims[i],3) * prims[j] >= MAXN)
            {
                nums.push_back(bpow(prims[i],3) * prims[j]);
            }
        }
    }
    for (i = 0; i < sz(prims); i++)
    {
        if (bpow(prims[i],3) >= 100000000)
            break;
        for (j = i + 1; j < sz(prims); j++)
        {
            if (prims[i] * prims[j] * prims[j] >= 100000000)
                break;
            for (k = j + 1; k < sz(prims); k++)
            {
                if (prims[i] * prims[j] * prims[k]>= 100000000)
                    break;
                if (prims[i] * prims[j] * prims[k] >= MAXN)
                {
                    nums.push_back(prims[i] * prims[j] * prims[k]);
                }
            }
        }
    }
    for (i = 1; i < 31650; i++)
    {
        if (i * i > 99'999'999 && i * i < 999'999'999)
        {
            fact(i * i);
        }
    }
    nums.pb(0);
    nums.pb(INT_MAX);
    sort(all(nums));
    vector<int> unNums;
    ll ant = -1;
    for (auto k : nums)
    {
        if (k == ant)
            continue;
        unNums.pb(k);
    }
    swap(unNums, nums);
    while (t--)
    {
        cin >> a >> b;
        auto it = lower_bound(all(nums), a);
        auto it2 = upper_bound(all(nums), b);
        it2 = prev(it2);
        ll x = it - nums.begin();
        ll y = it2 - nums.begin();
        if (y < x)
            cout << 0 << '\n';
        else
            cout << (y - x) + 1 << '\n';
    }
    return 0;
}
