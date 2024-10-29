//Link: https://codeforces.com/problemset/problem/1486/D
#include <bits/stdc++.h>

using namespace std;
vector<long long>seg,I,D;
int a, n,pot=1;
void update(long long nod)
{
    long long mi=max(seg[nod*2],seg[nod*2+1]);
    if(mi!=seg[nod])
    {
        seg[nod]=mi;
        if(nod!=1)
        update(nod/2);
    }
}
long long busMin(long long a, long long b, long long nod)
{
    if(I[nod]>b||D[nod]<a)
    return 0;
    else if(I[nod]>=a&&D[nod]<=b)
    {
        return seg[nod];
    }
    return max(busMin(a,b,nod*2),busMin(a,b,nod*2+1));
}
vector<long long> v;
bool can(long long x)
{
    int i, dif=0;
    long long obt;
    for(i=0; i<int(seg.size()); i++)
        seg[i]=0;
    for(i=0; i<n; i++)
    {
        if(v[i]>=x)
            dif--;
        else
            dif++;
        seg[i+pot]=dif;
        update((i+pot)/2);
    }
    if(seg[(a-1)+pot]<0)
        return true;
    for(i=a; i<n; i++)
    {
        if(seg[i+pot]<0)
            return true;
        obt=busMin(pot,(i-(a))+pot,1);
        if(seg[i+pot]-obt<0)
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a;
    v.resize(n);
    int i;
    while(pot<n)
        pot*=2;
    seg.resize(pot*2,0);
    I.resize(pot*2);
    D.resize(pot*2);
    for(i=pot; i<int(I.size()); i++)
    {
        I[i]=i;
        D[i]=i;
    }
    for(i=pot-1; i>0; i--)
    {
        I[i]=I[i*2];
        D[i]=D[i*2+1];
    }
    set<long long>s;
    vector<long long>pos;
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    for(auto k:s)
        pos.push_back(k);
    int mi=0, ma=int(pos.size())-1, piv,ult=pos[0];
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(pos[piv]))
        {
            mi=piv+1;
            ult=pos[piv];
        }
        else
        {
            ma=piv-1;
        }
    }
    cout << ult;
    return 0;
}
