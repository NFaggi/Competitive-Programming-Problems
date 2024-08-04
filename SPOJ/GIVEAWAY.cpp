//Link:https://www.spoj.com/problems/GIVEAWAY/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
int v[MAXN];
vector<int>blocks[(MAXN/800)+1];
int tam;
void cons(int n)
{
    tam=sqrt(n);
    int i;
    for(i=0; i<n; i++)
    {
        blocks[i/tam].push_back(v[i]);
    }
    for(i=0; i<=n/tam; i++)
    {
        sort(blocks[i].begin(),blocks[i].end());
    }
}
void update(int a, int b)
{
    int ant=v[a],block=a/tam, i;
    v[a]=b;
    for(i=0; i<int(blocks[block].size()); i++)
    {
        if(blocks[block][i]==ant)
        {
            blocks[block][i]=b;
            break;
        }
    }
    sort(blocks[block].begin(),blocks[block].end());
}
int cal(int a, int b, int c)
{
    int in=a/tam, fin=b/tam,can=0,i;
    if(in==fin)
    {
        for(i=a; i<=b; i++)
        {
            if(v[i]>=c)
                can++;
        }
    }
    else
    {
        for(i=a; i<((in+1)*tam); i++)
        {
            if(v[i]>=c)
            {
                can++;
            }
        }
        for(i=in+1; i<fin; i++)
        {
            auto it = lower_bound(blocks[i].begin(),blocks[i].end(),c);
            if(it!=blocks[i].end())
            {
                can+=distance(it,blocks[i].end());
            }
        }
        for(i=fin*tam; i<=b; i++)
        {
            if(v[i]>=c)
            {
                can++;
            }
        }
    }
    return can;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i, q, a, b, c, d;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    cons(n);
    cin >> q;
    while(q--)
    {
        cin >> a >> b >> c;
        if(a==0)
        {
            cin >> d;
            cout << cal(b-1,c-1,d) << '\n';
        }
        else
        {
            update(b-1,c);
        }
    }
    return 0;
}
