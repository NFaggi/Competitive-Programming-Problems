#include <bits/stdc++.h>

using namespace std;

struct Nodo
{
    int fin;
    int ma;
    int hijo[26];
    int tams[26];
    void iniciar()
    {
        ma=0;
        fin=0;
        for(int i=0; i<26; i++)
        {
            hijo[i]=-1;
            tams[i]=0;
        }
    }
};

const int largo = 5e5+1;
Nodo trie[largo];

int raiz = 0, tam = 1;
void Agregar(string s)
{
    int ta=s.size();
    int nod = raiz;
    for(auto c : s)
    {
        int x = c-'a';
        if(trie[nod].hijo[x]==-1)
        {
            trie[tam].iniciar();
            trie[nod].hijo[x]=tam;
            tam++;
        }
        trie[nod].tams[x]=max(trie[nod].tams[x],ta);
        trie[nod].ma=max(trie[nod].ma,trie[nod].tams[x]);
        nod = trie[nod].hijo[x];
        ta--;
    }
    trie[nod].fin=1;
}
vector<char>ans;
void start(int nod)
{
    if(trie[nod].fin)
        ans.push_back('P');
    int i;
    vector<pair<int,int>>v;
    for(i=0; i<26; i++)
    {
        if(trie[nod].hijo[i]!=-1)
        {
            v.push_back({trie[nod].tams[i],i});
        }
    }
    sort(v.begin(),v.end());
    for(i=0; i<int(v.size()); i++)
    {
        ans.push_back('a'+v[i].second);
        start(trie[nod].hijo[v[i].second]);
    }
    ans.push_back('-');
}
int main()
{
    trie[0].iniciar();
    int n, i;
    cin >> n;
    string s;
    for(i=0; i<n; i++)
    {
        cin >> s;
        Agregar(s);
    }
    start(raiz);
    while(ans.size()&&ans[int(ans.size())-1]=='-')
        ans.pop_back();
    cout << int(ans.size()) << '\n';
    for(auto k:ans)
    {
        cout << k << '\n';
    }
    return 0;
}
