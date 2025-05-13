#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define pb push_back 
using namespace std;

int main()
{
    ll n, ma=0, x, i;
    cin >> n;
    vector<ll>v(n);
    for(i=0; i<n; i++)
        cin >> v[i];
    vector<ll>area(n,0);
    stack<ll>s,s2;
    for(i=0; i<n; i++)
    {
        x=i;
        while(s.size()&&v[s.top()]>=v[i])
        {
            x=s.top();
            s.pop();
        }
        if(s.size()==0)
            x=-1;
        else
            x=s.top();    
        area[i]=v[i]*(i-x);
        s.push(i);
    }    
    swap(s,s2);
    for(i=n-1; i>=0; i--)
    {
        x=i;
        while(s.size()&&v[s.top()]>=v[i])
        {
            x=s.top();
            s.pop();
        }
        if(s.size()==0)
            x=n;
        else
            x=s.top();    
        area[i]+=v[i]*((x-i)-1);
        s.push(i);
    }    
    for(auto k:area)
        ma=max(ma,k);
    cout << ma;    
    return 0;
}
