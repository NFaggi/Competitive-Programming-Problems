//Link: https://juez.oia.unsam.edu.ar/task/177
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define fr first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

string cafes(vector<string> &nombres, vector<int> &precios, vector<int> &distancias) {
    vector<pair<ll,pair<ll,ll>>>v;
    for(ll i=0; i<sz(nombres); i++)
    {
        ll pd=1ll*precios[i]*distancias[i];
        v.pb({pd,{precios[i],i}});
    }
    sort(all(v));
    return nombres[v[0].se.se];
}
