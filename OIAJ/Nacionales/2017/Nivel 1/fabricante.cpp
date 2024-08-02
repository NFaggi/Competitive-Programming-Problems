//Link: https://juez.oia.unsam.edu.ar/task/55
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

int fabricante( int P, int precioVenta, int cantidadVenta, vector< int > precioCompra, vector< int > cantidadCompra, int & fabricante )
{
    int ing=precioVenta*cantidadVenta, res=-1, act, ma=0 ;
    fabricante=0;
    for(int i=0; i<int(precioCompra.size()); i++)
    {
        act=precioCompra[i]*max(cantidadCompra[i],cantidadVenta);
        if(act>P)
            continue;
        if(ma<=ing-act)
        {
            ma=ing-act;
            fabricante=i+1;
            res=ma;
        }    
    }
    return res;
}