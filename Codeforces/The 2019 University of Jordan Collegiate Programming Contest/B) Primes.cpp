//Link: https://codeforces.com/gym/102267/problem/B
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e6+1;
const int MAXP = 63e4;
int mindiv[MAXN],primes[MAXP],cant=0;

void criba()
{
    int i, j;
    for(i=2; i<MAXN; i++)
    {
        if(mindiv[i]==0)
        {
            mindiv[i]=i;
            primes[cant]=i;
            cant++;
        }
        for(j=0; j<cant && primes[j]<=mindiv[i] && i*primes[j]<MAXN; j++)
            mindiv[i*primes[j]]=primes[j];
    }
}

bool comp(int x)
{
    for(int i=2; i<=sqrt(x); i++)
        if(x%i==0)
            return 0;
    return 1;        
}

int main()
{
    int n, i;
    cin >> n;
    criba();
    for(i=0; i<cant&& primes[i]<n; i++)
    {
        if(n-primes[i]<MAXN)
        {
            if(mindiv[n-primes[i]]==n-primes[i])
            {
                cout << primes[i] << ' ' << n-primes[i];
                return 0;
            }
        }
        else if(comp(n-primes[i]))
        {
            cout << primes[i] << ' ' << n-primes[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}