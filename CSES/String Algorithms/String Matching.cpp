#include<bits/stdc++.h>
using namespace std;
int lps[int(1e6)];
void cLPS(string & x)
{
    int i=1, n=x.size(), len=0;
    while(i<n)
    {
        if(x[i]==x[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                i++;
            }
        }
    }
}
int ma(string & a, string & b)
{
    int i=0, j=0, n=a.size(), m=b.size(), cant=0;
    while(i<n)
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            j=lps[j-1];
            cant++;
        }
        else if(i<n&&a[i]!=b[j])
        {
            if(j>0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return cant;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cLPS(b);
    cout << ma(a,b);
    return 0;
}
