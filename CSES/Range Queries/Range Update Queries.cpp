#include <iostream>
#include <vector>
long long INF = 9223372036854775807;
using namespace std;
vector<long long>v;
vector<long long>I;
vector<long long>D;
long long update(long long a, long long nodo, long long sum)
{
    if (a > D[nodo] || a < I[nodo])
        return INF;
    if (a == I[nodo] && a == D[nodo])
        return v[nodo]+sum;
    return min(update(a, nodo * 2, sum+v[nodo]), update(a, nodo * 2 + 1, sum+v[nodo]));
}
void buscMin(long long a, long long b, long long nodo, long long aum)
{
    if (a > D[nodo] || b < I[nodo])
        return;
    if (a <= I[nodo] && b >= D[nodo])
    {
        v[nodo] += aum;
        return;
    }
    buscMin(a, b, nodo * 2, aum);
    buscMin(a, b, nodo * 2 + 1, aum);
 
}
int main()
{
    long long n, pot = 1, i, q;
    cin >> n >> q;
    while (pot < n)
        pot *= 2;
    v.resize(pot * 2, 0);
    I.resize(pot * 2);
    D.resize(pot * 2);
    for (i = pot; i < pot + n; i++)
    {
        cin >> v[i];
    }
    for (i = pot; i < I.size(); i++)
    {
        I[i] = i;
        D[i] = i;
    }
    for (i = pot - 1; i > 0; i--)
    {
        I[i] = I[i * 2];
        D[i] = D[i * 2 + 1];
    }
    while (q--)
    {
        long long a, b, c, d, pos;
        cin >> a >> b;
        if (a == 1)
        {
            cin >> c >> d;
            buscMin(b + pot - 1, c + pot - 1, 1, d);
        }
        else
        {
            cout << update(b + pot - 1, 1, 0) << endl;
        }
    }
    return 0;
}
