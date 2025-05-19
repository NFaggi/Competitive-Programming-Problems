#include<bits/stdc++.h>
#define ll long long
#define pb push_back 
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<ll>v;
    vector<vector<ll>>memo(s.size()+1,vector<ll>(4,LLONG_MAX));
    ll i, ma, sig;
    for(i=0; i<int(s.size()); i++)
    {
        if(s[i]=='A')
            v.pb(0);
        else if(s[i]=='C')
            v.pb(1);
        else if(s[i]=='G')
            v.pb(2);
        else
            v.pb(3);
    }
    for(i=int(s.size())-1; i>=0; i--)
    {
        memo[i]=memo[i+1];
        memo[i][v[i]]=i;
    }
    vector<ll>act=memo[0], ans;
    act[v[0]]=0;
    ma=0;
    for(i=0; i<4; i++)
    {
        if(act[i]>ma)
        {
            sig=i;
            ma=act[i];
        }
    }
    while(ma!=LLONG_MAX)
    {
        ans.pb(sig);
        act=memo[ma+1];
        ma=0;
        for(i=0; i<4; i++)
        {
            if(act[i]>ma)
            {
                sig=i;
                ma=act[i];
            }
        }
    }
    ans.pb(sig);
    for(auto k:ans)
    {
        if(k==0)
            cout << 'A';
        else if(k==1)
            cout << 'C';
        else if(k==2)
            cout << 'G';
        else
            cout << 'T';
    }
    return 0;
}
