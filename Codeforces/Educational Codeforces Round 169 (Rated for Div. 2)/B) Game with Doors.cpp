//Link: https://codeforces.com/contest/2004/problem/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, x1, y1, x2, y2, cant, i;
    cin >> t;
    while(t--)
    {
        cant=0;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1>y2||x2>y1)
            cout << 1 << '\n';
        else
        {
            cant=min(y1,y2)-max(x1,x2);
            if(x1>x2&&x1-1>=x2&&x1-1<=y2)
            {
                cant++;
            }
            else if(x2-1>=x1&&x2-1<=y1)
            {
                cant++;
            }
            if(y1<y2&&y1+1>=x2&&y1+1<=y2)
            {
                cant++;
            }
            else if(y2+1>=x1&&y2+1<=y1)
            {
                cant++;
            }
            cout << cant <<'\n';
        }    

    }
    return 0;
}
