#include <iostream>
 
using namespace std;
 
int main()
{
    long long n, num=2;
    cin >> n;
    if(n>=2&&n<=3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    if(n==1)
    {
        cout << "1";
        return 0;
    }
    while(num<=n)
    {
        cout << num << " ";
        num+=2;
    }
    num = 1;
    while(num<=n)
    {
        cout << num << " ";
        num+=2;
    }
    return 0;
}
