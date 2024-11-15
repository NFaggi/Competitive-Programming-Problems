#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > comp;
vector <int> id;
int cant, ma=0;
bool unionfind(int a, int b)
{
    if(id[a] == id[b])
        return false;
    int x = id[a], y = id[b];

    if(comp[x].size() < comp[y].size())
    {
        swap(a, b);
        swap(x, y);

    }
    for(int i:comp[y])
    {
        comp[x].push_back(i);
        id[i] = x;
    }
    ma=max(ma,int(comp[x].size()));
    cant--;
    return true;
}

int main()
{
    int n, m, a, b,i;
    cin >> n >> m;
    cant=n;
    id.resize(n+1);
    for(i=0; i<=n; i++)
    {
        comp.push_back({i});
        id[i] = i;
    }
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        unionfind(a,b);
        cout << cant << ' '<< ma <<'\n';
    }

    return 0;
}
