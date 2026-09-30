#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < (n); i++)
#define forsn(i, s, n) for (int i = (s); i < (n); i++)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = (n) - 1; i >= (s); i--)
 
using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ld = long double;
 
#define all(x) begin(x), end(x)
#define sz(x) int(x.size())
 
#define pb push_back
#define eb emplace_back
 
#define fst first
#define snd second

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string s, int lim=256){
        s.pb(0); int n=sz(s), k=0, a, b;
        vi x(all(s)), y(n), ws(max(n,lim));
        sa=lcp=y,iota(all(sa),0);
        for(int j=0, p=0; p<n; j=max(1,j*2),lim=p){
            p=j, iota(all(y),n-j);
            forn(i,n) if(sa[i]>=j) y[p++] = sa[i]-j;
            fill(all(ws),0);
            forn(i,n) ws[x[i]]++;
            forsn(i,1,lim) ws[i]+=ws[i-1];
            dforn(i,n) sa[--ws[x[y[i]]]] = y[i];
            swap(x,y), p=1, x[sa[0]]=0;
            forsn(i,1,n) a=sa[i-1], b=sa[i], x[b]=(y[a]==y[b]&&y[a+j]==y[b+j]) ? p-1 : p++;
        }
        for (int i=0, j; i<n-1; lcp[x[i++]]=k)
            for(k&&k--,j=sa[x[i]-1]; s[i+k]==s[j+k]; k++);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;

    SuffixArray v(s);
    ll ans=0;
    forsn(i,1,sz(v.sa))
        ans=ans+(sz(s)-v.sa[i]-v.lcp[i]);
    cout << ans << '\n';
    return 0;
}
