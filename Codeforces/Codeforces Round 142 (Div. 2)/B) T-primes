//Link: https://codeforces.com/contest/230/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
    int i, j, n;
    long long x, sqr;
    vector<int>v(int(1e6)+1,1);
    v[0]=0;
    v[1]=0;
    for(i=0; i<int(v.size()); i++)
    {
        if(v[i]==0)
            continue;
        for(j=i+i; j<int(v.size()); j+=i)
        {
            v[j]=0;
        }
    }
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x;
        sqr=sqrt(x);
        if(sqr*sqr==x&&v[sqr]==1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
