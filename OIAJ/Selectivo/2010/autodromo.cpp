//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/12
#include <bits/stdc++.h>

#define ll long long
#define sz(x) int(x.size())
using namespace std;
ll INF = LLONG_MAX;
vector<ll>seg, I, D;
void update(ll pos, ll x)
{
    seg[pos] += x;
    pos /= 2;
    while (pos > 0)
    {
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
        pos /= 2;
    }
}
ll calc(ll a, ll b, ll nod)
{
    if (I[nod] > b || D[nod] < a)
        return 0;
    if (I[nod] >= a && D[nod] <= b)
        return seg[nod];
    return calc(a, b, nod * 2) + calc(a, b, nod * 2 + 1);
}
int main()
{
    ll m, i, x1, y1, x2, y2, tot = 0, in, fin, pot = 65536, j, inx, iny;

    /// LECTURA

    ifstream cin ("autodromo.in");
    ofstream cout ("autodromo.out");
    cin >> m;
    vector<pair<ll, pair<ll, ll>>>vx1, vy1, vx2, vy2;
    cin >> x1 >> y1;
    inx = x1;
    iny = y1;
    for (i = 1; i < m; i++)
    {
        cin >> x2 >> y2;
        if (x1 == x2)
        {
            if (y1 < y2)
                vx1.push_back({ x1,{y1,y2} });
            else
                vx1.push_back({ x1,{y2,y1} });
        }
        else
        {
            if (x1 < x2)
                vy1.push_back({ x1,{x2,y1} });
            else
                vy1.push_back({ x2,{x1,y1} });
        }
        x1 = x2;
        y1 = y2;
    }
    x2 = inx;
    y2 = iny;
    if (x1 == x2)
    {
        if (y1 < y2)
            vx1.push_back({ x1,{y1,y2} });
        else
            vx1.push_back({ x1,{y2,y1} });
    }
    else
    {
        if (x1 < x2)
            vy1.push_back({ x1,{x2,y1} });
        else
            vy1.push_back({ x2,{x1,y1} });
    }
    sort(vx1.begin(), vx1.end());
    sort(vy1.begin(), vy1.end());
    cin >> m;
    cin >> x1 >> y1;
    inx = x1;
    iny = y1;
    for (i = 1; i < m; i++)
    {
        cin >> x2 >> y2;
        if (x1 == x2)
        {
            if (y1 < y2)
                vx2.push_back({ x1,{y1,y2} });
            else
                vx2.push_back({ x1,{y2,y1} });
        }
        else
        {
            if (x1 < x2)
                vy2.push_back({ x1,{x2,y1} });
            else
                vy2.push_back({ x2,{x1,y1} });
        }
        x1 = x2;
        y1 = y2;
    }
    x2 = inx;
    y2 = iny;
    if (x1 == x2)
    {
        if (y1 < y2)
            vx2.push_back({ x1,{y1,y2} });
        else
            vx2.push_back({ x1,{y2,y1} });
    }
    else
    {
        if (x1 < x2)
            vy2.push_back({ x1,{x2,y1} });
        else
            vy2.push_back({ x2,{x1,y1} });
    }
    sort(vx2.begin(), vx2.end());
    sort(vy2.begin(), vy2.end());

    /// FIN DE LECTURA

    /// INICIALIZACION DE SEGMENT TREE

    seg.resize(pot * 2, 0);
    I.resize(pot * 2);
    D.resize(pot * 2);
    for (i = pot; i < sz(I); i++)
    {
        I[i] = i;
        D[i] = i;
    }
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
    }

    /// FIN DE INICIALIZACION

    /// CALCULOS
    // VERTICALES AUTODROMO 1 Y HORIZONTALES AUTODROMO 2

    set<pair<ll, ll>>s; //x fin y altura y
    j = 0;
    for (i = 0; i < sz(vx1); i++)
    {
        while (j < sz(vy2) && vy2[j].first < vx1[i].first)
        {
            if (vy2[j].second.first > vx1[i].first)
            {
                update(vy2[j].second.second + pot, 1);
                s.insert({ vy2[j].second.first,vy2[j].second.second });
            }
            j++;
        }
        auto it = s.begin();
        while (it != s.end() && it->first <= vx1[i].first)
        {
            update(it->second + pot, -1);
            it = s.erase(it);
        }
        tot += calc(vx1[i].second.first + pot, vx1[i].second.second + pot, 1);

    }

    // VERTICALES AUTODROMO 2 Y HORIZONTALES AUTODROMO 1
    seg.resize(0);
    seg.resize(pot * 2, 0);
    s.clear();
    j = 0;
    for (i = 0; i < sz(vx2); i++)
    {
        while (j < sz(vy1) && vy1[j].first < vx2[i].first)
        {
            if (vy1[j].second.first > vx2[i].first)
            {
                update(vy1[j].second.second + pot, 1);
                s.insert({ vy1[j].second.first,vy1[j].second.second });
            }
            j++;
        }
        auto it = s.begin();
        while (it != s.end() && it->first <= vx2[i].first)
        {
            update(it->second + pot, -1);
            it = s.erase(it);
        }
        tot += calc(vx2[i].second.first + pot, vx2[i].second.second + pot, 1);

    }
    /// FIN DE CALCULOS
    cout << tot;
    return 0;
}
