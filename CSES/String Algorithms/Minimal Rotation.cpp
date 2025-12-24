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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll i=0, j=1, k=0, ans=0, n;
    string s;
    cin >> s;
    n=sz(s);
    s=s+s;
    while(j<n&&i<n)
    {
        if(k<n&&s[i+k]==s[j+k])
            k++;
        else
        {
            if(s[i+k]>s[j+k])
                i+=k+1;
            else
                j+=k+1;
            k=0;
        }
        if(i==j)
            j++;
    }
    ans=min(i,j);
    for(i=0; i<n; i++)
        cout << s[ans+i];
    return 0;
}
