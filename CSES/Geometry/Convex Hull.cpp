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

struct cord
{
    ll x, y;
};

ll cruz(cord &A, cord &B)
{
    return A.x*B.y-A.y*B.x;
}

void unir(cord &A, cord &B, cord &X)
{
    X.x=B.x-A.x;
    X.y=B.y-A.y;
}

ll ori(cord A, cord B, cord C)
{
    cord X, Y;
    unir(A,B,X);
    unir(A,C,Y);
    return cruz(X,Y);
}

bool ord(cord &A, cord &B)
{
    if(A.x!=B.x)
        return A.x<B.x;
    return A.y<B.y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, i;
    cin >> n;

    vector<cord>v(n);

    for(i=0; i<n; i++)
        cin >> v[i].x >> v[i].y;
    
    sort(all(v),ord);


    vector<cord>topH, botH, q;

    auto del=[&](ll x)-> bool
    {
        if(x==0)
            return ori(q[sz(q)-2],q[sz(q)-1],v[i])<0;
        return ori(q[sz(q)-2],q[sz(q)-1],v[i])>0;
    };

    auto calc=[&](ll x)
    {
        q.pb(v[0]);
        for(i=1; i<sz(v); i++)
        {
            while(sz(q)>1&&del(x))
                q.pop_back();
            q.pb(v[i]);
        }
    };
    
    // top hull
    calc(0);
    swap(q,topH);

    // bottom hull
    calc(1);
    swap(q,botH);

    botH.pop_back();
    reverse(all(botH));
    botH.pop_back();

    // unir
    vector<cord>pts;
    for(auto &k: topH)
        pts.pb(k);
    for(auto &k: botH)
        pts.pb(k);
    
    // respuesta
    cout << sz(pts) << '\n';
    for(auto &k:pts)
        cout << k.x << ' ' << k.y << '\n';
    return 0;
}

