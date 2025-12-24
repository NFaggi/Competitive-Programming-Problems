#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define pb push_back 
#define sz(x) int(x.size())
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    vector<ll>lps(sz(s),0);
    ll len=0, i=1;
    while(i<sz(s))
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len>0)
                len=lps[len-1];
            else
                i++;    
        }
    }
    vector<ll>ans;
    
    while(len)
    {
        ans.pb(sz(s)-len);
        len=lps[len-1];
    }
    ans.pb(sz(s));
    for(auto k:ans)
        cout << k << ' ';
    return 0;
}
