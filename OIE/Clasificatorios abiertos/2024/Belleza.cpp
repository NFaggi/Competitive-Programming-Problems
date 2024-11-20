//Link: https://codeforces.com/gym/105003/problem/B
//Score: 100/100
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t, n, k, i, a, b,bell,tot,j;
    cin >> t;
    vector<ll>v;
    while(t--)
    {
        bell=0;
        cin >> n >> k;
        v.resize(n);
        vector<ll>P,N;
        for(i=0; i<n; i++)
        {
            cin >> v[i];
            if(i%2!=0)
            {
                N.push_back(v[i]);
            }
            else
            {
                P.push_back(v[i]);
            }
        }
        sort(N.begin(),N.end());
        sort(P.begin(),P.end());

        if(n==2)
        {
            if(k%2==1)
            {
                swap(P[0],N[0]);
            }
        }
        else
        {
            i=0;
            j=int(N.size())-1;
            while(k>0&&j>=0&&i<int(P.size()))
            {
                if(P[i]>N[j]) break;
                swap(P[i],N[j]);
                j--;
                i++;
                k--;
            }
        }
        bell=0;
        for(i=0; i<int(P.size()); i++)
        {
            bell+=P[i];
        }
        for(i=0; i<int(N.size()); i++)
        {
            bell-=N[i];
        }
        cout << bell << '\n';

    }
    return 0;
}
