//Link: https://codeforces.com/contest/847/problem/E
#include<bits/stdc++.h>
using namespace std;
vector<int>pac,ast;
 
bool can(int piv)
{
    int i=0,j=0,acum=INT_MAX,dis,maj,aj,ai,ant;
    bool ult=1;
    while(i<int(pac.size())&&(j<ast.size()||!ult))
    {
        if(j<int(ast.size())&&((i<int(pac.size())&&ast[j]<pac[i])||i>=int(pac.size())))
        {
            acum=min(acum,ast[j]);
            j++;
            ult=0;
        }
        else if(i<int(pac.size()))
        {
            
            if(acum==INT_MAX)
                acum=pac[i];
            dis=abs(pac[i]-acum);
            ult=1;
            if(dis>piv)
                return 0;
            maj=0;
            aj=j;
            ant=pac[i];
            bool cam=0;
            for(ai=aj; ai<int(ast.size()); ai++)
            {
                if(dis+abs(ast[ai]-ant)*2<=piv) {
                    dis+=abs(ast[ai]-ant)*2;
                    maj=ai;
                    ant=ast[ai];
                    cam=1;
                }
                else
                    break;
            }
            ant=pac[i];
            dis=abs(pac[i]-acum)*2;
            for(ai=aj; ai<int(ast.size()); ai++)
            {
                if(dis+abs(ast[ai]-ant)<=piv)
                {
                    dis+=abs(ast[ai]-ant);
                    maj=max(maj,ai);
                    ant=ast[ai];
                    cam=1;
                }
                else
                    break;
            }
            if(cam)
            j=max(j,maj+1);
            i++;
            acum=INT_MAX;
            
        }
    }
    if(!ult||j<int(ast.size()))
        return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, i, mi=1, ma=3e5,piv, pos=-1;
    string s;
    cin >> n >> s;
    for(i=0; i<int(s.size()); i++)
    {
        if(s[i]=='*')
            ast.push_back(i+1);
        else if(s[i]=='P')
            pac.push_back(i+1);
    }
    
    while(mi<=ma)
    {
        piv=(mi+ma)/2;
        if(can(piv))
        {
            ma=piv-1;
            pos=piv;
        }
        else
        {
            mi=piv+1;
        }
    }
    cout << pos;
    return 0;
}
