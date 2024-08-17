#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    long long i, a, b, pos=1, n, cont=0;
    map<long long, int>m;
    vector<pair<long long,pair<int,long long>>>v;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        v.push_back({a,{1,1}});
        v.push_back({b,{0,a}});
    }
    sort(v.begin(),v.end());
    for(auto k:v)
    {
        if(k.second.first)
        {
            m[k.first]=pos;
        }
        else
        {
            if(m[k.second.second]==pos)
            {
                cont++;
                pos++;
            }
        }
    }
    cout << cont;
    return 0;
}