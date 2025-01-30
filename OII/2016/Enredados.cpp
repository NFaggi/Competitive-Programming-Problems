//Score: 100/100
#include <bits/stdc++.h>
using namespace std;

const int MAXN=1500001;

int v[MAXN], fen[MAXN], n;

void update(int nod)
{
    while(nod<MAXN)
    {
        fen[nod]++;
        nod=nod+(nod&-nod);
    }
}

int calc(int nod)
{
    int sum=0;
    while(nod>0)
    {
        sum+=fen[nod];
        nod-=(nod&-nod);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i, x;
    long long cost=0;
    cin >> n;
    n=n/2;
    for(i=0; i<n; i++)
    {
        cin >> x;
        v[x-1]=i;
    }

    for(i=0; i<n; i++)
    {
        cin >> x;
        x=v[x-1];
        cost+=(x-calc(x));
        update(x+1);
    }
    cout << cost << '\n';
    return 0;
}
