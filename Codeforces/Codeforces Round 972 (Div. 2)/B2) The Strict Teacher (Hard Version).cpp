//Link: https://codeforces.com/contest/2005/problem/B2
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, n, m, q,cal, i, x, l, r;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> q;
        vector<long long>v(m),vneg(m);
        for(i=0; i<m; i++)
        {
            cin >> v[i];
            vneg[i]=-v[i];
        }
        sort(v.begin(),v.end());
        sort(vneg.begin(),vneg.end());
        for(i=0; i<q; i++)
        {
            cin >> x;
            auto it = lower_bound(v.begin(),v.end(),x);
            if(it==v.end())
            {
                r=-1;
            }
            else
            {
                r=*it;
            }
            auto it2 = lower_bound(vneg.begin(),vneg.end(),-x);
            if(it2==vneg.end())
            {
                l=-1;
            }
            else{
                l=-(*it2);
            }
            if(l!=-1&&r!=-1&&l<x&&x<r)
            {
                if(x-l==r-x)
                {
                    cout << x-l << '\n';
                }
                else if(x-l>r-x)
                {
                    cal=r-x;
                    cal+=((x-l)-cal)/2;
                    cout << cal << '\n';
                }
                else
                {
                    cal=x-l;
                    cal+=((r-x)-cal)/2;
                    cout << cal << '\n';
                }
            }
            else if(r!=-1&&x<r)
            {
                cout << r-1 << '\n';
            }
            else
            {
                cout << n-l << '\n';
            }
        }
    }
    return 0;
}
