#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll tot=0ll, n, k, i, num, j,sig,low;
    cin >> n >> k;
    vector<ll>v(k);
    vector<ll>dp(1<<k,0), res(1<<k,0);
    for(i=0; i<k; i++)
    {
        cin >> v[i];
        tot=(tot+n/v[i]);
    }
    for(i=1ll; i<(1ll<<k); i++)
    {
        if(__builtin_popcountll(i)<=1ll)
            continue;
        sig=0;    
        num=1;
        for(j=0; j<k; j++)
        {

            if((1ll<<j)&i)
            {
                if(n/num<v[j])
                {
                    sig=1;
                    break;
                }
                num=num*v[j];
            }
        }
        if(sig)
            continue;
        if(__builtin_parityll(i))
        {
            tot+=n/num;
        }
        else
        {
            tot-=n/num;
        }
    }
    cout << tot;
    return 0;
}