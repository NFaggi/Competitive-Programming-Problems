//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/108
#include <bits/stdc++.h>

using namespace std;
string s;
vector<vector<char>>sopa;
vector<pair<int,char>>v;
int D;
bool N(int p, int i, int j)
{
    int tam=int(s.size()), pos=0;
    while(i>=0)
    {
        if(s[pos]==sopa[i][j])
        {
            tam--;
            pos++;
        }
        else
            break;
        if(tam==0)
            break;
        i--;
    }
    if(tam==0)
    {
        v.push_back({p,'N'});
        return 1;
    }
    return 0;
}
bool O(int p, int i, int j)
{
    int tam=int(s.size()), pos=0;
    while(j>=0)
    {
        if(s[pos]==sopa[i][j])
        {
            tam--;
            pos++;
        }
        else
            break;
        if(tam==0)
            break;
        j--;
    }
    if(tam==0)
    {
        v.push_back({p,'O'});
        return 1;
    }
    return 0;
}
bool S(int p, int i, int j)
{
    int tam=int(s.size()), pos=0;
    while(i<D)
    {
        if(s[pos]==sopa[i][j])
        {
            tam--;
            pos++;
        }
        else
            break;
        if(tam==0)
            break;
        i++;
    }
    if(tam==0)
    {
        v.push_back({p,'S'});
        return 1;
    }
    return 0;
}
bool E(int p, int i, int j)
{
    int tam=int(s.size()), pos=0;
    while(j<D)
    {
        if(s[pos]==sopa[i][j])
        {
            tam--;
            pos++;
        }
        else
            break;
        if(tam==0)
            break;
        j++;
    }
    if(tam==0)
    {
        v.push_back({p,'E'});
        return 1;
    }
    return 0;
}
int main()
{
    ifstream cin ("rapigrama.in");
    ofstream cout ("rapigrama.out");
    int P, cost, tam, i, j, l, aum=0, fin;
    cin >> D >> P;
    sopa.resize(D,vector<char>(D));
    for(i=0; i<D; i++)
    {
        for(j=0; j<D; j++)
        {
            cin >> sopa[i][j];
        }
    }
    for(i=0; i<P; i++)
    {
        cin >> s;
        fin=0;
        for(j=0; j<D; j++)
        {
            for(l=0; l<D; l++)
            {
                if(sopa[j][l]==s[0])
                {
                    if(N(i+1,j,l)||O(i+1,j,l)||S(i+1,j,l)||E(i+1,j,l))
                    {
                        fin=1;
                        break;
                    }
                }
            }
            if(fin)
                break;
        }

    }
    for(auto k:v)
    {
        cout << k.first << ' ' << k.second << '\n';
    }
    return 0;
}
