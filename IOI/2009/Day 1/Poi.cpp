//Link: https://oj.uz/problem/view/IOI09_poi
//Score: 100/100
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, t, p, i, j, tasks, punts, a;
    cin >> n >> t >> p;
    vector<vector<int>>v(n,vector<int>(t));
    vector<int>punt(t,n);
    vector<pair<int, pair<int, int>>>tabla;
    for(i=0; i<n; i++)
    {
        for(j=0; j<t; j++)
        {
            cin >> a;
            if(a)
            {
                punt[j]--;
            }
            v[i][j]=a;
        }
    }
    for(i=0; i<n; i++)
    {
        punts=0;
        tasks=0;
        for(j=0; j<t; j++)
        {
            if(v[i][j])
            {
                tasks++;
                punts+=punt[j];
            }
        }
        tabla.push_back({-punts,{-tasks,(i+1)}});
    }
    sort(tabla.begin(),tabla.end());
    for(i=0; i<int(tabla.size()); i++)
    {
        if(tabla[i].second.second==(p))
        {
            cout << -tabla[i].first << " " << i+1;
            return 0;
        }
    }
    return 0;
}
