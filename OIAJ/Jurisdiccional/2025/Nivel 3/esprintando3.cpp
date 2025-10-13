//Link: https://juez.oia.unsam.edu.ar/task/180
//Score: 100/100
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define ll long long
using namespace std;

double EPS = 1e-12;

double sq(double a) 
{ 
    return a * a; 
}
double ham(double x, double y, double x2, double y2)
{
    return sq(x - x2) + sq(y - y2);
}

vector<int> x, y;
vector<ll> dis, pref;
vector<double> pref2, pref2Ext, dis2;
int k, N;
double k2;

pair<int, int> fin(ll pos)
{
    ll K = k, aK = k, dis1 = pref.back(), l = pos, r = sz(x) - 1, piv, di, res = 0;
    if (pos > 0)
        dis1 -= pref[pos - 1];
    if (K > dis1)
    {
        K -= dis1;
        pos = 0;
        l = 0;
        r = sz(x) - 1;
    }
    if (l > 0)
        res = pref[l - 1];
    while (l <= r)
    {
        piv = (l + r) / 2;
        di = 0;
        if (piv > 0)
            di = pref[piv - 1] - res;
        if (di <= K)
        {
            pos = piv;
            aK = K - di;
            l = piv + 1;
        }
        else
            r = piv - 1;
    }
    int ant = pos;
    int sig = (ant + 1) % sz(x);
    ll xf = x[ant], yf = y[ant];
    if (xf == x[sig])
    {
        if (y[sig] < yf)
            yf = yf - aK;
        else
            yf = yf + aK;
    }
    else
    {
        if (x[sig] < xf)
            xf = xf - aK;
        else
            xf = xf + aK;
    }
    return {xf, yf};
}

void cal(int ind, int sig, double piv, double &gx, double &gy)
{
    if (x[ind] == x[sig])
    {
        if (y[ind] > y[sig])
            gy = gy - piv;
        else
            gy = gy + piv;
    }
    else
    {
        if (x[ind] > x[sig])
            gx = gx - piv;
        else
            gx = gx + piv;
    }
}

double calcDisGC(double piv, int ind)
{
    int sig = (ind + 1) % N;
    double falt = k2, gx = x[ind], gy = y[ind];

    if (x[ind] == x[sig])
        gy = piv;
    else
        gx = piv;

    double sD;

    if (x[ind] == x[sig])
        sD = fabs(gy - y[sig]);
    else
        sD = fabs(gx - x[sig]);

    if (sD >= falt - EPS)
    {
        double cx = gx, cy = gy;
        cal(ind, sig, falt, cx, cy);
        return ham(gx, gy, cx, cy);
    }

    falt -= sD;

    int act = sig;

    double in = 0;
    if(act>0)
        in=pref2Ext[act-1];
    double val = in + falt;
    auto it1 = pref2Ext.begin() + act;
    auto it2 = pref2Ext.begin() + act + N;
    auto it = upper_bound(it1, it2, val);
    int j = (it - pref2Ext.begin()) - 1;
    if (j >= act)
    {
        double res = pref2Ext[j];
        if(act>0)
            res-=pref2Ext[act - 1];
        falt -= res;
        act = (j+1) % N;
    }

    int sig2 = (act + 1) % N;
    double cx = x[act], cy = y[act];
    cal(act, sig2, falt, cx, cy);
    return ham(gx, gy, cx, cy);
}

double distGC(int ind)
{
    int sig = (ind + 1) % N;
    double l, r;
    if (x[ind] == x[sig])
    {
        l = min(y[ind], y[sig]);
        r = max(y[ind], y[sig]);
    }
    else
    {
        l = min(x[ind], x[sig]);
        r = max(x[ind], x[sig]);
    }

    int cant = 0;
    double d1, d2, m1, m2;
    while (r - l > 1e-10 && cant < 90)
    {
        m1 = l + (r - l) / 3.0;
        m2 = r - (r - l) / 3.0;
        d1 = calcDisGC(m1, ind);
        d2 = calcDisGC(m2, ind);
        if (d1 < d2)
            r = m2;
        else
            l = m1;
        cant++;
    }
    return calcDisGC((l + r) / 2.0, ind);
}

vector<double> esprintando(int K, vector<int> &X, vector<int> &Y)
{
    k = K;
    k2 = K;
    N = sz(X);
    x = X;
    y = Y;
    int i;
    dis.resize(N, 0);
    dis2.resize(N, 0.0);
    pref.resize(N, 0);
    pref2.resize(N, 0.0);

    for (i = 0; i < N; ++i)
    {
        int sig = (i + 1) % N;
        dis2[i] = sqrt(ham(X[i], Y[i], X[sig], Y[sig]));
        dis[i] = dis2[i];
        if (i > 0)
        {
            pref[i] = pref[i - 1];
            pref2[i] = pref2[i - 1];
        }
        pref2[i] += dis2[i];
        pref[i] += dis[i];
    }

    pref2Ext.resize(2 * N);
    for (i = 0; i < 2 * N; ++i)
    {
        pref2Ext[i] = dis2[i % N];
        if (i > 0)
            pref2Ext[i] += pref2Ext[i - 1];
    }

    vector<double> ans(2);
    pair<int, int> p2 = fin(0);
    double ma = ham(x[0], y[0], p2.first, p2.second);
    for (i = 0; i < N; ++i)
    {
        p2 = fin(i);
        ma = max(ma, ham(x[i], y[i], p2.first, p2.second));
    }

    double mi = DBL_MAX;
    for (i = 0; i < N; ++i)
    {
        double val = distGC(i);
        mi = min(mi, val);
    }

    ans[0] = sqrt(mi);
    ans[1] = sqrt(ma);
    return ans;
}

