//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
using namespace std;

void minLex(string &s, ll mir)
{
    vector<string>v;
    ll i, j;
    string newS="";
    for(j=0; j<sz(s); j++)
    {
        if(s[j]!='x')
        {
            newS+=s[j];
        }
        else
        {
            newS+=s[j];
            j++;
        }
    }
    v.push_back(newS);
    for(i=0; i<mir-1; i++)
    {
        newS="";
        for(j=0; j<sz(v[i]); j++)
        {
            if(v[i][j]!='x')
            {
                newS+=v[i][j];
            }
            else
            {
                newS+=v[i][j];
                j++;
            }
        }
        v.push_back(newS);
    }
    sort(v.begin(),v.end());
    s=v[0];
}
void calcsP(string &s, ll &mir)
{
    string newS="";
    ll n=sz(s), i, camb=0;
    for(i=0; i<n; i++)
    {
        if(i+1<n&&s[i]=='x'&&s[i+1]=='p')
        {
            newS+='$';
            camb=1;
            i++;
        }
        else if(i+1<n&&s[i]=='x'&&s[i+1]=='x')
        {
            newS+='x';
            i++;
        }
        else if(s[i]=='x')
        {
            return;
        }
        else
            newS+=s[i];
    }
    mir+=camb;
    vector<string>v(2);
    v[0]=newS;
    v[1]=s;
    sort(v.begin(),v.end());
    s=v[0];
}
int main()
{
    ll mix, i,res=0,mir=LLONG_MAX,enc=0;
    string s;
    cin >> s;
    vector<ll>cant(sz(s),0);
    for(i=0; i<sz(s); i++)
    {
        if(s[i]=='x')
        {
            if(i==0)
                cant[i]=1;
            else
                cant[i]=cant[i-1]+1;
            if(!(i+1<sz(s)&&s[i+1]=='x'))
            {
                if(cant[i]%2!=0&&(i+1>=sz(s)||s[i+1]!='p'))
                {
                    cout << 0 << '\n';
                    cout << "NOSTRING";
                    return 0;
                }
                else if(cant[i]%2!=0)
                {
                    enc=1;
                }
                mix=cant[i];
                mix=mix/2;
                res=1;
                while(mix>0&&mix%2==0)
                {
                    res++;
                    mix=mix/2;
                }
                mir=min(mir,res);
            }
        }
    }
    if(enc==1)
        mir=LLONG_MAX;
    if(mir==LLONG_MAX)
    {
        mir=1ll;
        calcsP(s,mir);
        cout << 1ll << '\n';
        cout << s;
    }
    else
    {
        minLex(s,mir);
        calcsP(s,mir);
        cout << mir << '\n';
        cout << s;
    }
    return 0;
}
