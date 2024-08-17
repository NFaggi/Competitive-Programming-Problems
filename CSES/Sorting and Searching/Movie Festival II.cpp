#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, k,i,a,b,c=0;
    cin >> n >> k;
    vector<pair<int,int>>v;
    vector<int>f;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        v.push_back({a,i});
        f.push_back(b);
    }
    sort(v.begin(),v.end());
    multiset<int>s;
    for(i=0; i<n; i++)
    {
        auto it=s.begin();
        while(int(s.size())>0&&*it<=v[i].first)
        {
            s.erase(it);
            it=s.begin();
            c++;
        }
        auto it2=s.rbegin();
        if(int(s.size())>=k&&*it2>f[v[i].second])
        {
            auto it3=s.find(*it2);
            s.erase(it3);
            s.insert(f[v[i].second]);
        }
        else if(int(s.size())<k)
        {
            s.insert(f[v[i].second]);
        }
    }
    cout << c+int(s.size());
    return 0;
}