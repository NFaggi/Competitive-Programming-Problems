//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/110
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<vector<int>>comp;
vector<int>id;

int m[int(2e6)];

int main()
{
    ifstream en ("red.in");
    ofstream sa ("red.out");
    int pos = 1, a, b;
    char c;
    comp.resize(1000001);
    id.resize(1000001);
    en >> c;
    while (c != 'F')
    {
        en >> a >> b;
        if (m[a] == 0)
        {
            m[a] = pos;
            pos++;
            comp[pos - 1].push_back(pos - 1);
            id[pos-1]=pos-1;
        }
        if (m[b] == 0)
        {
            m[b] = pos;
            pos++;
            comp[pos - 1].push_back(pos - 1);
            id[pos-1]=pos-1;
        }
        if (c == 'C')
        {
            if (id[m[a]] != id[m[b]])
            {
                int x = id[m[a]], y = id[m[b]];

                if (comp[x].size() < comp[y].size())
                {
                    swap(m[a], m[b]);
                    swap(x, y);
                }
                for (int i= comp[y].size()-1; i>=0; i--)
                {
                    comp[x].push_back(comp[y][i]);
                    id[comp[y][i]] = x;
                    comp[y].pop_back();
                }
            }
        }
        else
        {
            sa << ((id[m[a]] == id[m[b]]) ? "S" : "N") << endl;
        }

        en >> c;
    }
    en.close();
    sa.close();
    return 0;
}
