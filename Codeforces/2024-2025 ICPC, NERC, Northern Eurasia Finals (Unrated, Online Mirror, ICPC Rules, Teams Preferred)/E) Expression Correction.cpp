//Link:https://codeforces.com/contest/2052/problem/E
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool valid(string &s)
{
    int i,n=int(s.size());
    if(!(s[0]>='0'&&s[0]<='9')||!(s[n-1]>='0'&&s[n-1]<='9'))
        return 0;
    vector<string>nums;
    string num="";
    num+=s[0];
    for(i=1; i<n; i++)
    {
        if(!(s[i]>='0'&&s[i]<='9')&&!(s[i-1]>='0'&&s[i-1]<='9'))
            return 0;
        if(s[i]>='0'&&s[i]<='9')
        {
            num+=s[i];
        }
        else
        {
            nums.push_back(num);
            num="";
        }
    }
    nums.push_back(num);
    for(auto k:nums)
    {
        if(int(k.size())>1&&k[0]=='0')
            return 0;
        if(!k.size()||int(k.size())>10)
            return 0;
    }
    return 1;
}
bool comp(string &s)
{
    int i,n=int(s.size()),sign=1;
    ll a=0,tot=0;
    vector<ll>v;
    for(i=0; i<n; i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a=a*10ll+(s[i]-'0');
        else if(sign==2)
            a=a*-1ll;
        if(s[i]=='+')
        {
            sign=1;
            tot=tot+a;
            a=0ll;
        }
        else if(s[i]=='-')
        {
            sign=2;
            tot=tot+a;
            a=0ll;
        }
        else if(s[i]=='=')
        {
            sign=1;
            tot=tot+a;
            v.push_back(tot);
            a=0ll;
            tot=0ll;
        }
    }
    if(sign==2)
        a=a*-1;
    tot=tot+a;
    v.push_back(tot);
    tot=v[0];
    for(ll k:v)
    {
        if(tot!=k)
            return 0;
    }
    return 1;
}
int main()
{
    int i, j, n;
    string s, ori;
    cin >> s;
    ori=s;
    n=int(s.size());
    if(valid(s)&&comp(s))
    {
        cout << "Correct";
        return 0;
    }
    for(i=0; i<n; i++)
    {
        if(!(s[i]>='0'&&s[i]<='9'))
            continue;
        for(j=i+1; j<n; j++)
        {
            swap(s[j],s[j-1]);
            if(valid(s)&&comp(s))
            {
                cout << s;
                return 0;
            }
        }
        s=ori;
        for(j=i-1; j>=0; j--)
        {
            swap(s[j],s[j+1]);
            if(valid(s)&&comp(s))
            {
                cout << s;
                return 0;
            }
        }
        s=ori;
    }
    cout << "Impossible";
    return 0;
}
