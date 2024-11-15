#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n, i, j=0,tam=0,num,cant=0,k, cont=0;
    cin >> n >> k;
    vector<long long>memo(n+1,0),v(n);
    set<long long>s;
    map<long long,long long>m;
    for(i=1; i<=n; i++)
    {
        memo[i]=memo[i-1]+i;
        cin >> v[i-1];
    }
    for(i=0; i<n; i++)
    {
        num=v[i];
        m[num]++;
        s.insert(num);
        if(int(s.size())>k)
        {
            cant+=memo[tam];
            cant-=memo[cont];
            cont=tam;
        }    
        tam++;
        while(int(s.size())>k)
        {
            tam--;
            if(cont>0)
                cont--;
            num=v[j];
            m[num]--;
            if(m[num]==0)
            {
                s.erase(num);
            }
            j++;
        }
 
    }
    while(int(s.size())>k)
    {
        tam--;
        if(cont>0)
            cont--;
        num=v[j];
        m[num]--;
        if(m[num]==0)
        {
            s.erase(num);
        }
        j++;
    }
    cant+=memo[tam];
    cant-=memo[cont];
    cout << cant;
    return 0;
}
