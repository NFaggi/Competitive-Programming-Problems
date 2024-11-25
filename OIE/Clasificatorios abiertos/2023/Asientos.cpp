//Link: https://codeforces.com/gym/104597/problem/A
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t, f, a, n,pos,as;
    cin >> t;
    while(t--)
    {
        cin >> f >> a >> n;
        if(a==1)
        {
            cout << "AMBOS\n";
            continue;
        }
        as=n%a;
        if(as!=0&&as!=1)
        {
            cout << ":(\n";
            continue;
        }
        pos=(n-1)/a;
        if(pos%2==0)
        {
            if(as==1)
                cout << "VENTANA\n";
            else
                cout << "PASILLO\n";    
        }
        else
        {
            if(as==0)
                cout << "VENTANA\n";
            else
                cout << "PASILLO\n";
        }
    }
    return 0;
}