#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
 
struct nods
{
    ll hijos[26];
    void iniciar()
    {
        for(ll i=0; i<26; i++)
            hijos[i]=-1;
    }
};

const int TAM=6e5;
const int SQ=317;
const int MAXN=5e5+1;

ll ap[TAM], act=1, lsp[MAXN];

nods Trie[TAM];

void busc(string &s, ll l)
{
    ll nod=0, x;
    ap[nod]=1;
    for(; l<sz(s); l++)
    {
        x=s[l]-'a';
        if(Trie[nod].hijos[x]==-1)
            return;
        nod=Trie[nod].hijos[x];
        ap[nod]=1;
    }
}

ll agregar(string &s)
{
    ll nod=0, x;
    for(auto k:s)
    {
        x=k-'a';
        if(Trie[nod].hijos[x]==-1)
        {
            Trie[act].iniciar();
            Trie[nod].hijos[x]=act++;
        }
        nod=Trie[nod].hijos[x];
    }
    return nod;
}

bool comp(string &a, string &b)
{
    return sz(a)<sz(b);
}

void calcLSP(string &s)
{
    ll i, len=0;
    for(i=1; i<sz(s); i++)
    {
        while(len>0&&s[i]!=s[len])
            len=lsp[len-1];
        if(s[i]==s[len])
            len++;
        lsp[i]=len;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie[0].iniciar();

    ll n, i, j, k;
    string s;
    
    cin >> s >> n;

    vector<string>v(n);
    vector<ll>ans(n), fin(n);

    for(i=0; i<n; i++)
        cin >> v[i];
    bool band;
    for(i=0; i<sz(v); i++)
    {
        if(sz(v[i])<SQ)
            fin[i]=agregar(v[i]);
        else
        {
            calcLSP(v[i]);
            k=0;
            band=0;
            for(j=0; j<sz(s); j++)
            {
                while(k>0&&s[j]!=v[i][k])
                    k=lsp[k-1];
                if(s[j]==v[i][k])
                    k++;
                if(k==sz(v[i]))
                {
                    band=1;
                    break;
                }
            }
            ans[i]=band;
        }
    }

    for(i=0; i<sz(s); i++)
        busc(s,i);
    for(i=0; i<n; i++)
        if(sz(v[i])<SQ)
            ans[i]=ap[fin[i]];
    for(i=0; i<n; i++)
        cout << ((ans[i])?"YES":"NO") << '\n';
    return 0;
}
