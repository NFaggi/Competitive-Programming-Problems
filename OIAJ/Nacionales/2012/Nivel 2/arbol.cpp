//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/10
#include <bits/stdc++.h>

using namespace std;
vector<vector<long long>>grafo;
vector<bool>visitados;
long long vis=0;
void DFS(int nodo)
{
    if(visitados[nodo]==false)
        vis++;
    visitados[nodo] = true;
    for(int i=0; i<grafo[nodo].size(); i++)
    {
        if(!visitados[grafo[nodo][i]])
        {
            DFS(grafo[nodo][i]);
        }
    }

}
int main()
{
    ifstream ent ("arbol.in");
    ofstream sal ("arbol.out");
    long long n, m, a, b, i;
    bool reg1=true, reg2=true, reg3=true;
    ent >> n >> m;
    grafo.resize(n+1);
    visitados.resize(n+1);
    vector<long long> punt(n+1,0);
    vector<long long> raices;
    vector<long long> multArcos;
    vector<long long> sinCaminos;
    for(i=0; i<m; i++)
    {
        ent >> a >> b;
        grafo[a].push_back(b);
        punt[b]++;
    }
    for(i=1; i<punt.size(); i++)
    {
        if(punt[i]==0)
        {
            raices.push_back(i);
        }
        if(punt[i]>1)
        {
            multArcos.push_back(i);
            reg2=false;
        }
    }
    if(raices.size()!=1)
    {
        reg1=false;
        reg3=false;
    }
    if(reg1)
    {
        DFS(raices[0]);
        for(i=1; i<visitados.size(); i++)
        {
            if(visitados[i]==0)
                sinCaminos.push_back(i);
        }
        if(sinCaminos.size()>0)
            reg3=false;
    }
    if(raices.size()==1&&multArcos.size()==0&&sinCaminos.size()==0)
    {
        sal << "Si "<< raices[0] << "\n";
    }
    else
    {
        sal << "No" << "\n";
        if(raices.size()==0)
        {
            sal << 0 << "\n";
        }
        else
        {
            for(auto j:raices)
            {
                sal << j << ' ';
            }
            sal << "\n";
        }
        if(multArcos.size()==0)
        {
            sal << 0 << "\n";
        }
        else
        {
            for(auto j:multArcos)
            {
                sal << j << ' ';
            }
            sal << "\n";
        }
        if(sinCaminos.size()==0)
        {
            sal << 0 << "\n";
        }
        else
        {
            for(auto j:sinCaminos)
            {
                sal << j << ' ';
            }
            sal << '\n';
        }
    }
    return 0;
}
