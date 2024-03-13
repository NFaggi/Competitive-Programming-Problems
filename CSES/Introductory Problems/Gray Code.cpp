#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<vector<int>>lista(2);
    lista[0].push_back(0);
    lista[1].push_back(1);
    for(int i=1; i<n; i++)
    {
        int siz=lista.size();
        lista.resize(siz*2);
        k=siz-1;
        for(int j=siz; j<lista.size(); j++)
        {
            lista[j]=lista[k];
            k--;
        }
        for(int j=0; j<siz; j++)
        {
            lista[j].push_back(0);
        }
        for(int j=siz; j<lista.size(); j++)
        {
            lista[j].push_back(1);
        }
    }
    for(int i=0; i<lista.size(); i++)
    {
        for(int j=lista[i].size()-1; j>=0; j--)
        {
            cout << lista[i][j];
        }
        cout << endl;
    }
    return 0;
}
