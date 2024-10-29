//Link: https://codeforces.com/problemset/problem/230/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    bool vive=true;
    long long n,s, x, y;
    cin >> s >> n;
    priority_queue<pair<long long, long long>>pq;

    while(n--)
    {
        cin >> x >> y;
        pq.push({-x,y});
    }
    while(pq.size()&&vive)
    {
        long long niv = -pq.top().first;
        if(niv<s)
        {
            s+=pq.top().second;
        }
        else
        {
            vive=false;
            break;
        }
        pq.pop();
    }
    if(vive)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
