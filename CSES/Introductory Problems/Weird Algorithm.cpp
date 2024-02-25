#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long>nums;
    while(n!=1)
    {
        nums.push_back(n);
        if(n%2==0)
        {
            n/=2;
        }
        else
        {
            n=n*3+1;
        }
    }
    nums.push_back(1);
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
