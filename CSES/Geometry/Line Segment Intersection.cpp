#include <bits/stdc++.h>
using namespace std;
 
struct Point
{
    long long x, y;
};
 
long long cruz(Point A, Point B, Point O)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
bool mismoSeg(Point A, Point B, Point P)
{
    return min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) &&
           min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    long long d1, d2, d3, d4;
    cin >> t;
    bool inter=0;
 
    while (t--)
    {
        inter=0;
        Point A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        d1 = cruz(C, D, A);
        d2 = cruz(C, D, B);
        d3 = cruz(A, B, C);
        d4 = cruz(A, B, D);
 
        if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
                ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        {
            inter=1;
        }
        if (d1 == 0 && mismoSeg(C, D, A)) inter=1;
        if (d2 == 0 && mismoSeg(C, D, B)) inter=1;
        if (d3 == 0 && mismoSeg(A, B, C)) inter=1;
        if (d4 == 0 && mismoSeg(A, B, D)) inter=1;
 
        if (inter)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}
