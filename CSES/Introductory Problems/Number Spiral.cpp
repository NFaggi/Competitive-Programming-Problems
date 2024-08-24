#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t, x, y, res;
    cin >> t;
    while(t--)
    {
        cin >> y >> x;
        if(y>x)
        {
            if(y%2==0)
            {
                res=y*y;
                res-=(x-1);
            }
            else
            {
                y--;
                res=y*y;
                res++;
                res+=(x-1);
            }
        }
        else
        {
            if(x%2==0)
            {
                x--;
                res=x*x;
                res++;
                res+=(y-1);
            }
            else
            {
                res=x*x;
                res-=(y-1);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
