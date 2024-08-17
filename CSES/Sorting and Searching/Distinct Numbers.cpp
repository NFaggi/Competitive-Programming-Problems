#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    map<int,bool>M;
    int n, num;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        M[num]=true;
    }
    cout << M.size() << endl;
    return 0;
}