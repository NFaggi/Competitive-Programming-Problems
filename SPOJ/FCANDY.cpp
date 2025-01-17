//Link:https://www.spoj.com/problems/FCANDY/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int cero=20000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, k, c, j, d, res=20000;
    cin >> n;

    bitset<40001>b[n+1]; ///La maxima diferencia que podemos tener es de 20000 (explicacion de esto: 1*), y ahora cero es 20000 para evitar usar numeros negativos
    b[0][cero]=1;

    for(i=1; i<=n; i++)
    {
        cin >> k >> c;
        for(j=0; j<=k/2; j++)
        {
            d=(k-j*2)*c; ///Calculamos la distancia de la pregunta, ¿que pasa si a un grupo le doy j y al otro lo que reste? ¿cual seria la diferencia de eso?
            /// y la respuesta es que un grupo se quedaria con j caramelos mientras que el otro se quedaria con k-j y la diferencia entre los 2 seria k-j*2
            b[i]|=b[i-1]<<d; ///las posibilidades que nos deja sacarle d de distancia
            b[i]|=b[i-1]>>d; ///las posibilidades que nos deja agregarle d de distancia
        }
    }

    for(i=0; i<40001; i++)
        if(b[n][i]) /// revisamos si es posible llegar a esa diferencia
            res=min(res,abs(cero-i)); ///Guardamos la menor diferencia

    cout << res;

    return 0;
}


/// 1* imaginemos que tenemos 100 caramelos, el peor caso que podemos tener es tener 20000 de diferencia, debido a que si agarramos de cada tipo de caramelo
/// la mitad de su cantidad y la repartimos en partes iguales, solo nos quedara repartir 1 si la cantidad de caramelos es impar, y en el peor de los casos
/// todos los caramelos tienen cantidades impares, lo cual nos quedara 1 de cada tipo y en el peor de los casos todos son de 200 calorias, si hacemos
/// 100*200=20000 que son los caramelos que no podemos dividir en partes iguales, por esto no nos importa lo que queda comprendio entre >20000 y <-20000
