//Score: 100/100
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

ll pot[33];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, q, i, num=0, num2, j, t, ans, sup, cant;
    cin >> n >> k >> q;

    pot[0]=1;
    for(i=1; i<33; i++)
        pot[i]=pot[i-1]*2ll;

    map<string,ll>ma;
    vector<ll>v(n), sig(n), ant(n);
    vector<vector<ll>>mat(k,vector<ll>(k));
    string a, b, s;

    for(i=0; i<n; i++)
    {
        cin >> s >> sup;
        ma[s]=num++;
        v[i]=sup-1;
        sig[i]=i-1;
        ant[i]=i+1;
    }

    for(i=0; i<k; i++)
        for(j=0; j<k; j++)
            cin >> mat[i][j];

    while(q--)
    {
        cin >> t;
        if(t==1)
        {
            cin >> a >> b;
            num=ma[a];
            num2=ma[b];
            if(sig[num]>-1)
                ant[sig[num]]=ant[num];
            if(ant[num]<n)
                sig[ant[num]]=sig[num];
            ant[num]=num2;
            sig[num]=sig[num2];
            if(sig[num2]>-1)
                ant[sig[num2]]=num;
            sig[num2]=num;
        }
        else if(t==2)
        {
            cin >> a >> sup;
            num=ma[a];
            v[num]=sup-1;
        }
        else
        {
            cin >> a;
            num=ma[a];
            num2=num;
            ans=0;
            cant=0;
            while(cant<31)
            {
                num=sig[num];
                if(num==-1)
                    break;
                ans+=(mat[v[num2]][v[num]])/pot[cant];
                cant++;
            }
            num=num2;
            cant=0;
            while(cant<31)
            {
                num=ant[num];
                if(num==n)
                    break;
                ans+=(mat[v[num2]][v[num]])/pot[cant];
                cant++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
