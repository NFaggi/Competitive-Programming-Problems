//link: https://juez.oia.unsam.edu.ar/task/36
//score: 100/100
#include <bits/stdc++.h>

using namespace std;
int dp[101];
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    ifstream cin ("colgantes.in");
    ofstream cout ("colgantes.out");
    int n, a, cant=0, peso=0, act=0;
    cin >> n;
    while(n--)
    {
        cin >> a;
        dp[a]++;
    }
    for(n=1; n<101; n++)
    {
        act=dp[n]/2;
        cant+=act;
        peso+=(act*n)*2;
    }
    if(cant>0)
        cout << peso << ' ' << cant;
    else
        cout << "no se puede";
    return 0;
}
