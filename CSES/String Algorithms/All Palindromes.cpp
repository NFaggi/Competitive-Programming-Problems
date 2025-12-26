#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;
const int MAXN=2e6+2;
string s;
ll len[MAXN], n, ma[MAXN];
 
void calcODD()
{
    ll l=-1,r=-1, i, L, R;
    for(i=0; i<n; i++)
    {
        if(r<i)
        {
            l=i;
            r=i;
            while(l>0&&r<n-1&&s[l-1]==s[r+1])
            {
                l--;
                r++;
            }
            len[i]=r-i;
        }
        else
        {
            len[i]=min(r-i,len[l+(r-i)]);
            L=(i-(len[i]+1));
            R=(i+(len[i]+1));
            while(L>=0&&R<n&&s[L]==s[R])
            {
                len[i]++;
                L--;
                R++;
            }
            if(len[i]+i>r)
            {
                l=i-len[i];
                r=i+len[i];
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i;
    string a="#";
    cin >> s;
    for(i=0; i<sz(s); i++)
    {
        a.pb(s[i]);
        a.pb('#');
    }
    swap(a,s);
    n=sz(s);
    calcODD();
    for(i=0; i<n; i++)
        ma[len[i]+i]=max(ma[len[i]+i],len[i]);
    for(i=n-1; i>=0; i--)
        ma[i]=max(ma[i],ma[i+1]-1);
    for(i=0; i<n; i++)
        if(s[i]!='#')
            cout << ma[i]+1 << ' ';
    return 0;
}
