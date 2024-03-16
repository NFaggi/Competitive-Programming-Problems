#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<int,int>>p;
 
void Hanoi(int n, int Ori, int Med, int Des)
{
    if(n==1)
    {
        p.push_back({Ori,Des});
    }
    else
    {
        Hanoi(n-1,Ori,Des,Med);
        p.push_back({Ori,Des});
        Hanoi(n-1,Med,Ori,Des);
    }
}
 
int main()
{
    int n;
    scanf("%d",&n);
    Hanoi(n,1,2,3);
    printf("%d ",p.size());
    for(auto k:p)
    {
        printf("%d %d ",k.first,k.second);
    }
    return 0;
}
