//Link: https://oj.uz/problem/view/IOI14_game
//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define pb push_back
#define fr first
#define se second
#define mp make_pair
using namespace std;

const int MAXN=1501;


void initialize(int n) {

}

ll ars[MAXN];
int hasEdge(int u, int v)
{
    ll x=max(u,v);
    ars[x]++;
    return ars[x]==x;
}
