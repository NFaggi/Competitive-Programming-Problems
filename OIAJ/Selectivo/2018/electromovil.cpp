//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/49
#include <bits/stdc++.h>

using namespace std;

vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia)
{
    vector<int>res;
    int i;
    long long viaje=autonomia[0], maAu=0, maU=0;
    for(i=1; i<ubicacion.size(); i++)
    {
        if(ubicacion[i]<=viaje)
        {
            if(maAu<ubicacion[i]+autonomia[i])
            {
                maAu=ubicacion[i]+autonomia[i];
                maU=ubicacion[i];
            }
        }
        else if(maU!=0&&maAu!=0)
        {
            viaje=maAu;
            res.push_back(maU);
            i--;
            maAu=0;
            maU=0;
        }
        else
        {
            res.resize(0);
            return res;
        }
    }
    if(viaje>=ubicacion[ubicacion.size()-1])
    {
        if(res.size()>0)
        {
            if(res[res.size()-1]!=ubicacion[ubicacion.size()-1])
            res.push_back(ubicacion[ubicacion.size()-1]);
        }
        else
        {
            res.push_back(ubicacion[ubicacion.size()-1]);
        }
    }
    else
    {
        viaje=maU+maAu;
        res.push_back(maU);
        if(viaje>=ubicacion[ubicacion.size()-1])
        {
            if(res.size()>0)
            {
                if(res[res.size()-1]!=ubicacion[ubicacion.size()-1])
                res.push_back(ubicacion[ubicacion.size()-1]);
            }
            else
            {
                res.push_back(ubicacion[ubicacion.size()-1]);
            }
        }
        else
        {
            res.resize(0);
        }
    }
    return res;
}
