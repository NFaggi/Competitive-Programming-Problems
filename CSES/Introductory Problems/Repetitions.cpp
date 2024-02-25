#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int max = 1, cant=1;
    string letras;
    cin >> letras;
    for (int i = 1; i < letras.size(); i++)
    {
        if (letras[i] == letras[i - 1])
        {
            cant++;
            if (cant > max)
                max = cant;
        }
        else
        {
            cant = 1;
        }
    }
    cout << max;
    return 0;
