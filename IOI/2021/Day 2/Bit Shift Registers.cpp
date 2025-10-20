//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

void append_move(int t, int x);
void append_store(int t, std::vector<bool> v);
void append_and(int t, int x, int y);
void append_or(int t, int x, int y);
void append_xor(int t, int x, int y);
void append_not(int t, int x);
void append_left(int t, int x, int s);
void append_right(int t, int x, int s);
void append_add(int t, int x, int y);
void append_print(int t);
void construct_instructions(int s, int n, int k, int q);

void todo(ll &k)
{
    append_and(1,0,99); // solo pares

    append_right(2,0,k);
    append_and(2,2,99); // solo impares

    append_xor(3,2,99); // impares negados

    append_add(3,3,1); // sumar -impares+pares
    append_right(3,3,k);
    append_add(3,3,99); // quedan k unos si n1<n2 o k ceros si n1>n2

    append_and(4,3,1); // solo los pares que son < a n2
    append_not(3,3); // quedan k unos si n1>n2 o k ceros si n1<n2

    append_and(5,2,3); // solo los impares que son < n1

    append_or(6,5,4); // union de pares e impares <

    append_xor(1,4,1); // solo pares que son > n2
    append_left(1,1,k); // moverlos a la posicion correspondiente

    append_xor(2,2,5); // solo impares que son > n1
    append_left(2,2,k); // moverlos a la posicion correspondiente

    append_or(7,2,1); // unir pares e impares >
    append_or(0,7,6); // unir ambos vectores
}

void construct_instructions1(int s, int n, int k, int q)
{
    ll i, b=2000, j;
    vector<bool>v(b,0);
    for(j=0; j<n; j+=2)
        for(i=0; i<k; i++)
            v[i+j*k]=1;
    append_store(99,v); 

    if(n%2!=0)
    {
        vector<bool>v2(b,0);
        for(i=0; i<k; i++)
            v2[i+n*k]=1;
        append_store(97,v2);
        append_or(0,0,97);
        n++;
    }

    ll cant=50;
    if(n==2)
        cant=1;
    for(i=0; i<cant; i++)
    {
        todo(k); // ordenar de a pares i e i+1
        append_move(98,0);
    
        append_left(0,0,b-k*(n-1)); // borrar el ultimo numero
        append_right(0,0,b-k*(n-2)); // borrar el primer numero
    
        todo(k); // ordenar de a pares i e i+1
        append_left(0,0,k); // dejar lugar para el primer numero
    
        append_left(96,98,b-k); // borrar todos los numeros menos el primero
        append_right(96,96,b-k); // acomodar el primer numero
        append_or(0,0,96); // agregarlo a 0
    
        append_right(96,98,k*(n-1)); // borrar todos los numeros menos el ultimo
        append_left(96,96,k*(n-1)); // acomodar el ultimo numero
        append_or(0,0,96); // agregarlo a 0
    }
}
void construct_instructions(int s, int n, int k, int q) {
    if(s==1)
    {
        construct_instructions1(s,n,k,q);
        return;
    }
    ll pot=1, i, act=1, j, m=1;

    while(pot<n)
        pot*=2;

    vector<bool>v(2000,0);

    for(i=n; i<pot; i++)
        for(j=0; j<k; j++)
            v[i*k+j]=1;
    append_store(m,v);
    append_or(0,m,0);

    while(act<n)
    {
        act*=2;
        for(i=0; i<pot; i++)
        {
            if(i%act)
            {
                for(j=0; j<k; j++)
                    v[i*k+j]=0;
            }
            else
            {
                for(j=0; j<k; j++)
                    v[i*k+j]=1;
            }
        }
        append_store(1,v); // deshabilitar impares (comando)
        append_and(2,1,0); // par

        append_xor(3,2,0); // impar
        append_right(3,3,k*(act/2)); // alinear
        append_xor(3,3,1); // negar impar

        append_add(4,3,2); // -impar+par
        append_right(4,4,k); // alinear signo al inicio
        append_and(4,1,4); // solo dejar los signos y nada de basura
        append_add(4,1,4); // deja en 0 las posiciones donde el par era mas grande

        append_and(2,4,2); // solo dejamos habilitados los pares mas chicos

        append_not(4,4); // negamos para dejar en 1 las posiciones donde el par era el mas grande

        append_xor(3,3,1);
        append_and(3,4,3); // solo dejamos habilitado los impares mas chicos

        append_or(0,3,2); // dejamos los numeros mas chicos
    }

}
