#include <bits/stdc++.h>
using namespace std;
 
const int TAM = 4000000;
const int MAXN = 200005;
 
struct nod
{
    long long sum;
    int l, r;
};
 
nod seg[TAM];
 
int in[MAXN], ta=1;
 
int update(int ind, int val, int p, int l, int r)
{
    int act=ta++;
    seg[act]=seg[ind];
    seg[act].sum+=val;
 
    if (l == r)
        return act;
 
    int mid = (l + r) / 2;
 
    if(p<=mid)
        seg[act].l=update(seg[act].l,val,p,l,mid);
    else
        seg[act].r=update(seg[act].r,val,p,mid+1,r);
 
    return act;
}
 
long long calc(int ind, int a, int b, int l, int r)
{
    if(ind==0)
        return 0;
    if (l >= a && r <= b)
        return seg[ind].sum;
    int mid = (l + r) / 2;
    long long res=0;
    if(a<=mid&&seg[ind].l)
        res+=calc(seg[ind].l, a, b, l, mid);
    if(b>mid&&seg[ind].r)
        res+=calc(seg[ind].r, a, b, mid + 1, r);
    return res;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, i, q;
    cin >> n >> q;
 
    vector<pair<long long,int>> v(n);
    vector<long long>xs(n);
 
    for (i = 0; i < n; i++)
    {
        cin >> xs[i];
        v[i]={xs[i],i+1};
    }
 
    sort(xs.begin(),xs.end());
    sort(v.begin(),v.end());
 
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
 
    int apos=0;
 
    for (i = 0; i < n; i++)
    {
        int pos=(lower_bound(xs.begin(),xs.end(),v[i].first)-xs.begin());
        in[pos]=update(in[apos],v[i].first,v[i].second,1,n);
        apos=pos;
    }
 
    
    while (q--)
    {
        int a, b;
        cin >> a >> b;
 
        long long ant = 0;
        long long ult = 1;
 
        while (true)
        {
            int ub = (upper_bound(xs.begin(),xs.end(), ult) - xs.begin())-1;
 
            if (ub < 0)
                break;
            long long su = calc(in[ub], a, b, 1,n);
            if (su == ant)
                break;
            ant = su;
            ult = su + 1;
        }
 
        cout << ult << '\n';
    }
 
    return 0;
}
