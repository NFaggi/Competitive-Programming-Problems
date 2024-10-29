#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int i, n=int(s.size()), j, k;
    vector<int>v(n,0);
    
    for(i=1; i<n; i++)
    {
        j=v[i-1];
        while(j>0&&s[i]!=s[j])
        {
            j=v[j-1];
        }
        if(s[i]==s[j])
        {
            v[i]=j+1;
        }
    }
    k=v[n-1];
    vector<int>v2;
    while(k!=0){
        v2.push_back(k);
        k=v[k-1];
    }
    for(i=int(v2.size())-1; i>=0; i--)
    {
        cout << v2[i] << ' ';
    }
    return 0;
}