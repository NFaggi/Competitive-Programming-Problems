//Link: https://codeforces.com/contest/2005/problem/B1
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, n, m, q,cal, i, x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> q;
        vector<long long>v(m);
        for(i=0; i<m; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        for(i=0; i<q; i++)
        {
            cin >> x;
            if(v[0]<x&&x<v[1])
            {
                if(x-v[0]==v[1]-x)
                {
                    cout << x-v[0] << '\n';
                }
                else if(x-v[0]>v[1]-x)
                {
                    cal=v[1]-x;
                    cal+=((x-v[0])-cal)/2;
                    cout << cal << '\n';
                }
                else
                {
                    cal=x-v[0];
                    cal+=((v[1]-x)-cal)/2;
                    cout << cal << '\n';
                }
            }
            else if(x<v[0])
            {
                cout << v[0]-1 << '\n';
            }
            else
            {
                cout << n-v[1] << '\n';
            }
        }
    }
    return 0;
}
