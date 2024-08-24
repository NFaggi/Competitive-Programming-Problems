//Link: https://codeforces.com/problemset/problem/2004/A
#include <bits/stdc++.h>

using namespace std;
bool can(vector<int>&v, int x)
{
    for(int i=0; i<int(v.size()); i++)
    {
        if(i>0&&abs(v[i-1]-v[i])<abs(x-v[i]))
            return 0;
        if(i<int(v.size())-1&&abs(v[i+1]-v[i])<abs(x-v[i]))
            return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, i;
    bool pos;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>v(n);
        vector<bool>nums(101,0);
        for(i=0; i<n; i++)
        {
            cin >> v[i];
            nums[v[i]]=1;
        }
        sort(v.begin(),v.end());
        pos=0;
        for(i=0; i<=200; i++)
        {
            if(nums[i])
                continue;
            if(can(v,i))
            {
                pos=1;
                break;
            }
        }
        cout << ((pos) ? "YES" : "NO") << '\n';
    }
    return 0;
}
