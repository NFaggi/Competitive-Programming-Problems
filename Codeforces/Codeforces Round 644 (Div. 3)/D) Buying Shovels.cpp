//Link: https://codeforces.com/contest/1360/problem/D
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, k, div, cost, i;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cost=n;
        for(i=1; i<=sqrt(n)&&i<=k; i++)
        {
            if(n%i==0)
            {
                div=n/i;
                if(div<=k)
                {
                    cost=min(i,cost);
                }
                else
                {
                    cost=min(div,cost);
                }
            }
        }
        cout << cost << '\n';
    }
    return 0;
}
