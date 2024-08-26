#include <bits/stdc++.h>
 
using namespace std;
struct point
{
    long long x, y;
};
long long cruz(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}
long long cruz2(point A, point B, point O)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool mismoSeg(point A, point B, point P)
{
    return min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) &&
           min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    random_device rd;
    mt19937 gen(rd());
 
    uniform_int_distribution<> dis(1e9+1, INT_MAX);
 
    long long x = dis(gen), y=dis(gen), n, m, i, d1, d2, d3, d4,cant;
    cin >> n >> m;
    vector<point>v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i].x >> v[i].y;
    }
    point p, a, b,j,k;
    bool in, inter;
    while(m--)
    {
        in=0;
        cin >> p.x >> p.y;
        for(i=0; i<n; i++)
        {
            if(i<n-1)
            {
                a.x=p.x-v[i].x;
                a.y=p.y-v[i].y;
                b=v[i+1];
                b.x-=v[i].x;
                b.y-=v[i].y;
                j=v[i];
                k=v[i+1];
            }
            else
            {
                a.x=p.x-v[i].x;
                a.y=p.y-v[i].y;
                b=v[0];
                b.x-=v[i].x;
                b.y-=v[i].y;
                j=v[i];
                k=v[0];
            }
            if(cruz(b,a)==0&&mismoSeg(j,k,p))
            {
                in=1;
                break;
            }
        }
        if(in)
        {
            cout << "BOUNDARY\n";
        }
        else
        {
            cant=0;
            in = 1;
            point A, B, C, D;
            for(i=0; i<n; i++)
            {
                if(i<n-1)
                {
                    C=v[i];
                    D=v[i+1];
                }
                else
                {
                    C=v[i];
                    D=v[0];
                }
                A=p;
                B.x=x;
                B.y=y;
                inter=0;
                d1 = cruz2(C, D, A);
                d2 = cruz2(C, D, B);
                d3 = cruz2(A, B, C);
                d4 = cruz2(A, B, D);
 
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
                    cant++;
            }
 
            if(cant%2==0)
            {
                cout << "OUTSIDE\n";
            }
            else
            {
                cout << "INSIDE\n";
            }
        }
    }
    return 0;
}