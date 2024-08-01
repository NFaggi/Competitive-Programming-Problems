#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    int i, j,act;
    cin >> s >> t;
    vector<vector<long long>>dp(int(s.size())+1,vector<long long>(int(t.size())+1,0));
    for(i=1; i<=int(s.size()); i++)
    {
        for(j=1; j<=int(t.size()); j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1ll);
            }
        }
    }
    string res="";
    i=s.size();
    j=t.size();
    act=dp[i][j];
    while(act>0)
    {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else
        {
            res+=t[j-1];
            j--;
            i--;
            act=dp[i][j];
        }    
        
    }
    reverse(res.begin(),res.end());
    cout << res;
    return 0;
}