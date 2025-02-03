#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin ("latas.in");
    ofstream cout ("latas.out");
    int n, i, j, k;
    long long mi=LLONG_MAX, act;
    cin >> n;
    vector<vector<long long>>lats(n,vector<long long>(n,0));
    vector<long long>diag(n+1,0);
    vector<long long>vert(n,0);
    vector<long long>horiz(n,0);
    vector<vector<long long>>uniones(n,vector<long long>(n,0));
    long long sum=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<(n-(n-(i+1))); j++)
        {
            cin >> lats[i][j];
            sum+=lats[i][j];

        }
    }
    //Vertical
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            vert[j]+=lats[i][j];
        }
        if(j>0)
            vert[j]+=vert[j-1];
    }
    //Horizontal
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            horiz[i]+=lats[i][j];
        }
        if(i>0)
            horiz[i]+=horiz[i-1];
    }
    //Diagonal
    for(j=n-1; j>=0; j--)
    {
        k=j;
        for(i=n-1; i>=0; i--)
        {
            if(k>=n)
                break;
            diag[j]+=lats[i][k];
            k++;
        }
        diag[j]+=diag[j+1];
    }
    //Uniones
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i>0)
            {
                uniones[i][j]+=uniones[i-1][j];
            }
            if(j>0)
            {
                uniones[i][j]+=uniones[i][j-1];
            }
            if(i>0&&j>0)
            {
                uniones[i][j]-=uniones[i-1][j-1];
            }
            uniones[i][j]+=lats[i][j];
        }
    }
    //Calculo
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            act=0;
            if(i>0)
            {
                act+=horiz[i-1];
            }
            if(j>0)
            {
                act+=vert[j-1];
            }
            if(i>0&&j>0)
            {
                act-=uniones[i-1][j-1];
            }
            int diaPos=j+(n-(n-i))+1;
            if(diaPos<n)
            act+=diag[diaPos];
            mi=min(act,mi);
        }
    }
    cout << mi << '\n';
    return 0;
}
