#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n, m, k;
    cin >> n >> m;
    vector<long long>h(n);
    vector<long long>res;
    multiset<long long>ms;
    for(long long i=0; i<n; i++)
    {
        cin >> k;
        ms.insert(-k);
    }
    for(long long i=0; i<m; i++)
    {
        long long q;
        cin >> q;
        auto it = ms.lower_bound(-q);
        if(it!=ms.end())
        {
            res.push_back(-(*it));
            ms.erase(it);
        }
        else
        {
            res.push_back(-1);
        }
 
    }
    for(long long i=0; i<res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
 
}
