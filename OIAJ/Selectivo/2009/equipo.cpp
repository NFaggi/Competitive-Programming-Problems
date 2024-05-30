//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/51
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long ma=0;
int sN=0;
string sMa="";
struct Nodo
{
    int hijo[26];
    long long afinidad;
    int eq;
};

Nodo trie[int(1e7)];

int raiz = 0, tam = 1;
void Agregar(string s)
{
    int nod = raiz, i, x;
    for(i=0; i<s.size(); i++)
    {
        x = s[i]-'a';
        if(trie[nod].hijo[x]==0)
        {
            trie[tam].eq=0;
            trie[nod].hijo[x]=tam;
            tam++;
        }
        nod = trie[nod].hijo[x];
        trie[nod].eq++;
        trie[nod].afinidad=trie[nod].eq*(i+1ll)*(i+1ll);
        if(trie[nod].eq>1&&trie[nod].afinidad>ma)
        {
            ma=trie[nod].afinidad;
            sMa=s;
            sN=i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, i;
    string s;
    ifstream cin ("equipo.in");
    ofstream cout ("equipo.out");
    cin >> n >> n;
    for(i=0; i<n; i++)
    {
        cin >> s;
        Agregar(s);
    }
    cout << ma << endl;
    cout << sMa.substr(0,sN+1);
    return 0;
}
