#include <iostream>
#include <queue>

using namespace std;

const int MOD=1e6;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int D, K, i, j, aum=1, ult=0;
    cin >> K >> D;
    queue<int>q;
    q.push(1);
    for(i=1; i<=D; i++)
    {
        ult=aum;
        q.push(ult);
        aum=(aum+ult)%MOD;
        if(i-K>=0)
        {
            aum=(aum-q.front())%MOD;
            q.pop();
            if(aum<0)
                aum+=MOD;
        }
    }
    cout << ult;
    return 0;
}
