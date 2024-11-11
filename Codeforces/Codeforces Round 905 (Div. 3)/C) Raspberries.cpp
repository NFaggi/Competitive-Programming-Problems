//Link: https://codeforces.com/problemset/problem/1883/C
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, x, mi,div,i,j;
    vector<vector<int>>v(6);
    v[2]= {2,4,6,8,10};
    v[3]= {3,6,9,12};
    v[4]= {4,8,12};
    v[5]= {5,10};
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        mi=INT_MAX;
        if(k!=4)
        {
            for(i=0; i<n; i++)
            {
                cin >> x;
                for(j=0; j<int(v[k].size()); j++)
                {
                    if(x<=v[k][j])
                    {
                        div=v[k][j];
                        break;
                    }
                }
                mi=min(mi,div-x);
            }
        }
        else
        {
            vector<int>v3;
            for(i=0; i<n; i++)
            {
                cin >> x;
                for(j=0; j<int(v[k].size()); j++)
                {
                    if(x<=v[k][j])
                    {
                        div=v[k][j];
                        break;
                    }
                }

                mi=min(mi,div-x);
                for(j=0; j<int(v[2].size()); j++)
                {
                    if(x<=v[2][j])
                    {
                        div=v[2][j];
                        break;
                    }
                }
                v3.push_back(div-x);
            }
            sort(v3.begin(),v3.end());
            if(int(v3.size())>1)
            {
                mi=min(mi,v3[0]+v3[1]);
            }
        }
        cout << mi << '\n';
    }
    return 0;
}