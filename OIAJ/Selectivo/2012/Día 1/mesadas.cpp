//Link: https://juez.oia.unsam.edu.ar/task/84
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin ("mesadas.in");
    ofstream cout ("mesadas.out");
    int n, i;
    long long a, b;
    cin >> n;
    vector<pair<long long, long long>>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if(v[i].first<v[i].second)
            swap(v[i].first,v[i].second);
        v[i].first*=-1ll;
        v[i].second*=-1ll;
    }
    sort(v.begin(),v.end());
    vector<long long>s;
    for(i=0; i<n; i++)
    {
        auto it=lower_bound(s.begin(),s.end(),-v[i].second);
        if(it==s.end())
        {
            s.push_back(-v[i].second);
        }
        else
        {
            *it=(-v[i].second);
        }
    }
    cout << s.size();
    return 0;
}
