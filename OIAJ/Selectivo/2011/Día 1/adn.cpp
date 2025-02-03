//Score: 100/100
//Link: https://juez.oia.unsam.edu.ar/task/1
#include <bits/stdc++.h>
#define sz(x) int(x.size())
using namespace std;
int m, x;
bool comp1(int num)
{
    return num<=m;
}
bool comp2(int num)
{
    return num<=x;
}
bool comp3(pair<int,int>p)
{
    return (comp1(p.first+1)&&comp2(p.second+1));
}
int main()
{
    ifstream cin ("adn.in");
    ofstream cout ("adn.out");
    int n, i, j, mi;
    string a, b;
    cin >> n >> m >> x;
    cin >> a >> b;
    vector<vector<pair<int,int>>>dp(n+1);
        
    for(i=0; i<=m&&i<=x; i++)
    {
        dp[0].push_back({i,i});
    }
    for(i=1; i<=n&&i<=x; i++)
    {
        dp[i].push_back({0,i});
    }
    for(i=1; i<=n; i++)
    {
        j=0;
        while(j<sz(dp[i-1])||sz(dp[i])&&comp3(dp[i][sz(dp[i])-1]))
        {
            if(sz(dp[i])&&dp[i-1][j].first==dp[i][sz(dp[i])-1].first)
            {
                dp[i][sz(dp[i])-1].second=min(dp[i][sz(dp[i])-1].second,dp[i-1][j].second+1);
                if(comp1(dp[i-1][j].first+1)&&a[i-1]==b[dp[i-1][j].first])
                {
                    dp[i].push_back({dp[i-1][j].first+1,dp[i-1][j].second});
                }
                else if(comp3({dp[i-1][j].first,min(dp[i-1][j].second,dp[i][sz(dp[i])-1].second)}))
                {
                    dp[i].push_back({dp[i-1][j].first+1,min(dp[i-1][j].second+1,dp[i][sz(dp[i])-1].second+1)});
                }
                j++;
            }
            else if(sz(dp[i])>0&&j<sz(dp[i-1])&&comp1(dp[i][sz(dp[i])-1].first+1))
            {
                mi=dp[i][sz(dp[i])-1].second+1;
                if(dp[i-1][j].first==dp[i][sz(dp[i])-1].first+1)
                    mi=min(mi,dp[i-1][j].second+1);
                if(comp2(mi))
                    dp[i].push_back({dp[i][sz(dp[i])-1].first+1,mi});
                else
                {
                    if(comp2(dp[i-1][j].second+1))
                        dp[i].push_back({dp[i-1][j].first,dp[i-1][j].second+1});
                    else if(comp1(dp[i-1][j].first+1)&&a[i-1]==b[dp[i-1][j].first])
                    {
                        dp[i].push_back({dp[i-1][j].first+1,dp[i-1][j].second});
                        j++;
                    }
                    else
                        j++;
                }
            }
            else if(sz(dp[i])==0)
            {
                if(comp2(dp[i-1][j].second+1))
                    dp[i].push_back({dp[i-1][j].first,dp[i-1][j].second+1});
                else if(comp1(dp[i-1][j].first+1)&&a[i-1]==b[dp[i-1][j].first])
                {
                    dp[i].push_back({dp[i-1][j].first+1,dp[i-1][j].second});
                    j++;
                }
                else
                    j++;
            }
            else if(comp2(dp[i][sz(dp[i])-1].second+1)==0&&j<sz(dp[i-1]))
            {
                if(comp2(dp[i-1][j].second+1))
                    dp[i].push_back({dp[i-1][j].first,dp[i-1][j].second+1});
                else if(comp1(dp[i-1][j].first+1)&&a[i-1]==b[dp[i-1][j].first])
                {
                    dp[i].push_back({dp[i-1][j].first+1,dp[i-1][j].second});
                    j++;
                }
                else
                    j++;
            }
            else if(j>=sz(dp[i-1])&&sz(dp[i])&&comp3(dp[i][sz(dp[i])-1]))
            {
                dp[i].push_back({dp[i][sz(dp[i])-1].first+1,dp[i][sz(dp[i])-1].second+1});
            }
            else
                j++;
        }
    }
    if(sz(dp[n])==0||dp[n][sz(dp[n])-1].first!=m)
    {
        cout << "Muy distintas.";
    }
    else
    {
        cout << dp[n][sz(dp[n])-1].second;
    }
    return 0;
}
