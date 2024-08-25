#include <bits/stdc++.h>
using namespace std;
struct point
{
    long long x, y;
};

long long cruz (point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t,res;
    cin >> t;
    point a, b, c, d, e;
    while(t--)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        d.x=c.x-a.x;
        d.y=c.y-a.y;
        e.x=b.x-a.x;
        e.y=b.y-a.y;
        res=cruz(e,d);
        if(res>0)
            cout << "LEFT\n";
        else if(res<0)
            cout << "RIGHT\n";
        else
            cout << "TOUCH\n";

    }
    return 0;
}
