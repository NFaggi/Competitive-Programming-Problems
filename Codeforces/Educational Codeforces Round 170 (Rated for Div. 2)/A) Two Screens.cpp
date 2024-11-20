//Link: https://codeforces.com/contest/2025/problem/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, mi, i, cant=0,tam;
    cin >> t;
    string a, b;
    while(t--)
    {
        cin >> a >> b;
        mi=min(int(a.size()),int(b.size()));
        tam=int(a.size())+int(b.size());
        cant=0;
        for(i=0; i<mi; i++)
        {
            if(a[i]==b[i])
            {
                cant++;
            }
            else
            {
                break;
            }
        }
        if(cant>0)
        {
            tam-=cant;
            tam++;
        }
        cout << tam << '\n';
    }
    return 0;
}
