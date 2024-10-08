//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/109
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin ("rayuela.in");
    ofstream cout ("rayuela.out");
    int D, P, cost, tam, i, j, l, aum=0;
    cin >> D >> P;
    string s;
    vector<vector<char>>sopa(D,vector<char>(D));
    vector<vector<int>>valor(D,vector<int>(D));
    for(i=0; i<D; i++)
    {
        for(j=0; j<D; j++)
        {
            cin >> sopa[i][j] >> valor[i][j];
        }
    }
    vector<vector<vector<int>>>dist(D,vector<vector<int>>(D,vector<int>(21,0)));
    for(i=0; i<P; i++)
    {
        cin >> s;
        tam=int(s.size());

        queue<pair<int,pair<int,pair<int,int>>>>pq;
        for(j=0; j<D; j++)
        {
            for(l=0; l<D; l++)
            {
                if(s[0]==sopa[j][l])
                {
                    pq.push({valor[j][l]+aum,{1,{j,l}}});
                }
            }
        }
        cost=aum;
        while(!pq.empty())
        {
            int val=pq.front().first, pos=pq.front().second.first, x=pq.front().second.second.first, y=pq.front().second.second.second;
            pq.pop();
            if(dist[x][y][pos]>val)
                continue;
            if(pos==tam)
            {
                cost=max(cost,val);
                continue;
            }
            if(x>0&&s[pos]==sopa[x-1][y])
            {
                if(dist[x-1][y][pos+1]<val+valor[x-1][y])
                {
                    pq.push({val+valor[x-1][y],{pos+1,{x-1,y}}});
                    dist[x-1][y][pos+1]=val+valor[x-1][y];
                }
            }
            if(x+1<D&&s[pos]==sopa[x+1][y])
            {
                if(dist[x+1][y][pos+1]<val+valor[x+1][y])
                {
                    pq.push({val+valor[x+1][y],{pos+1,{x+1,y}}});
                    dist[x+1][y][pos+1]=val+valor[x+1][y];
                }
            }
            if(y>0&&s[pos]==sopa[x][y-1])
            {
                if(dist[x][y-1][pos+1]<val+valor[x][y-1])
                {
                    pq.push({val+valor[x][y-1],{pos+1,{x,y-1}}});
                    dist[x][y-1][pos+1]=val+valor[x][y-1];
                }
            }
            if(y+1<D&&s[pos]==sopa[x][y+1])
            {
                if(dist[x][y+1][pos+1]<val+valor[x][y+1])
                {
                    pq.push({val+valor[x][y+1],{pos+1,{x,y+1}}});
                    dist[x][y+1][pos+1]=val+valor[x][y+1];
                }
            }
        }
        cout << cost-aum << '\n';
        aum+=181;
    }
    return 0;
}
