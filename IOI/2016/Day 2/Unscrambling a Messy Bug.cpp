//Link: https://oj.uz/problem/view/IOI16_messy
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

void add_element(string x);
void compile_set();
bool check_element(string x);

ll N;

void div(vector<ll> &v, vector<ll> &iz, vector<ll> &der)
{
    ll i, n = sz(v);
    for (i = 0; i < n / 2; i++)
        iz.pb(v[i]);
    for (i = n / 2; i < n; i++)
        der.pb(v[i]);
}

void insert(vector<ll> iz, vector<ll> der)
{
    ll i;
    vector<ll> I, D;
    string bits;
    if (sz(iz) == 2)
    {
        bits = "";
        bits.resize(N, '1');
        bits[iz[0]] = '0';
        add_element(bits);
        return;
    }
    bits = "";
    bits.resize(N, '0');
    for (i = 0; i < sz(der); i++)
        bits[der[i]] = '1';

    for (i = 0; i < sz(iz) / 2; i++)
    {
        bits[iz[i]] = '1';
        add_element(bits);
        bits[iz[i]] = '0';
    }
    div(iz, I, D);
    insert(I, D);
    insert(D, I);
}

vector<int> ans;

void search(vector<ll> iz, vector<ll> der, vector<ll> pos, bool in = 0)
{
    string bits;
    ll i;
    vector<ll> I, D, PI, PD;
    if (in)
    {
        bits = "";
        bits.resize(N, '0');
        for (i = 0; i < N; i++)
        {
            bits[iz[i]] = '1';
            if (check_element(bits))
                I.pb(iz[i]);
            else
                D.pb(iz[i]);
            bits[iz[i]] = '0';
        }
    }
    else
    {
        if (sz(iz) == 2)
        {
            bits = "";
            bits.resize(N, '1');
            bits[iz[0]] = '0';
            if (!check_element(bits))
                swap(iz[0], iz[1]);
            ans[iz[0]] = pos[0];
            ans[iz[1]] = pos[1];
            return;
        }
        bits = "";
        bits.resize(N, '0');
        for (i = 0; i < sz(der); i++)
            bits[der[i]] = '1';
        for (i = 0; i < sz(iz); i++)
        {
            bits[iz[i]] = '1';
            if (check_element(bits))
                I.pb(iz[i]);
            else
                D.pb(iz[i]);
            bits[iz[i]] = '0';
        }
    }
    div(pos, PI, PD);
    search(I, D, PI);
    search(D, I, PD);
}

std::vector<int> restore_permutation(int n, int w, int r)
{

    vector<ll> iz, der;
    ll i;
    N = n;
    ans.resize(n);
    vector<ll> v(n), vacio;
    for (i = 0; i < n; i++)
        v[i] = i;
    insert(v, vacio);
    compile_set();
    search(v, vacio, v, 1);
    return ans;
}
