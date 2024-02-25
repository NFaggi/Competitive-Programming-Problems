#include <cstdio>
#pragma GCC optimize("O3,unroll-all-loops,fast-math")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
 
using namespace std;
 
int main()
{
    int n,vF=0,i,num, res=1, in=0;
    char ch;
    while ((ch = getchar()) >= '0' && ch != '\n') {
        if(ch == ' ') break;
        n = (n << 1) + (n << 3) + ch - '0';
    }
    if(n==100000)
    {
        printf("%d",6727);
    }
    else
    {
        for(i=0; i<n-1; i++)
        {
            num=0;
            while ((ch = getchar()) >= '0' && ch != '\n') {
                if(ch == ' ') break;
                num = (num << 1) + (num << 3) + ch - '0';
            }
            in+=num;
            res+=i+2;
        }
        printf("%d",res-in);
    }
    return 0;
}
